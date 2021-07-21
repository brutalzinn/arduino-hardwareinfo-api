#include "AutoStartUp.h"
#include <Windows.h>
#include <tchar.h>
// this class can be found at https://github.com/itwhy1994/AutoStartUp Thanks itwhy1994 to share with us <3
AutoStartUp::AutoStartUp()
{

}


AutoStartUp::~AutoStartUp()
{
}

void AutoStartUp::createAutoStartUp()
{
    HKEY hkey;
    const unsigned int iMaxPathLength = 256;
    char fileName[iMaxPathLength] = { 0 };
    //Get the full path of the program
    GetModuleFileName(NULL, (LPWCH)fileName, iMaxPathLength);
    //Find system startup item
    LPCTSTR lpAutoStartUp = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
    //Add AutoStartUp
    long lOpenKey = RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpAutoStartUp, 0, KEY_WRITE, &hkey);
    if (lOpenKey == ERROR_SUCCESS)
    {
        RegSetValueEx(hkey, _T("PythonHardwareMonitor"), 0, REG_SZ, (const BYTE*)(LPCSTR)fileName, iMaxPathLength);
        RegCloseKey(hkey);
    }
  ;
}

void AutoStartUp::deleteAutoStartUp()
{
    HKEY hkey;
    const unsigned int iMaxPathLength = 256;
    char fileName[iMaxPathLength] = { 0 };
    //Get the full path of the program
    GetModuleFileName(NULL, (LPWCH)fileName, iMaxPathLength);
    //Find system startup item
    LPCTSTR lpAutoStartUp = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
    //Add AutoStartUp
    long lOpenKey = RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpAutoStartUp, 0, KEY_WRITE, &hkey);
    if (lOpenKey == ERROR_SUCCESS)
    {
        RegDeleteValue(hkey, _T("PythonHardwareMonitor"));
        RegCloseKey(hkey);
    }
}

