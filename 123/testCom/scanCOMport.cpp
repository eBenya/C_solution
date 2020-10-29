#include "scanCOMport.h"

/*
*Сканирует раздел реестра и возвращает число считанных символов.
*Аргумент namePortBuff - указатель на двумерный массив с длинной строки lenghtWord.
*rKey - указатель на переменную, получающую описатель открытого раздела.
*
*Scans the reestr key and return number of read character.
*Argument namePortBuff - is point on 2 dimensional array with the lenght of the string - lenghtWord.
*rKey - point to variable that recives the handles of an open partition.
*/

int scanPort(HKEY rKey, char *namePortBuff, int lenghtWord) 
{
	//открываем раздел реестра
	int r = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"HARDWARE\\DEVICEMAP\\SERIALCOMM\\", 0, KEY_QUERY_VALUE, &rKey);
	if (r == ERROR_SUCCESS) 
	{
		printf("r = %d\n", r);
											//не включая нулевой байт
		unsigned long valueParam = 0;		// число параметров раздела 
		unsigned long maxValueNameLen = 0;	// размер самого длинного названия параметра данного раздела
		unsigned long maxValueLen = 0;		//размер самого длинного значения среди тех, которые имеют параметры данного раздела
		//получаем информацию поразделу реестра 
		RegQueryInfoKey(rKey, NULL, NULL, NULL, NULL, NULL,NULL, &valueParam, &maxValueNameLen, &maxValueLen, NULL, NULL);
		maxValueLen++;
		printf("value - %d\nvalueName - %d\nvalueLen - %d\n", valueParam, maxValueNameLen, maxValueLen);

		//Выделить память под названия доступных COM-ов
		//namePortBuff = (char*)malloc((maxValueLen + 1) * sizeof(TCHAR) * 7);

		TCHAR *bufferName = nullptr;			//буфер, который получает название параметра.
		char *bufferData = nullptr;			//буфер, который получает данные параметра.
		bufferName = (TCHAR*)malloc(++maxValueNameLen * sizeof(TCHAR));
		bufferData = (char*)malloc((maxValueLen + 1) * sizeof(char));		

		if (!bufferName || !bufferData) {
			printf("error.");
			free(bufferData);
			free(bufferName);
			RegCloseKey(rKey);
			return -1;
		}
		printf("sizeof(dataName) = %d\n", sizeof(bufferName));
		printf("sizeof(dataBuf) = %d\n", sizeof(bufferData));
		
		unsigned long len = valueParam * lenghtWord * sizeof(char);
		//namePortBuff = (char*)malloc(len);
		printf("namePort - %d\n", namePortBuff);

		unsigned long nameLen =	NULL, dataLen = NULL, type = NULL;

		for (size_t i = 0; i < valueParam; i++){
			nameLen = maxValueNameLen;
			dataLen = maxValueLen;

			r = RegEnumValue(rKey, i, bufferName, &nameLen, NULL, &type, (LPBYTE)bufferData, &dataLen);
			
			printf("nameLen = %d\t", nameLen);
			_tprintf(TEXT("bufferName = %s\n"), bufferName);
			printf("dataLen = %d\t", dataLen);
			_tprintf(TEXT("bufferData = %s\n\n"), bufferData);
			int j = 0;
			for (int j = 0; j < lenghtWord; j+=2)
			{
				*(namePortBuff + i*lenghtWord + j/2) = bufferData[j];
			}
		}

		free(bufferData);
		free(bufferName);
		RegCloseKey(rKey);
		return len;
	}
	else
	{
		printf("error. code: %d\n", r);
		RegCloseKey(rKey);
		return -1;
	}	
}