#pragma once

#include "../Megayuchi_Common/typedef.h"
#include "../Megayuchi_Common/IMidiLib.h"

ref class RefMidi;

class CMidiLib : public IMidiLib
{
	DWORD	m_dwRefCount = 1;
	RefMidi^ m_pRefMidi = nullptr;
	ON_MIDI_INPUT_CALLBACK	m_pOnMidiInputCallback = nullptr;
	void*	m_pCallbackData = nullptr;
	void	Cleanup();
public:
	STDMETHODIMP			QueryInterface(REFIID refiid, void** ppv);
	STDMETHODIMP_(ULONG)	AddRef();
	STDMETHODIMP_(ULONG)	Release();

	BOOL __stdcall	Initialize(ON_MIDI_INPUT_CALLBACK pMidiInCallback, void* pData);
	BOOL __stdcall 	SetMidiOutDevice(const WCHAR* wchDeviceName);
	BOOL __stdcall	GetSelectedMidiOutDevice(MIDI_DEVICE_INFO* pOutInfo);
	BOOL __stdcall 	SetMidiInDevice(const WCHAR* wchDeviceName);
	BOOL __stdcall	GetSelectedMidiInDevice(MIDI_DEVICE_INFO* pOutInfo);
	BOOL __stdcall 	SetVolume(unsigned char channel, unsigned char Volume);
	BOOL __stdcall	SetSustainPedal(unsigned char channel, unsigned char Value);
	BOOL __stdcall	NoteOn(unsigned char channel, unsigned char note, unsigned char Velocity);
	BOOL __stdcall	NoteOff(unsigned char channel, unsigned char note, unsigned char Velocity);
	DWORD __stdcall GetMidiInDeviceList(MIDI_DEVICE_INFO* pOutInfoList, DWORD dwMaxBufferCount);
	DWORD __stdcall GetMidiOutDeviceList(MIDI_DEVICE_INFO* pOutInfoList, DWORD dwMaxBufferCount);


	CMidiLib();
	~CMidiLib();
};



