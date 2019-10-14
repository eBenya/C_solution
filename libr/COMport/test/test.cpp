// com_port_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <tchar.h>
#include "scanCOMport/scanCOMport.h"

#define LENNAME 7

//#include <Windows.h>
//#include <iostream>
//using namespace std;
//
//HANDLE hSerial;
//
//void ReadCOM()
//{
//      DWORD iSize;
//      char sReceivedChar;
//      while (true)
//      {
//            ReadFile(hSerial, &sReceivedChar, 1, &iSize, 0);
//			if (iSize > 0)
//				cout << sReceivedChar;
//      }
//}
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	LPCTSTR sPortName = L"COM1";  
//
//	hSerial = ::CreateFile(sPortName,GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
//	if(hSerial==INVALID_HANDLE_VALUE)
//	{
//		if(GetLastError()==ERROR_FILE_NOT_FOUND)
//		{
//			cout << "serial port does not exist.\n";
//		}
//		cout << "some other error occurred.\n";
//	}
//
//
//	DCB dcbSerialParams = {0};
//	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
//	if (!GetCommState(hSerial, &dcbSerialParams))
//	{
//		cout << "getting state error\n";
//	}
//	dcbSerialParams.BaudRate=CBR_9600;
//	dcbSerialParams.ByteSize=8;
//	dcbSerialParams.StopBits=ONESTOPBIT;
//	dcbSerialParams.Parity=NOPARITY;
//	if(!SetCommState(hSerial, &dcbSerialParams))
//	{
//		cout << "error setting serial port state\n";
//	}
//	char data[] = "Hello from C++";
//	DWORD dwSize = sizeof(data);
//	DWORD dwBytesWritten;
//	LPOVERLAPPED ov;
//
//	BOOL iRet = WriteFile (hSerial,data,dwSize,&dwBytesWritten ,NULL);
//
//	cout << dwSize << " Bytes in string. " << dwBytesWritten << " Bytes sended. " << endl;
//
//	while(1)
//	{
//		ReadCOM();
//	}
//	return 0;
//}
//

//int scanPort( char *namePortBuff, int leghtWord); //читаем COM порты с реестра

int main() {

	HKEY rKey = 0;
	TCHAR buffer[100][LENNAME] = { 0 };
	unsigned long len = scanPort(&buffer[0][0], LENNAME);

	//¬ывести доступные порты на экран
	if (len > 0) {

		len = len / LENNAME;
		printf("len = %d\n", len);
		for (size_t i = 0; i < len; i++){
			printf("name port - ");
			//int j = 0;
			//while ( buffer[i][j] != '\0') {
				_tprintf(TEXT("%s\n"), buffer[i]/*[j++]*/);
			//}
			putchar('\n');
		}
	}

	/////////////////////////////////////
	//–јбота с COM портом
	////////////////////////////////////
	HANDLE h1Ser;					//сюда будет возвращатьс€ ошибка или дескриптор файла
	LPCTSTR sPortName = buffer[2];	// акой порт хотим открыть из доступного списка

	_tprintf(TEXT("%s\n"), sPortName);

	h1Ser = CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == h1Ser){
		if (ERROR_FILE_NOT_FOUND == GetLastError()){
			printf("error. File not found");
		}
		printf("error. Invalid handle value\n");
		//return;
	}
	printf("file is open");


	
	
	CloseHandle(h1Ser);
}


///*
//*—канирует раздел реестра и возвращает число считанных символов.
//*јргумент namePortBuff - указатель на двумерный массив с длинной строки lenghtWord.
//*rKey - указатель на переменную, получающую описатель открытого раздела.
//*
//*Scans the reestr key and return number of read character.
//*Argument namePortBuff - is point on 2 dimensional array with the lenght of the string - lenghtWord.
//*rKey - point to variable that recives the handles of an open partition.
//*/
//int scanPort(HKEY rKey, char *namePortBuff, int lenghtWord) 
//{
//	//открываем раздел реестра
//	int r = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"HARDWARE\\DEVICEMAP\\SERIALCOMM\\", 0, KEY_QUERY_VALUE, &rKey);
//	if (r == ERROR_SUCCESS) 
//	{
//		printf("r = %d\n", r);
//											//не включа€ нулевой байт
//		unsigned long valueParam = 0;		// число параметров раздела 
//		unsigned long maxValueNameLen = 0;	// размер самого длинного названи€ параметра данного раздела
//		unsigned long maxValueLen = 0;		//размер самого длинного значени€ среди тех, которые имеют параметры данного раздела
//		//получаем информацию поразделу реестра 
//		RegQueryInfoKey(rKey, NULL, NULL, NULL, NULL, NULL,NULL, &valueParam, &maxValueNameLen, &maxValueLen, NULL, NULL);
//		maxValueLen++;
//		printf("value - %d\nvalueName - %d\nvalueLen - %d\n", valueParam, maxValueNameLen, maxValueLen);
//
//		//¬ыделить пам€ть под названи€ доступных COM-ов
//		//namePortBuff = (char*)malloc((maxValueLen + 1) * sizeof(TCHAR) * 7);
//
//		TCHAR *bufferName = nullptr;			//буфер, который получает название параметра.
//		char *bufferData = nullptr;			//буфер, который получает данные параметра.
//		bufferName = (TCHAR*)malloc(++maxValueNameLen * sizeof(TCHAR));
//		bufferData = (char*)malloc((maxValueLen + 1) * sizeof(char));		
//
//		if (!bufferName || !bufferData) {
//			printf("error.");
//			free(bufferData);
//			free(bufferName);
//			RegCloseKey(rKey);
//			return -1;
//		}
//		printf("sizeof(dataName) = %d\n", sizeof(bufferName));
//		printf("sizeof(dataBuf) = %d\n", sizeof(bufferData));
//		
//		unsigned long len = valueParam * lenghtWord * sizeof(char);
//		//namePortBuff = (char*)malloc(len);
//		printf("namePort - %d\n", namePortBuff);
//
//		unsigned long nameLen =	NULL, dataLen = NULL, type = NULL;
//
//		for (size_t i = 0; i < valueParam; i++){
//			nameLen = maxValueNameLen;
//			dataLen = maxValueLen;
//
//			r = RegEnumValue(rKey, i, bufferName, &nameLen, NULL, &type, (LPBYTE)bufferData, &dataLen);
//			
//			printf("nameLen = %d\t", nameLen);
//			_tprintf(TEXT("bufferName = %s\n"), bufferName);
//			printf("dataLen = %d\t", dataLen);
//			_tprintf(TEXT("bufferData = %s\n\n"), bufferData);
//			int j = 0;
//			for (int j = 0; j < lenghtWord; j+=2)
//			{
//				*(namePortBuff + i*lenghtWord + j/2) = bufferData[j];
//			}
//		}
//
//		free(bufferData);
//		free(bufferName);
//		RegCloseKey(rKey);
//		return len;
//	}
//	else
//	{
//		printf("error. code: %d\n", r);
//		RegCloseKey(rKey);
//		return -1;
//	}	
//}