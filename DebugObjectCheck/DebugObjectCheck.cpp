#include <iostream>
#include "windows.h"
#include <string.h>
using namespace std;// This function uses NtQuerySystemInformation
// to try to retrieve a handle to the current
// process's debug object handle. If the function
// is successful it'll return true which means we're
// being debugged or it'll return false if it fails
// or the process isn't being debugged
inline bool DebugObjectCheck()
{
    // Much easier in ASM but C/C++ looks so much better
    typedef NTSTATUS (WINAPI *pNtQueryInformationProcess)
            (HANDLE ,UINT ,PVOID ,ULONG , PULONG); 

    HANDLE hDebugObject = NULL;
    NTSTATUS Status; 

    // Get NtQueryInformationProcess
    pNtQueryInformationProcess NtQIP = (pNtQueryInformationProcess)
                GetProcAddress(  GetModuleHandle( TEXT("ntdll.dll") ), 
                "NtQueryInformationProcess" ); 

    Status = NtQIP(GetCurrentProcess(), 
            0x1e, // ProcessDebugObjectHandle
            &hDebugObject, 4, NULL); 
    
    if (Status != 0x00000000)
        return false; 

    if(hDebugObject)
        return true;
    else
        return false;
}

int main(){
    if (!DebugObjectCheck)
        cout<< "dang debug roi ne, phai dung thoi"<<endl;
    else
        cout <<"Hello ^^"<<endl;
}
