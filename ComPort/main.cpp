#include "ParserClass.h"


using namespace std;

HANDLE hSerial;


union types {
    int value;
    char data[4];
};

static int value = 0;
void ReadCOM()
{
    string str;
    types vn;
    DWORD iSize;
    char sReceivedChar;
    while (true)
    {
        ReadFile(hSerial, &sReceivedChar, 1, &iSize, 0);  // получаем 1 байт
        if (iSize > 0)   // если что-то принято, выводим
        {
            if (sReceivedChar != '\n')
            {
                str += sReceivedChar;
            }
            else {
              //  cout << str << endl;
                ParserClass pc(str);
                str.clear();
               // cout << str << endl;
            }
        }
           // cout << sReceivedChar;

    }
}

int _tmain(int argc, TCHAR* argv[])
{
	LPCTSTR sPortName = L"COM4";
	hSerial = ::CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hSerial == INVALID_HANDLE_VALUE)
    {
        if (GetLastError() == ERROR_FILE_NOT_FOUND)
        {
            cout << "serial port does not exist.\n";
        }
        cout << "some other error occurred.\n";
    }
    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams))
    {
        cout << "getting state error\n";
    }
    dcbSerialParams.BaudRate = CBR_115200;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    if (!SetCommState(hSerial, &dcbSerialParams))
    {
        cout << "error setting serial port state\n";
    }
    char data[] = "Hello from C++";  // строка для передачи
    DWORD dwSize = sizeof(data);   // размер этой строки
    DWORD dwBytesWritten;    // тут будет количество собственно переданных байт

   // while (1)
    //{
        ReadCOM();
    //}
    return 0;
}

