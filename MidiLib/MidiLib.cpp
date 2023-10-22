#include "stdafx.h"
#include "MidiLib.h"
#include "../Megayuchi_Common/IMidiLib.h"
#include "RefMidi.h"

CMidiLib::CMidiLib()
{
#ifdef _DEBUG
	int	flag = _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF;
	_CrtSetDbgFlag(flag);
#endif
}

STDMETHODIMP CMidiLib::QueryInterface(REFIID refiid, void** ppv)
{
	return E_NOINTERFACE;

}
STDMETHODIMP_(ULONG) CMidiLib::AddRef()
{
	m_dwRefCount++;
	return m_dwRefCount;

}
STDMETHODIMP_(ULONG) CMidiLib::Release()
{
	DWORD ref_count = --m_dwRefCount;
	if (!m_dwRefCount)
	{
		delete this;
	}

	return ref_count;
}
BOOL __stdcall CMidiLib::Initialize(ON_MIDI_INPUT_CALLBACK pMidiInCallback, void* pData)
{
	m_pRefMidi = ref new RefMidi(pMidiInCallback, pData);
	m_pRefMidi->RequestUpdateMidiInDeviceList();
	m_pRefMidi->RequestUpdateMidiOutDeviceList();

	m_pOnMidiInputCallback = pMidiInCallback;
	return TRUE;
}
BOOL __stdcall CMidiLib::SetMidiOutDevice(const WCHAR* wchDeviceName)
{
	BOOL bResult = m_pRefMidi->SetMidiOutDevice(wchDeviceName);
	return bResult;
}
BOOL __stdcall CMidiLib::GetSelectedMidiOutDevice(MIDI_DEVICE_INFO* pOutInfo)
{
	BOOL bResult = m_pRefMidi->GetSelectedMidiOutDevice(pOutInfo);
	return bResult;
}
BOOL __stdcall CMidiLib::SetMidiInDevice(const WCHAR* wchDeviceName)
{
	BOOL bResult = m_pRefMidi->SetMidiInDevice(wchDeviceName);
	return bResult;
}
BOOL __stdcall CMidiLib::GetSelectedMidiInDevice(MIDI_DEVICE_INFO* pOutInfo)
{
	BOOL bResult = m_pRefMidi->GetSelectedMidiInDevice(pOutInfo);
	return bResult;
}

DWORD __stdcall CMidiLib::GetMidiInDeviceList(MIDI_DEVICE_INFO* pOutInfoList, DWORD dwMaxBufferCount)
{
	DWORD dwDeviceNum = m_pRefMidi->GetMidiInDeviceList(pOutInfoList, dwMaxBufferCount);
	return dwDeviceNum;
}
DWORD __stdcall CMidiLib::GetMidiOutDeviceList(MIDI_DEVICE_INFO* pOutInfoList, DWORD dwMaxBufferCount)
{
	DWORD dwDeviceNum = m_pRefMidi->GetMidiOutDeviceList(pOutInfoList, dwMaxBufferCount);
	return dwDeviceNum;
}
BOOL __stdcall CMidiLib::SetVolume(unsigned char channel, unsigned char Volume)
{
	BOOL bResult = m_pRefMidi->SetVolume(channel, Volume);
	return bResult;
}
BOOL __stdcall CMidiLib::SetSustainPedal(unsigned char channel, unsigned char Value)
{
	BOOL bResult = m_pRefMidi->SetSustainPedal(channel, Value);
	return bResult;
}
BOOL __stdcall CMidiLib::NoteOn(unsigned char channel, unsigned char note, unsigned char Velocity)
{
	BOOL bResult = m_pRefMidi->NoteOn(channel, note, Velocity);
	return bResult;
}
BOOL __stdcall CMidiLib::NoteOff(unsigned char channel, unsigned char note, unsigned char Velocity)
{
	BOOL bResult = m_pRefMidi->NoteOff(channel, note, Velocity);
	return bResult;
}
void CMidiLib::Cleanup()
{
	m_pRefMidi = nullptr;
}

CMidiLib::~CMidiLib()
{
	Cleanup();
#ifdef _DEBUG
	_ASSERT(_CrtCheckMemory());
#endif
}