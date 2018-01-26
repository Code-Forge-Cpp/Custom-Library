#include <stdlib.h>
/*

#include <TlHelp32.h>
#include <stdio.h>
//#include <string>
#include <fstream>
//forShell
//#include <cstdlib>
#include <cstdio>
//#include <string>
#include <cstring>
//#include "windows.h"
#include <shellapi.h>
#pragma comment(lib,"shell32.lib") 
*/
//#include <string.h>

static HWND hBut; 
//#include <vector> // Not require to pass data pipe

 #undef UNICODE
 #undef _UNICODE
#define FileExists(f) (GetFileAttributes(f)!=-1&&\
	!(GetFileAttributes(f)&FILE_ATTRIBUTE_DIRECTORY))
#define DirExists(f) (GetFileAttributes(f)!=-1&&\
	(GetFileAttributes(f)&FILE_ATTRIBUTE_DIRECTORY)) 

using namespace std;
using namespace System::Diagnostics;



class WinProc {


public:
	bool IsFileExists( std::string ProcessName) // works beatyfully
	{
		std::ifstream test(ProcessName.c_str());
		return (test ? true : false);
		test.close();
	}



	//exists

	// Check if is process on WINDOWS
	bool IsProcess(std::string  ProcessName){


		//std::string ProcName = ProcessName; // LPCTSTR(ProcessName.c_str());
		bool success = false;	
		HANDLE hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		PROCESSENTRY32 pe32 = {sizeof(PROCESSENTRY32)};
		DWORD processId = NULL;


	


		if(Process32First(hProcSnap, &pe32))
		{
			do{
				std::wstring s(pe32.szExeFile);
				//MessageBoxA(NULL,( char*)(s.c_str()),"",MB_OK);

				if( !CMP_LPCSTR_AND_String(pe32.szExeFile,ProcessName) )
				{

					processId = pe32.th32ProcessID;
					//   cout << "Found "<<ProcName << " program" <<endl;
					success = true;
					break;
				}
				//  cout << "Searching for "<<ProcName << ", " << pe32.szExeFile<<endl;

			}
			while(Process32Next(hProcSnap, &pe32));
		}
		CloseHandle(hProcSnap);
		return success;
	};// IsProcess("cstrike.exe"); 


	void RunProcessByName (std::string RelativePath) {
		std::string path = RelativePath; // "d:\\test1.exe";

		///	ShellExecuteA(GetDesktopWindow(), ("open"), (path.c_str()), NULL, NULL, SW_SHOWNORMAL);
		//Process::Start("C:\\application_directory\\PreSets.exe");
		   Process::Start("C:\\Program Files\\Notepad++\\notepad++.exe");
	};

	//Kill Selected Process
	bool KillProcessByName(std::string ProcessName){
		//LPCTSTR(ProcessName.c_str());
		HANDLE hProcessSnap;
		HANDLE hProcess;
		PROCESSENTRY32 pe32;
		//DWORD dwPriorityClass;
		bool success = false;

		hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);  // Takes a snapshot of all the processes

		if(hProcessSnap == INVALID_HANDLE_VALUE){
			return( FALSE );
		}

		pe32.dwSize = sizeof(PROCESSENTRY32);

		if(!Process32First(hProcessSnap, &pe32)){
			CloseHandle(hProcessSnap);
			return( FALSE );
		}

		do{
			if(!CMP_LPCSTR_AND_String(pe32.szExeFile,ProcessName) ){    //  checks if process at current position has the name of to be killed app
				hProcess = OpenProcess(PROCESS_TERMINATE,0, pe32.th32ProcessID);  // gets handle to process
				TerminateProcess(hProcess,0);   // Terminate process by handle
				success = true;
				break;
			}
		}while(Process32Next(hProcessSnap,&pe32));  // gets next member of snapshot

		CloseHandle(hProcessSnap);  // closes the snapshot handle
		return( success );
	}; //How to Use it: KillProcessByName("notepad.exe");

	
	
	int  ToChar (std::string s1,const std::string&  s2){
		// if true return 0 else -1  
		//return (stricmp((char*)(s1.c_str()),(char*)(s2.c_str()) )); // Working Great
		//return (lstrcmpi((LPCTSTR)(s1.c_str()),(LPCTSTR)(s2.c_str()) ));   // workd onlly if (C:\\ABC,C:\\ABC) and return result after push twice #Strange
		//return strcmp((char*)(s1.c_str()),(char*)(s2.c_str())); //Works as expected 
		WCHAR HIT[4] = L"LOL"; 
		std::wstring s = HIT;		


		return CMP_LPCSTR_AND_String(HIT,s2);  //wcscmp (HIT, ToLPCTSTR("LOL"));
	};


private:
	std::wstring ToWstring(const std::string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
	}
   
	bool CMP_LPCSTR_AND_String(LPCTSTR a, std::string b) {
		std::wstring stemp = ToWstring(b); // Temporary buffer is required
		LPCTSTR L_filename = stemp.c_str();	 // convert and store as should be 
		return  wcscmp (a, L_filename)?true:false; // compare both as one LPCSTR type data
	}

	 
	
};




