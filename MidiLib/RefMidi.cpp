#include "stdafx.h"
#include <ppl.h>
#include <ppltasks.h>
#include <intrin.h>
#include "../Megayuchi_UTIL/WriteDebugString.h"
#include <unordered_map>

#undef SendMessage
#include "RefMidi.h"

using namespace std;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Devices::Enumeration;
using namespace Windows::Devices::Midi;
using namespace Concurrency;

RefMidi::RefMidi(ON_MIDI_INPUT_CALLBACK	pMidiInputCallback, void* pData)
{
	InitializeSRWLock(&m_Lock_MidiInDeviceCollection);
	InitializeSRWLock(&m_Lock_MidiOutDeviceCollection);

	m_MidiInSelectorString = MidiInPort::GetDeviceSelector();
	m_MidiOutSelectorString = MidiOutPort::GetDeviceSelector();

	const WCHAR* wchMidiInStr = m_MidiInSelectorString->Data();
	const WCHAR* wchMidiOutStr = m_MidiOutSelectorString->Data();

	m_pMidiOutDeviceList = new unordered_map < wstring, MIDI_OUT_DEVICE^>;
	m_pMidiInDeviceList = new unordered_map < wstring, MIDI_IN_DEVICE^>;
	m_pOnMidiInputCallback = pMidiInputCallback;
	m_pCallbackData = pData;

}
void RefMidi::RequestUpdateMidiInDeviceList()
{
	LONG lOldCount = _InterlockedCompareExchange(&m_lMidiInDeviceListEnumCompleted, 0, 1);
	if (!lOldCount)
		return;

	m_MidiInDeviceWatcher = DeviceInformation::CreateWatcher(m_MidiInSelectorString);
	m_MidiInDeviceWatcher->Added += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher ^, Windows::Devices::Enumeration::DeviceInformation ^>(this, &RefMidi::OnAddedMidiInDevice);
	m_MidiInDeviceWatcher->Removed += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher ^, Windows::Devices::Enumeration::DeviceInformationUpdate ^>(this, &RefMidi::OnRemovedMidiInDevice);
	m_MidiInDeviceWatcher->Updated += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher ^, Windows::Devices::Enumeration::DeviceInformationUpdate ^>(this, &RefMidi::OnUpdatedMidiInDevice);
	m_MidiInDeviceWatcher->EnumerationCompleted += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher ^, Platform::Object ^>(this, &RefMidi::OnEnumerationCompletedMidiInDevice);
	m_MidiInDeviceWatcher->Start();
}
void RefMidi::RequestUpdateMidiOutDeviceList()
{
	LONG lOldCount = _InterlockedCompareExchange(&m_lMidiOutDeviceListEnumCompleted, 0, 1);
	if (!lOldCount)
		return;

	m_MidiOutDeviceWatcher = DeviceInformation::CreateWatcher(m_MidiOutSelectorString);
	m_MidiOutDeviceWatcher->Added += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher ^, Windows::Devices::Enumeration::DeviceInformation ^>(this, &RefMidi::OnAddedMidiOutDevice);
	m_MidiOutDeviceWatcher->Removed += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher ^, Windows::Devices::Enumeration::DeviceInformationUpdate ^>(this, &RefMidi::OnRemovedMidiOutDevice);
	m_MidiOutDeviceWatcher->Updated += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher ^, Windows::Devices::Enumeration::DeviceInformationUpdate ^>(this, &RefMidi::OnUpdatedMidiOutDevice);
	m_MidiOutDeviceWatcher->EnumerationCompleted += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher ^, Platform::Object ^>(this, &RefMidi::OnEnumerationCompletedMidiOutDevice);
	m_MidiOutDeviceWatcher->Start();
}

void RefMidi::UpdateMidiInDeviceList()
{
	/*
	DeviceInformationCollection^ DeviceInfoCollection = nullptr;
	std::unordered_map<std::wstring, IMidiInPort^>* pTempDeviceCollection = new std::unordered_map<std::wstring, IMidiInPort^>;

	create_task(DeviceInformation::FindAllAsync(m_MidiInSelectorString)).then([this, pTempDeviceCollection](DeviceInformationCollection^ deviceInfoCollection)
	{
		UINT DeviceCount = deviceInfoCollection->Size;
		for (UINT i = 0; i < DeviceCount; i++)
		{
			DeviceInformation^ Info = deviceInfoCollection->GetAt(i);
			Info->Id;
			Info->Name;
			IMidiInPort^ Port = GetMidiInPort(Info->Id);
			std::wstring wstrName(Info->Name->Data());
			pTempDeviceCollection->insert(make_pair(wstrName, Port));
		}
		AcquireSRWLockExclusive(&m_Lock_MidiInDeviceCollection);

		if (m_pMidiInDeviceCollection)
		{
			delete m_pMidiInDeviceCollection;
			m_pMidiInDeviceCollection = nullptr;
		}
		m_pMidiInDeviceCollection = pTempDeviceCollection;

		_InterlockedOr(&m_lMidiInDeviceListUpdated, 1);
		ReleaseSRWLockExclusive(&m_Lock_MidiInDeviceCollection);
	});
	*/
}

void RefMidi::UpdateMidiOutDeviceList()
{
	/*
	DeviceInformationCollection^ DeviceInfoCollection = nullptr;
	std::unordered_map<std::wstring, IMidiOutPort^>* pTempDeviceCollection = new std::unordered_map<std::wstring, IMidiOutPort^>;

	create_task(DeviceInformation::FindAllAsync(m_MidiOutSelectorString)).then([this, pTempDeviceCollection](DeviceInformationCollection^ deviceInfoCollection)
	{
		UINT DeviceCount = deviceInfoCollection->Size;
		for (UINT i = 0; i < DeviceCount; i++)
		{
			DeviceInformation^ Info = deviceInfoCollection->GetAt(i);
			Info->Id;
			Info->Name;
			IMidiOutPort^ Port = GetMidiOutPort(Info->Id);
			std::wstring wstrName(Info->Name->Data());
			pTempDeviceCollection->insert(make_pair(wstrName, Port));
		}
		AcquireSRWLockExclusive(&m_Lock_MidiOutDeviceCollection);

		if (m_pMidiOutDeviceCollection)
		{
			delete m_pMidiOutDeviceCollection;
			m_pMidiOutDeviceCollection = nullptr;
		}
		m_pMidiOutDeviceCollection = pTempDeviceCollection;

		_InterlockedOr(&m_lMidiOutDeviceListUpdated, 1);
		ReleaseSRWLockExclusive(&m_Lock_MidiOutDeviceCollection);
	});
	*/
}
IMidiOutPort^ RefMidi::GetMidiOutPort(Platform::String^ Id)
{
	IMidiOutPort^ Port = nullptr;
	auto task_get = create_task(MidiOutPort::FromIdAsync(Id));
	try
	{
		Port = task_get.get();
	}
	catch (Platform::Exception ^ e)
	{
		const WCHAR* wchErrMsg = e->Message->Data();
		Platform::String^ err = e->ToString();
		WriteDebugStringW(DEBUG_OUTPUT_TYPE_DEBUG_CONSOLE, L"[MidiLib] MidiOutPort::FromIdAsync - Exception , %s\n", wchErrMsg);
		return nullptr;
	}
	return Port;
}
IMidiInPort^ RefMidi::GetMidiInPort(Platform::String^ Id)
{
	IMidiInPort^ Port = nullptr;
	auto task_get = create_task(MidiInPort::FromIdAsync(Id));
	try
	{
		Port = task_get.get();
	}
	catch (Platform::Exception ^ e)
	{
		const WCHAR* wchErrMsg = e->Message->Data();
		Platform::String^ err = e->ToString();
		WriteDebugStringW(DEBUG_OUTPUT_TYPE_DEBUG_CONSOLE, L"[MidiLib] MidiInPort::FromIdAsync - Exception , %s\n", wchErrMsg);
		return nullptr;
	}
	return Port;
}

IMidiInPort^ RefMidi::GetSelectedMidiInPort()
{
	IMidiInPort^ Port = nullptr;

	if (!m_SelectedMidiInDevice)
		goto lb_return;

	Port = m_SelectedMidiInDevice->GetPort();
lb_return:
	return Port;
}
IMidiOutPort^ RefMidi::GetSelectedMidiOutPort()
{
	IMidiOutPort^ Port = nullptr;

	if (!m_SelectedMidiOutDevice)
		goto lb_return;

	//		if (!wcscmp(wchDeviceName, L"Microsoft GS Wavetable Synth"))
	//		{
	Port = m_SelectedMidiOutDevice->GetPort();
lb_return:
	return Port;
}
BOOL RefMidi::SetVolume(unsigned char channel, unsigned char Volume)
{
	if (!m_SelectedMidiOutDevice)
		return FALSE;

	IMidiOutPort^ pPort = m_SelectedMidiOutDevice->GetPort();

	Windows::Devices::Midi::MidiControlChangeMessage^ MidiControl = ref new MidiControlChangeMessage(channel, 7, Volume);
	pPort->SendMessage(MidiControl);
	return TRUE;
}
BOOL RefMidi::SetSustainPedal(unsigned char channel, unsigned char Value)
{
	if (!m_SelectedMidiOutDevice)
		return FALSE;

	IMidiOutPort^ pPort = m_SelectedMidiOutDevice->GetPort();

	Windows::Devices::Midi::MidiControlChangeMessage^ MidiControl = ref new MidiControlChangeMessage(channel, 64, Value);
	pPort->SendMessage(MidiControl);
	return TRUE;
}
BOOL RefMidi::NoteOn(unsigned char channel, unsigned char note, unsigned char Velocity)
{
	BOOL	bResult = FALSE;

	if (!m_SelectedMidiOutDevice)
		return FALSE;

	IMidiOutPort^ pPort = m_SelectedMidiOutDevice->GetPort();

	MidiNoteOnMessage^ MidiNote = ref new MidiNoteOnMessage(channel, note, Velocity);
	pPort->SendMessage(MidiNote);
	//this.currentMidiOutputDevice.SendMessage(midiMessageToSend);
	//midiMessageToSend = new MidiNoteOnMessage(Convert.ToByte(this.parameter1.SelectedValue), Convert.ToByte(this.parameter2.SelectedValue), Convert.ToByte(this.parameter3.SelectedValue));
	return TRUE;
}
BOOL RefMidi::NoteOff(unsigned char channel, unsigned char note, unsigned char Velocity)
{
	BOOL	bResult = FALSE;


	if (!m_SelectedMidiOutDevice)
		return FALSE;

	IMidiOutPort^ pPort = m_SelectedMidiOutDevice->GetPort();

	MidiNoteOffMessage^ MidiNote = ref new MidiNoteOffMessage(channel, note, Velocity);
	pPort->SendMessage(MidiNote);
	//this.currentMidiOutputDevice.SendMessage(midiMessageToSend);

	//midiMessageToSend = new MidiNoteOnMessage(Convert.ToByte(this.parameter1.SelectedValue), Convert.ToByte(this.parameter2.SelectedValue), Convert.ToByte(this.parameter3.SelectedValue));
	return TRUE;
}
void RefMidi::OnAddedMidiOutDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformation^ Info)
{
	wstring wstrDeviceName(Info->Name->Data());
	wstring wstrDeviceID(Info->Id->Data());

	IMidiOutPort^ Port = GetMidiOutPort(Info->Id);
	if (Port)
	{
		std::wstring wstrDeviceId(Info->Id->Data());
		MIDI_OUT_DEVICE^ Device = ref new MIDI_OUT_DEVICE(Port, Info->Name, Info->Id);

		AcquireSRWLockExclusive(&m_Lock_MidiOutDeviceCollection);

		auto it = m_pMidiOutDeviceList->find(wstrDeviceId);
		if (it == m_pMidiOutDeviceList->end())
		{
			WriteDebugStringW(DEBUG_OUTPUT_TYPE_DEBUG_CONSOLE, L"[MidiLib] OnAddedMidiOutDevice - %s , %s\n", wstrDeviceName.data(), wstrDeviceID.data());
			m_pMidiOutDeviceList->insert(make_pair(wstrDeviceId, Device));
		}
		ReleaseSRWLockExclusive(&m_Lock_MidiOutDeviceCollection);
	}
}

void RefMidi::OnRemovedMidiOutDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformationUpdate^ Info)
{
	wstring wstrDeviceId(Info->Id->Data());

	IMidiOutPort^ Port = GetMidiOutPort(Info->Id);

	AcquireSRWLockExclusive(&m_Lock_MidiOutDeviceCollection);

	auto it = m_pMidiOutDeviceList->find(wstrDeviceId);
	if (it != m_pMidiOutDeviceList->end())
	{
		MIDI_OUT_DEVICE^	Device = it->second;
		wstring wstrDeviceName(Device->GetName()->Data());

		WriteDebugStringW(DEBUG_OUTPUT_TYPE_DEBUG_CONSOLE, L"[MidiLib] OnRemovedMidiOutDevice - %s , %s\n", wstrDeviceName.data(), wstrDeviceId.data());
		m_pMidiOutDeviceList->erase(it);

	}
	ReleaseSRWLockExclusive(&m_Lock_MidiOutDeviceCollection);
}
void RefMidi::OnUpdatedMidiOutDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformationUpdate^ InfoUpdated)
{

	wstring wstrDeviceId(InfoUpdated->Id->Data());
	IMidiOutPort^ Port = GetMidiOutPort(InfoUpdated->Id);

	AcquireSRWLockExclusive(&m_Lock_MidiOutDeviceCollection);

	auto it = m_pMidiOutDeviceList->find(wstrDeviceId);
	if (it != m_pMidiOutDeviceList->end())
	{
		MIDI_OUT_DEVICE^ Device = it->second;
		wstring wstrDeviceName(Device->GetName()->Data());

		WriteDebugStringW(DEBUG_OUTPUT_TYPE_DEBUG_CONSOLE, L"[MidiLib] OnUpdatedMidiOutDevice - %s , %s\n", wstrDeviceName.data(), wstrDeviceId.data());
		Device->ReplacePort(Port);
	}
	ReleaseSRWLockExclusive(&m_Lock_MidiOutDeviceCollection);
}
void RefMidi::OnEnumerationCompletedMidiOutDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Platform::Object^ obj)
{
	//m_MidiOutDeviceWatcher->Stop();
	//m_MidiOutDeviceWatcher = nullptr;
	_InterlockedOr(&m_lMidiOutDeviceListEnumCompleted, 1);
}

void RefMidi::OnMessageReceived(Windows::Devices::Midi::MidiInPort ^ Port, Windows::Devices::Midi::MidiMessageReceivedEventArgs^ args)
{
	IMidiMessage^ receivedMidiMessage = args->Message;
	/*
	MIDI CC List ? Most Common Parameters
1 = Modulation wheel
2 = Breath Control
7 = Volume
10 = Pan
11 = Expression
64 = Sustain Pedal (on/off)
65 = Portamento (on/off)
71 = Resonance (filter)
74 = Frequency Cutoff (filter)
*/
	receivedMidiMessage->RawData;
	switch (receivedMidiMessage->Type)
	{
		case MidiMessageType::NoteOn:
			{
				MidiNoteOnMessage^ NoteOnMessage = static_cast<MidiNoteOnMessage^>(receivedMidiMessage);
				unsigned char Note = NoteOnMessage->Note;
				unsigned Vel = NoteOnMessage->Velocity;
				unsigned char Channel = NoteOnMessage->Channel;
				m_pOnMidiInputCallback(MIDI_SIGNAL_TYPE_NOTE, TRUE, Channel, Note, Vel, m_pCallbackData);
			}
			break;
		case MidiMessageType::NoteOff:
			{
				MidiNoteOffMessage^ NoteOffMessage = static_cast<MidiNoteOffMessage^>(receivedMidiMessage);
				unsigned char Note = NoteOffMessage->Note;
				unsigned Vel = NoteOffMessage->Velocity;
				unsigned char Channel = NoteOffMessage->Channel;
				m_pOnMidiInputCallback(MIDI_SIGNAL_TYPE_NOTE, FALSE, Channel, Note, Vel, m_pCallbackData);
			}
			break;
		case MidiMessageType::ControlChange:
			{
				// 카시오 디지털 피아노에서 건반 눌렀을때 controller = 88, value 34
				// controller = 64, value = 128
				MidiControlChangeMessage^ CCMessage = static_cast<MidiControlChangeMessage^>(receivedMidiMessage);
				unsigned char Channel = CCMessage->Channel;
				unsigned char Controller = CCMessage->Controller;
				unsigned char Value = CCMessage->ControlValue;
				m_pOnMidiInputCallback(MIDI_SIGNAL_TYPE_CONTROL, TRUE, Channel, Controller, Value, m_pCallbackData);
				
				int a = 0;
			}
			break;

	}
	//MidiMessageType
	int a = 0;
}
void RefMidi::OnAddedMidiInDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformation^ Info)
{
	wstring wstrDeviceName(Info->Name->Data());
	wstring wstrDeviceID(Info->Id->Data());

	IMidiInPort^ Port = GetMidiInPort(Info->Id);
	if (Port)
	{
		Port->MessageReceived += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Midi::MidiInPort ^, Windows::Devices::Midi::MidiMessageReceivedEventArgs ^>(this, &RefMidi::OnMessageReceived);
		std::wstring wstrDeviceId(Info->Id->Data());
		MIDI_IN_DEVICE^ Device = ref new MIDI_IN_DEVICE(Port, Info->Name, Info->Id);

		AcquireSRWLockExclusive(&m_Lock_MidiInDeviceCollection);

		auto it = m_pMidiInDeviceList->find(wstrDeviceId);
		if (it == m_pMidiInDeviceList->end())
		{
			WriteDebugStringW(DEBUG_OUTPUT_TYPE_DEBUG_CONSOLE, L"[MidiLib] OnAddedMidiInDevice - %s , %s\n", wstrDeviceName.data(), wstrDeviceID.data());
			m_pMidiInDeviceList->insert(make_pair(wstrDeviceId, Device));
		}
		ReleaseSRWLockExclusive(&m_Lock_MidiInDeviceCollection);
	}
}

void RefMidi::OnRemovedMidiInDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformationUpdate^ Info)
{
	wstring wstrDeviceId(Info->Id->Data());

	IMidiInPort^ Port = GetMidiInPort(Info->Id);

	AcquireSRWLockExclusive(&m_Lock_MidiInDeviceCollection);

	auto it = m_pMidiInDeviceList->find(wstrDeviceId);
	if (it != m_pMidiInDeviceList->end())
	{
		MIDI_IN_DEVICE^	Device = it->second;
		wstring wstrDeviceName(Device->GetName()->Data());

		WriteDebugStringW(DEBUG_OUTPUT_TYPE_DEBUG_CONSOLE, L"[MidiLib] OnRemovedMidiInDevice - %s , %s\n", wstrDeviceName.data(), wstrDeviceId.data());
		m_pMidiInDeviceList->erase(it);

	}
	ReleaseSRWLockExclusive(&m_Lock_MidiInDeviceCollection);
}
void RefMidi::OnUpdatedMidiInDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformationUpdate^ InfoUpdated)
{

	wstring wstrDeviceId(InfoUpdated->Id->Data());
	IMidiInPort^ Port = GetMidiInPort(InfoUpdated->Id);

	AcquireSRWLockExclusive(&m_Lock_MidiInDeviceCollection);

	auto it = m_pMidiInDeviceList->find(wstrDeviceId);
	if (it != m_pMidiInDeviceList->end())
	{
		MIDI_IN_DEVICE^ Device = it->second;
		wstring wstrDeviceName(Device->GetName()->Data());

		WriteDebugStringW(DEBUG_OUTPUT_TYPE_DEBUG_CONSOLE, L"[MidiLib] OnUpdatedMidiInDevice - %s , %s\n", wstrDeviceName.data(), wstrDeviceId.data());
		Device->ReplacePort(Port);
	}
	ReleaseSRWLockExclusive(&m_Lock_MidiInDeviceCollection);
}
void RefMidi::OnEnumerationCompletedMidiInDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Platform::Object^ obj)
{
	//m_MidiInDeviceWatcher->Stop();
	//m_MidiInDeviceWatcher = nullptr;
	_InterlockedOr(&m_lMidiInDeviceListEnumCompleted, 1);
}
BOOL RefMidi::SetMidiOutDevice(const WCHAR* wchDeviceName)
{
	// 메인스레드에서 호출
	BOOL	bResult = FALSE;

	if (!_InterlockedOr(&m_lMidiOutDeviceListEnumCompleted, 0))
		goto lb_return;

	UINT DeviceNum = (UINT)m_pMidiOutDeviceList->size();

	for (auto it = m_pMidiOutDeviceList->begin(); it != m_pMidiOutDeviceList->end(); it++)
	{
		MIDI_OUT_DEVICE^	Device = it->second;
		wstring wstrExistDeviceName(Device->GetName()->Data());
		if (!wcscmp(wstrExistDeviceName.data(), wchDeviceName))
		{
			m_SelectedMidiOutDevice = Device;
			bResult = TRUE;
			break;
		}
	}
lb_return:
	return bResult;
	//if (!wcscmp(wchDeviceName, L"Microsoft GS Wavetable Synth"))
}
BOOL RefMidi::GetSelectedMidiOutDevice(MIDI_DEVICE_INFO* pOutInfo)
{
	if (!_InterlockedOr(&m_lMidiOutDeviceListEnumCompleted, 0))
		return FALSE;

	if (!m_SelectedMidiOutDevice)
		return FALSE;

	wstring wstrDeviceName(m_SelectedMidiOutDevice->GetName()->Data());
	wstring wstrDeviceId(m_SelectedMidiOutDevice->GetDeviceID()->Data());
	wcscpy_s(pOutInfo->wchName, wstrDeviceName.data());
	wcscpy_s(pOutInfo->wchID, wstrDeviceId.data());
	return TRUE;
}

BOOL RefMidi::SetMidiInDevice(const WCHAR* wchDeviceName)
{
	// 메인스레드에서 호출
	BOOL	bResult = FALSE;

	if (!_InterlockedOr(&m_lMidiInDeviceListEnumCompleted, 0))
		goto lb_return;

	UINT DeviceNum = (UINT)m_pMidiInDeviceList->size();

	for (auto it = m_pMidiInDeviceList->begin(); it != m_pMidiInDeviceList->end(); it++)
	{
		MIDI_IN_DEVICE^	Device = it->second;
		wstring wstrExistDeviceName(Device->GetName()->Data());
		if (!wcscmp(wstrExistDeviceName.data(), wchDeviceName))
		{
			m_SelectedMidiInDevice = Device;
			bResult = TRUE;
			break;
		}
	}
lb_return:
	return bResult;
	//if (!wcscmp(wchDeviceName, L"Microsoft GS Wavetable Synth"))
}
BOOL RefMidi::GetSelectedMidiInDevice(MIDI_DEVICE_INFO* pOutInfo)
{
	if (!_InterlockedOr(&m_lMidiInDeviceListEnumCompleted, 0))
		return FALSE;

	if (!m_SelectedMidiInDevice)
		return FALSE;

	wstring wstrDeviceName(m_SelectedMidiInDevice->GetName()->Data());
	wstring wstrDeviceId(m_SelectedMidiInDevice->GetDeviceID()->Data());
	wcscpy_s(pOutInfo->wchName, wstrDeviceName.data());
	wcscpy_s(pOutInfo->wchID, wstrDeviceId.data());
	return TRUE;
}
DWORD RefMidi::GetMidiInDeviceList(MIDI_DEVICE_INFO* pInInfoList, DWORD dwMaxBufferCount)
{
	AcquireSRWLockExclusive(&m_Lock_MidiInDeviceCollection);

	DWORD dwDeviceNum = (DWORD)m_pMidiInDeviceList->size();
	if (dwDeviceNum > dwMaxBufferCount)
	{
		dwDeviceNum = dwMaxBufferCount;
	}
	auto it = m_pMidiInDeviceList->begin();
	for (DWORD i = 0; i < dwDeviceNum; i++)
	{
		MIDI_IN_DEVICE^	Device = it->second;
		wstring wstrDeviceName(Device->GetName()->Data());
		wstring wstrDeviceId(Device->GetDeviceID()->Data());

		wcscpy_s(pInInfoList[i].wchName, wstrDeviceName.data());
		wcscpy_s(pInInfoList[i].wchID, wstrDeviceId.data());
		it++;
	}
	ReleaseSRWLockExclusive(&m_Lock_MidiInDeviceCollection);
	return dwDeviceNum;
}
DWORD RefMidi::GetMidiOutDeviceList(MIDI_DEVICE_INFO* pOutInfoList, DWORD dwMaxBufferCount)
{
	AcquireSRWLockExclusive(&m_Lock_MidiOutDeviceCollection);

	DWORD dwDeviceNum = (DWORD)m_pMidiOutDeviceList->size();
	if (dwDeviceNum > dwMaxBufferCount)
	{
		dwDeviceNum = dwMaxBufferCount;
	}
	auto it = m_pMidiOutDeviceList->begin();
	for (DWORD i = 0; i < dwDeviceNum; i++)
	{
		MIDI_OUT_DEVICE^	Device = it->second;
		wstring wstrDeviceName(Device->GetName()->Data());
		wstring wstrDeviceId(Device->GetDeviceID()->Data());

		wcscpy_s(pOutInfoList[i].wchName, wstrDeviceName.data());
		wcscpy_s(pOutInfoList[i].wchID, wstrDeviceId.data());
		it++;
	}
	ReleaseSRWLockExclusive(&m_Lock_MidiOutDeviceCollection);
	return dwDeviceNum;
}

RefMidi::~RefMidi()
{
	m_SelectedMidiInDevice = nullptr;
	m_SelectedMidiOutDevice = nullptr;

	m_MidiInDeivceInfoCollection = nullptr;
	m_MidiOutDeivceInfoCollection = nullptr;

	if (m_pMidiInDeviceList)
	{
		delete m_pMidiInDeviceList;
		m_pMidiInDeviceList = nullptr;
	}
	if (m_pMidiOutDeviceList)
	{
		delete m_pMidiOutDeviceList;
		m_pMidiOutDeviceList = nullptr;
	}
	if (m_MidiInDeviceWatcher)
	{
		m_MidiInDeviceWatcher->Stop();
		m_MidiInDeviceWatcher = nullptr;
	}
	if (m_MidiOutDeviceWatcher)
	{
		m_MidiOutDeviceWatcher->Stop();
		m_MidiOutDeviceWatcher = nullptr;
	}
	m_MidiInSelectorString = nullptr;
	m_MidiOutSelectorString = nullptr;
}

void RefMidi::OnAddedAsync(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformation^ Info)
{
	/*
	if (!m_MideOutPort)
	{
		create_task(MidiOutPort::FromIdAsync(Info->Id)).then([this, Info](IMidiOutPort^ Port)
		{
			const WCHAR* wchDeviceName = Info->Name->Data();
			const WCHAR* wchDeviceID = Info->Id->Data();

			if (!wcscmp(wchDeviceName, L"Microsoft GS Wavetable Synth"))
			{
				if (0 == _InterlockedOr(&m_lDeivcePrepared, 0))
				{
					m_MideOutPort = Port;
					_InterlockedIncrement(&m_lDeivcePrepared);

					WCHAR wchTxt[256] = {};
					swprintf_s(wchTxt, L"Midi Device Found \n \tName:%s, ID:%s\n", wchDeviceName, wchDeviceID);
					OutputDebugStringW(wchTxt);
				}
				else
				{
					int a = 0;
				}
			}
		});
	}
	else
	{
		int a = 0;
	}
	*/

	//m_deviceInformationCollection = DeviceInformation::FindAllAsync(m_midiSelectorString);
	/*
			// If no devices are found, update the ListBox
			if ((this.deviceInformationCollection == null) || (this.deviceInformationCollection.Count == 0))
			{
				// Start with a clean list
				this.portList.Items.Clear();

				this.portList.Items.Add("No MIDI ports found");
				this.portList.IsEnabled = false;
			}
			// If devices are found, enumerate them and add them to the list
			else
			{
				// Start with a clean list
				this.portList.Items.Clear();

				foreach (var device in deviceInformationCollection)
				{
					this.portList.Items.Add(device.Name);
				}

				this.portList.IsEnabled = true;
			}
		}

		int a = 0;
	}
	*/
}