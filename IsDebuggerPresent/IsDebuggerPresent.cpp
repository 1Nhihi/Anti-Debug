#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
    if (IsDebuggerPresent())
    {
    	cout<< "dang debug roi ne, phai dung thoi"<<endl;
    	ExitProcess(-1);
    }else{
    	cout <<"Hello ^^"<<endl;
	}

}