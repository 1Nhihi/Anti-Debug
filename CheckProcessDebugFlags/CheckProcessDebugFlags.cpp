#include <iostream>
#include "windows.h"
#include <string.h>
using namespace std;

// CheckProcessDebugFlags will return true if 
// the EPROCESS->NoDebugInherit is == FALSE, 
// the reason we check for false is because 
// the NtQueryProcessInformation function returns the
// inverse of EPROCESS->NoDebugInherit so (!TRUE == FALSE)
inline bool CheckProcessDebugFlags()
{
    // Much easier in ASM but C/C++ looks so much better
    typedef NTSTATUS (WINAPI *pNtQueryInformationProcess)
        (HANDLE ,UINT ,PVOID ,ULONG , PULONG); 

    DWORD NoDebugInherit = 0; 
    NTSTATUS Status; 

    // Get NtQueryInformationProcess
    pNtQueryInformationProcess NtQIP = (pNtQueryInformationProcess)
        GetProcAddress( GetModuleHandle( TEXT("ntdll.dll") ), 
        "NtQueryInformationProcess" ); 

    Status = NtQIP(GetCurrentProcess(), 
            0x1f, // ProcessDebugFlags
            &NoDebugInherit, 4, NULL); 

    if (Status != 0x00000000)
        return false; 

    if(NoDebugInherit == FALSE)
        return true;
    else
        return false;
}

int main(){
    if (!CheckProcessDebugFlags)
        cout<< "dang debug roi ne, phai dung thoi"<<endl;
    else
        cout <<"Hello ^^"<<endl;
}
