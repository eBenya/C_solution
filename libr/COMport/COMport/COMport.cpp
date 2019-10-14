#include "COMport.h"


int scanPort(TCHAR *namePortBuff, int lenghtWord)
{
	HKEY rKey;
	//открываем раздел реестра
	int r = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		L"HARDWARE\\DEVICEMAP\\SERIALCOMM\\",
		0,
		KEY_QUERY_VALUE,
		&rKey);

	if (r == ERROR_SUCCESS)
	{
		//printf("r = %d\n", r);
											//не включая нулевой байт
		unsigned long valueParam = 0;		// число параметров раздела 
		unsigned long maxValueNameLen = 0;	// размер самого длинного названия параметра данного раздела
		unsigned long maxValueLen = 0;		//размер самого длинного значения среди тех, которые имеют параметры данного раздела
		//получаем информацию поразделу реестра 
		RegQueryInfoKey(rKey,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&valueParam,
			&maxValueNameLen,
			&maxValueLen,
			nullptr,
			nullptr);

		maxValueLen++;
		//printf("value - %d\nvalueName - %d\nvalueLen - %d\n", valueParam, maxValueNameLen, maxValueLen);

		//Выделить память под названия доступных COM-ов
		//namePortBuff = (char*)malloc((maxValueLen + 1) * sizeof(TCHAR) * 7);

		TCHAR *bufferName = nullptr;			//буфер, который получает название параметра.
		TCHAR *bufferData = nullptr;			//буфер, который получает данные параметра.
		bufferName = (TCHAR*)malloc(++maxValueNameLen * sizeof(TCHAR));
		bufferData = (TCHAR*)malloc((maxValueLen + 1) * sizeof(TCHAR));

		if (!bufferName || !bufferData) {
			//printf("error.");
			free(bufferData);
			free(bufferName);
			RegCloseKey(rKey);
			return -1;
		}
		//printf("sizeof(dataName) = %d\n", sizeof(bufferName));
		//printf("sizeof(dataBuf) = %d\n", sizeof(bufferData));

		unsigned long len = valueParam * lenghtWord * sizeof(char);
		//namePortBuff = (char*)malloc(len);
		//printf("namePort - %d\n", namePortBuff);

		unsigned long nameLen = NULL, dataLen = NULL, type = NULL;

		for (size_t i = 0; i < valueParam; i++) {
			nameLen = maxValueNameLen;
			dataLen = maxValueLen;

			r = RegEnumValue(rKey,
				i,
				bufferName,
				&nameLen,
				nullptr,
				&type,
				(LPBYTE)bufferData,
				&dataLen);

			/*printf("nameLen = %d\t", nameLen);
			_tprintf(TEXT("bufferName = %s\n"), bufferName);
			printf("dataLen = %d\t", dataLen);
			_tprintf(TEXT("bufferData = %s\n\n"), bufferData);*/
			for (int j = 0; j < lenghtWord; j++)
			{
				*(namePortBuff + i * lenghtWord + j) = bufferData[j];
			}
		}

		free(bufferData);
		free(bufferName);
		RegCloseKey(rKey);
		return len;
	}
	else
	{
		//printf("error. code: %d\n", r);
		RegCloseKey(rKey);
		return -1;
	}
}

int openCOMport(HANDLE *hSer, LPCTSTR COM) {

	*hSer = CreateFile(COM,
		GENERIC_READ | GENERIC_WRITE,
		NULL,
		nullptr,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		nullptr);

	if (INVALID_HANDLE_VALUE == *hSer) {
		if (ERROR_FILE_NOT_FOUND == GetLastError()) {
			//MessageBox(NULL, TEXT("Невозможно открыть последовательный порт. Файл не найден."), TEXT("Error"), MB_OK);
			//printf("error. File not found. Code: %d", ERROR_FILE_NOT_FOUND);
			return ERROR_FILE_NOT_FOUND;
		}
		//MessageBox(NULL, TEXT("Невозможно открыть последовательный порт"), TEXT("Error"), MB_OK);
		//printf("error. Invalid handle value\n");
		return 1;
	}
	//printf("file is open");
	return 0;
}




/*
*Остальные функции и структуры winAPI и так достаточно дружелюбны и просты в использовании
*	typedef struct _DCB					//структура с основными параметрами настройки COM
*	typedef struct _COMMTIMEOUTS
*
*	GetCommState(h1Ser, &settingCOM);	//получить параметры структуры DCB
*	SetCommState(h1Ser, &settingCOM);	//Установить параметры структуры DCB
*
*	ReadFile(...);						//чтение данных
*	WriteFile(...);						//передача данных
*	CloseHandle(h1Ser);					//закрыть порт
*/