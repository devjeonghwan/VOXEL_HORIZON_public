// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "../Megayuchi_Common/IMidiLib.h"
#include "MidiLib.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


STDAPI DllCreateInstance(void** ppv)
{
	HRESULT hr;
    CMidiLib*   pMidiLib = new CMidiLib;
	if (!pMidiLib)
	{
		hr = E_OUTOFMEMORY;
		goto lb_return;
	}
	hr = S_OK;
	*ppv = pMidiLib;
lb_return:
	return hr;
}