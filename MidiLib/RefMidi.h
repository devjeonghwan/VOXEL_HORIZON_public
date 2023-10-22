#pragma once

#include <unordered_map>
#include <string>

using namespace std;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Devices::Enumeration;
using namespace Windows::Devices::Midi;

ref class MIDI_IN_DEVICE sealed
{
	IMidiInPort^ Port;
	String^ Name;
	String^ DeviceID;
public:
	MIDI_IN_DEVICE(IMidiInPort^ _Port, String^ _Name, String^ _DeviceID)
	{
		Port = _Port;
		Name = _Name;
		DeviceID = _DeviceID;
	}
	void ReplacePort(IMidiInPort^ _Port)
	{
		Port = _Port;
	}
	IMidiInPort^ GetPort()
	{
		return Port;
	}
	String^ GetName()
	{
		return Name;
	}
	String^ GetDeviceID()
	{
		return DeviceID;
	}
};

ref class MIDI_OUT_DEVICE sealed
{
	IMidiOutPort^ Port;
	String^ Name;
	String^ DeviceID;
public:
	MIDI_OUT_DEVICE(IMidiOutPort^ _Port, String^ _Name, String^ _DeviceID)
	{
		Port = _Port;
		Name = _Name;
		DeviceID = _DeviceID;
	}
	void ReplacePort(IMidiOutPort^ _Port)
	{
		Port = _Port;
	}
	IMidiOutPort^ GetPort()
	{
		return Port;
	}
	String^ GetName()
	{
		return Name;
	}
	String^ GetDeviceID()
	{
		return DeviceID;
	}
};

const DWORD MAX_MIDI_PORT_NUM = 16;
ref class RefMidi sealed
{
	LONG volatile m_lMidiInDeviceListEnumCompleted = 1;
	LONG volatile m_lMidiOutDeviceListEnumCompleted = 1;

	DeviceInformationCollection^	m_MidiInDeivceInfoCollection = nullptr;
	DeviceInformationCollection^	m_MidiOutDeivceInfoCollection = nullptr;
	DeviceWatcher^	m_MidiInDeviceWatcher = nullptr;
	DeviceWatcher^	m_MidiOutDeviceWatcher = nullptr;

	String^	m_MidiInSelectorString = nullptr;
	String^	m_MidiOutSelectorString = nullptr;
	ON_MIDI_INPUT_CALLBACK	m_pOnMidiInputCallback = nullptr;
	void*	m_pCallbackData = nullptr;

	std::unordered_map<std::wstring, MIDI_IN_DEVICE^>* m_pMidiInDeviceList = nullptr;
	SRWLOCK	m_Lock_MidiInDeviceCollection = {};
	MIDI_IN_DEVICE^ m_SelectedMidiInDevice = nullptr;

	std::unordered_map<std::wstring, MIDI_OUT_DEVICE^>* m_pMidiOutDeviceList = nullptr;
	SRWLOCK	m_Lock_MidiOutDeviceCollection = {};
	MIDI_OUT_DEVICE^ m_SelectedMidiOutDevice = nullptr;

	void UpdateMidiInDeviceList();
	void UpdateMidiOutDeviceList();
	IMidiOutPort^	GetMidiOutPort(Platform::String^ Id);
	IMidiInPort^	GetMidiInPort(Platform::String^ Id);

	IMidiInPort^	GetSelectedMidiInPort();
	IMidiOutPort^	GetSelectedMidiOutPort();

	//Vector<String^>^	m_DeviceNameList = nullptr;
	void OnAddedAsync(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformation^ Info);
	void OnAddedMidiOutDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformation^ Info);
	void OnRemovedMidiOutDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformationUpdate^ InfoUpdate);
	void OnUpdatedMidiOutDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformationUpdate^ InfoUpdated);
	void OnEnumerationCompletedMidiOutDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Platform::Object^ obj);

	void OnAddedMidiInDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformation^ Info);
	void OnRemovedMidiInDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformationUpdate^ InfoUpdate);
	void OnUpdatedMidiInDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Windows::Devices::Enumeration::DeviceInformationUpdate^ InfoUpdated);
	void OnEnumerationCompletedMidiInDevice(Windows::Devices::Enumeration::DeviceWatcher^ watcher, Platform::Object^ obj);
	void OnMessageReceived(Windows::Devices::Midi::MidiInPort ^ Port, Windows::Devices::Midi::MidiMessageReceivedEventArgs^ args);
	~RefMidi();
public:

internal:
	void	RequestUpdateMidiInDeviceList();
	void	RequestUpdateMidiOutDeviceList();
	BOOL	SetVolume(unsigned char channel, unsigned char Volume);
	BOOL	SetSustainPedal(unsigned char channel, unsigned char Value);
	BOOL	NoteOn(unsigned char channel, unsigned char note, unsigned char Velocity);
	BOOL	NoteOff(unsigned char channel, unsigned char note, unsigned char Velocity);

	DWORD	GetMidiInDeviceList(MIDI_DEVICE_INFO* pInInfoList, DWORD dwMaxBufferCount);
	DWORD	GetMidiOutDeviceList(MIDI_DEVICE_INFO* pOutInfoList, DWORD dwMaxBufferCount);
	
	BOOL	SetMidiOutDevice(const WCHAR* wchDeviceName);
	BOOL	GetSelectedMidiOutDevice(MIDI_DEVICE_INFO* pOutInfo);

	BOOL	SetMidiInDevice(const WCHAR* wchDeviceName);
	BOOL	GetSelectedMidiInDevice(MIDI_DEVICE_INFO* pOutInfo);
	RefMidi(ON_MIDI_INPUT_CALLBACK	pMidiInputCallback, void* pData);
};
