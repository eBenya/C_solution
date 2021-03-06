// COMport.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
/*#include <windows.h>
#include <iostream>
using namespace std;

int scanPort(LPCTSTR portName);

HANDLE hSerial;

int main(int argc, char* argv[])
{

	char numberOfCOM_port[200] = { 0 };
	//LPCTSTR portName = L"COM1";
	char pName[6] = { "COM" };
	int n = 1;
	
	//int accesPortBuff[50] = { 0 };
	//for(int i = 0; i < 50; i++)
	
	while (n != 15) {
		if (n > 9) {
			pName[3] = '0' + n / 10;
			pName[4] = '0' + n % 10;
		}
		else
			pName[3] = '0' + n;
		int i = 0;
		while (pName[i] != '\0') {
			printf("%c", pName[i++]);
		}
		putchar('\n');

		LPCTSTR portName = (LPCTSTR)pName;
		if (scanPort(portName)) {
			printf("Ports is ends or is esepsen\n");
			return 0;
		}

		n++;
	}
	putchar('\n');
}

int scanPort(LPCTSTR portName) {

	hSerial = CreateFile(portName, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//Проверка на ошибку выполнения CreateFile
	if (hSerial == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) { //GetLastError - return last error code value.
			cout << "serial port does not exist.\n";
			return 2;
		}
		cout << "some other error occurred. Code: " << hSerial << endl;
		return 1;
	}
	else {
		return 0;
	}

}*/

#include <windows.h>
#include <tchar.h>
void ShowCOMPorts()
{
	int r = 0;
	HKEY hkey = NULL;
	//Открываем раздел реестра, в котором хранится иинформация о COM портах
	r = RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM\\"), 0, KEY_READ, &hkey);
	if (r != ERROR_SUCCESS)
		return;

	unsigned long CountValues = 0, MaxValueNameLen = 0, MaxValueLen = 0;
	//Получаем информацию об открытом разделе реестра
	RegQueryInfoKey(hkey, NULL, NULL, NULL, NULL, NULL, NULL, &CountValues, &MaxValueNameLen, &MaxValueLen, NULL, NULL);
	++MaxValueNameLen;
	//Выделяем память
	TCHAR *bufferName = NULL, *bufferData = NULL;
	bufferName = (TCHAR*)malloc(MaxValueNameLen * sizeof(TCHAR));
	if (!bufferName)
	{
		RegCloseKey(hkey);
		return;
	}
	bufferData = (TCHAR*)malloc((MaxValueLen + 1) * sizeof(TCHAR));
	if (!bufferData)
	{
		free(bufferName);
		RegCloseKey(hkey);
		return;
	}

	unsigned long NameLen, type, DataLen;
	//Цикл перебора параметров раздела реестра
	for (unsigned int i = 0; i < CountValues; i++)
	{
		NameLen = MaxValueNameLen;
		DataLen = MaxValueLen;
		r = RegEnumValue(hkey, i, bufferName, &NameLen, NULL, &type, (LPBYTE)bufferData, &DataLen);
		if ((r != ERROR_SUCCESS) || (type != REG_SZ))
			continue;

		_tprintf(TEXT("%s\n"), bufferData);
	}
	//Освобождаем память
	free(bufferName);
	free(bufferData);
	//Закрываем раздел реестра
	RegCloseKey(hkey);
}
int main()
{
	ShowCOMPorts();
	return 0;
}