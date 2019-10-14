#pragma once

#ifndef _WINDOWS_H_
	#include <windows.h>
#endif

#ifndef _TCHAR_H_
	#include <tchar.h>
#endif

#ifndef LENNAME 
	#define LENNAME 7
#endif
//#ifndef _TCHAR_H_
//	#include <iostream>
//#endif



/*
*—канирует раздел реестра и возвращает число считанных символов.
*јргумент namePortBuff - указатель на двумерный массив с длинной строки lenghtWord.
* аждый следующий COM пишетс€ в новую строку!
*rKey - указатель на переменную, получающую описатель открытого раздела.
*¬озвращает целое число байт!!! int типа.
*
*Scans the reestr key and return number of read character.
*Argument namePortBuff - is point on 2 dimensional array with the lenght of the string - lenghtWord.
*Each of the following COMport - writes is next line
*rKey - point to variable that recives the handles of an open partition.
*return count of  byte!!! of the int type
*/

int scanPort(TCHAR *namePortBuff, int lenghtWord);


/*
*ќткрывает указанный COM порт дл€ работы. ѕри успешном выполнение возвращает 0.
*≈сли файл небыл открыт возвращает 1, если файл отсутствует возвращает 2.
*HANDLE hSer - указатель переменной, куда будет занесен дескриптор файла.
*LPCSTR COM - название COM порта, который вы хотите открыть
*
*Open select COM port for operation. if successful return 0.
*If file is not open - return 1, if the file is missing - return 2.
*HANDLE hSer - variable pointer, where the file descriptor will be placed
*LPCSTR COM - name COM port, when you want to open.
*/

int openCOMport(HANDLE *hSer, LPCTSTR COM);