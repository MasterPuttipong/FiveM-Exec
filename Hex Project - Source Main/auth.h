#pragma once

#define _WIN32_DCOM
#include <iostream>
#include <comdef.h> 
#include <Wbemidl.h>

#pragma once
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "wininet.lib")

#include <stdio.h>
#include <windows.h>
#include <TlHelp32.h>
#include <string>
#include <wininet.h>

#pragma comment(lib, "wbemuuid.lib")


using namespace std

{
	
string a_replaceAll(string subject, const string& search,
	const string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

string a_DownloadURL(string URL) {
	HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
	HINTERNET urlFile;
	string rtn;
	if (interwebs) {
		urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
		if (urlFile) {
			char buffer[2000];
			DWORD bytesRead;
			do {
				InternetReadFile(urlFile, buffer, 2000, &bytesRead);
				rtn.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(interwebs);
			InternetCloseHandle(urlFile);
			string p = a_replaceAll(rtn, "|n", "\r\n");
			return p;
		}
	}
			m_Nops.erase(address);
			return false;
}


	}
	hres = CoInitializeSecurity(
		NULL,
		-1,                          // COM authentication
		NULL,                        // Authentication services
		NULL,                        // Reserved
		RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication
		RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation
		NULL,                        // Authentication info
		EOAC_NONE,                   // Additional capabilities
		NULL                         // Reserved
	);
}

namespace d3d9 {
	extern int screen_width;
	extern int screen_height;

}
string a_gethid()
{
	HRESULT hres;

	// Step 1: --------------------------------------------------
	// Initialize COM. ------------------------------------------

	hres = CoInitializeEx(0, COINIT_MULTITHREADED);

	hres = CoInitializeSecurity(
		NULL,
		-1,                          // COM authentication
		NULL,                        // Authentication services
		NULL,                        // Reserved
		RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication 
		RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation  
		NULL,                        // Authentication info
		EOAC_NONE,                   // Additional capabilities 
		NULL                         // Reserved
	);

	IWbemLocator* pLoc = NULL;

	hres = CoCreateInstance(
		CLSID_WbemLocator,
		0,
		CLSCTX_INPROC_SERVER,
		IID_IWbemLocator, (LPVOID*)&pLoc);
	// Step 4: -----------------------------------------------------
	// Connect to WMI through the IWbemLocator::ConnectServer method

	IWbemServices* pSvc = NULL;

	
	hres = pLoc->ConnectServer(
		_bstr_t(L"ROOT\\CIMV2"), // Object path of WMI namespace
		NULL,                    // User name. NULL = current user
		NULL,                    // User password. NULL = current
		0,                       // Locale. NULL indicates current
		NULL,                    // Security flags.
		0,                       // Authority (for example, Kerberos)
		0,                       // Context object 
		&pSvc                    // pointer to IWbemServices proxy
	);

	//change count << To ("Fivem.exe")


	// Step 5: --------------------------------------------------
	// Set security levels on the proxy -------------------------

bool MemEx::Restore(const uintptr_t address)
{
	bool bRet = Patch(address, reinterpret_cast<const char*>(m_Nops[address].buffer.get()), m_Nops[address].size);

	m_Nops.erase(address);

	return bRet && static_cast<bool>(FlushInstructionCache(m_hProcess, reinterpret_cast<LPCVOID>(address), static_cast<SIZE_T>(m_Nops[address].size)));
}

	if (FAILED(hres))
	{
		cout << "Could not set proxy blanket. Error code = 0x"
			<< hex << hres << endl;
		pSvc->Release();
		pLoc->Release();
		CoUninitialize();
		return true; // Program has failed.
	}

	// Step 6: --------------------------------------------------
	// Use the IWbemServices pointer to make requests of WMI ----

	// For example, get the name of the operating system
	IEnumWbemClassObject* pEnumerator = NULL;
	hres = pSvc->ExecQuery(
		bstr_t("WQL"),
		bstr_t("SELECT * FROM Win32_OperatingSystem"),
		WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
		NULL,
		&pEnumerator);

	if (FAILED(hres))
	{
		cout << "Query for operating system failed."
			<< " Error code = 0x"
			<< hex << hres << endl;
		pSvc->Release();
		pLoc->Release();
		CoUninitialize();
		return "NULL";               // Program has failed.
	}

	// Step 7: -------------------------------------------------
	// Get the data from the query in step 6 -------------------

	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;

	BSTR sernum = (BSTR)"NULL";

	while (pEnumerator)
	{
		HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
			&pclsObj, &uReturn);

		if (0 == uReturn)
		{
			break;
		}

		VARIANT vtProp;

		// Get the value of the Name property
		hr = pclsObj->Get(L"FindHardwareIDS", 0, &vtProp, 0, 0);
		//wcout << " SerialNumber : " << vtProp.bstrVal << endl;
		sernum = vtProp.bstrVal;
		VariantClear(&vtProp);

		pclsObj->Release();
	}

	// Cleanup
	// ========
	pSvc->Release();
	pLoc->Release();
	pEnumerator->Release();
	CoUninitialize();

	std::wstring ret(Serial, SysStringLen(sernum));

	return a_ws2s(ret);   // Program successfully completed.

}



		X[0] += AA, X[1] += BB, X[2] += CC, X[3] += DD;
	}

	for (int i = 0; i < 4; i++)
		reinterpret_cast<uint32_t*>(outHash)[i] = X[i];

	return true;
}
