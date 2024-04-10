#include <iostream>
#include "windows.h"
using namespace std;
int main(int argc, char *argv[])
{
    BOOL isDebuggerPresent = FALSE;
    if (CheckRemoteDebuggerPresent(GetCurrentProcess(), &isDebuggerPresent ))
    {
        if (isDebuggerPresent )
        {
            std::cout << "Stop debugging program!" << std::endl;
            exit(-1);
        }else{
            std::cout<< "Hello ^^"<<std::endl;
        }
    }
    return 0;
}