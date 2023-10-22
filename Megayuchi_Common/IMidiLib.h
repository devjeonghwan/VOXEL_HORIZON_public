#pragma once

struct MIDI_DEVICE_INFO
{
	WCHAR wchName[128];
	WCHAR wchID[128];
};
enum MIDI_SIGNAL_TYPE
{
	MIDI_SIGNAL_TYPE_NOTE,
	MIDI_SIGNAL_TYPE_CONTROL
};
typedef void (__stdcall *ON_MIDI_INPUT_CALLBACK)(MIDI_SIGNAL_TYPE type, BOOL bOnOff, unsigned char channel, unsigned char key, unsigned char Velocity, void* pData);

interface IMidiLib : public IUnknown
{
	virtual BOOL __stdcall	Initialize(ON_MIDI_INPUT_CALLBACK pMidiInCallback, void* pData) = 0;
	virtual BOOL __stdcall 	SetMidiOutDevice(const WCHAR* wchDeviceName) = 0;
	virtual BOOL __stdcall	GetSelectedMidiOutDevice(MIDI_DEVICE_INFO* pOutInfo) = 0;
	virtual BOOL __stdcall 	SetMidiInDevice(const WCHAR* wchDeviceName) = 0;
	virtual BOOL __stdcall	GetSelectedMidiInDevice(MIDI_DEVICE_INFO* pOutInfo) = 0;
	virtual BOOL __stdcall 	SetVolume(unsigned char channel, unsigned char Volume) = 0;
	virtual BOOL __stdcall	SetSustainPedal(unsigned char channel, unsigned char Value) = 0;
	virtual BOOL __stdcall	NoteOn(unsigned char channel, unsigned char note, unsigned char Velocity) = 0;
	virtual BOOL __stdcall	NoteOff(unsigned char channel, unsigned char note, unsigned char Velocity) = 0;
	virtual DWORD __stdcall GetMidiInDeviceList(MIDI_DEVICE_INFO* pOutInfoList, DWORD dwMaxBufferCount) = 0;
	virtual DWORD __stdcall GetMidiOutDeviceList(MIDI_DEVICE_INFO* pOutInfoList, DWORD dwMaxBufferCount) = 0;
};

