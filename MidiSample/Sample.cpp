#include "../Megayuchi_Common/typedef.h"
#include "../Megayuchi_Common/IMidiLib.h"

void __stdcall OnMidiInputCallback(MIDI_SIGNAL_TYPE type, BOOL bOnOff, unsigned char channel, unsigned char key, unsigned char Velocity, void* pData)
{
	// input from midi device
	// this function called by any thread. synchronization needed.

	MIDI_NOTE_L	midiNote;
	switch (type)
	{
		case MIDI_SIGNAL_TYPE_NOTE:
			midiNote.SetAsNote(bOnOff, (DWORD)Velocity, (DWORD)key);
			break;
		case MIDI_SIGNAL_TYPE_CONTROL:
			midiNote.SetAsControl((DWORD)Velocity, (DWORD)key);
			break;
		default:
			__debugbreak();
	}
	PostMessage(g_hMainWindow, WM_MIDI_INPUT, *(UINT*)&midiNote, 0);
}
void InitMidi()
{
	IMidiLib*	pMidiLib = nullptr;
	const WCHAR* wchMidiLibFileName = L"MidiLib_x64_debug.dll";
	// Load MidiLib
	CREATE_INSTANCE_FUNC pFuncCreateMidiLib = nullptr;
	HMODULE hMidiLibDLL = LoadLibrary(wchMidiLibFileName);
	if (hMidiLibDLL)
	{
		pFuncCreateMidiLib = (CREATE_INSTANCE_FUNC)GetProcAddress(hMidiLibDLL, "DllCreateInstance");
		HRESULT hr = pFuncCreateMidiLib(&pMidiLib);
		if (hr != S_OK)
			__debugbreak();

		void* pCallbackData = nullptr;	// pCallbackData is value passed when called OnMidiInputCallback
		pMidiLib->Initialize(OnMidiInputCallback, pCallbackData);	

		// blablabla....


		if (pMidiLib)
		{
			pMidiLib->Release();
			pMidiLib = nullptr;
		}
	}
}