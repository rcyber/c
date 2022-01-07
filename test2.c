#include "stdafx.h"
#include <cstdlib>
#include "ShellAPI.h"
 
int main()
{
    //открыть браузер
    ShellExecute(Application.Handle, 'open', 'http://google.ru', nil, nil, SW_SHOWNORMAL);
 
    //открыть программу       
    ShellExecute(hwnd, "find", "c:\\MyPrograms", NULL, NULL, 0);
 
    //калькулятор открывает
    system("calc");
 
    return 0;
}
