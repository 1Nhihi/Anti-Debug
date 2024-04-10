#include <windows.h>
#include <iostream>

using namespace std;
// CheckHardwareBreakpoints returns the number of hardware 
// breakpoints detected and on failure it returns -1.
int CheckHardwareBreakpoints()
{
    unsigned int NumBps = 0;

    // This structure is key to the function and is the 
    // medium for detection and removal
    CONTEXT ctx;
    ZeroMemory(&ctx, sizeof(CONTEXT)); 
    
    // The CONTEXT structure is an in/out parameter therefore we have
    // to set the flags so Get/SetThreadContext knows what to set or get.
    ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS; 
    
    // Get a handle to our thread
    HANDLE hThread = GetCurrentThread();

    // Get the registers
    if(GetThreadContext(hThread, &ctx) == 0)
        return -1;

    // Now we can check for hardware breakpoints, its not 
    // necessary to check Dr6 and Dr7, however feel free to
    if(ctx.Dr0 != 0)
        ++NumBps; 
    if(ctx.Dr1 != 0)
           ++NumBps; 
    if(ctx.Dr2 != 0)
           ++NumBps; 
    if(ctx.Dr3 != 0)
        ++NumBps;
        
    return NumBps;
}
int main(){
    if (!CheckHardwareBreakpoints)
        cout<< "dang debug roi ne, phai dung thoi"<<endl;
    else
        cout <<"Hello ^^"<<endl;
}