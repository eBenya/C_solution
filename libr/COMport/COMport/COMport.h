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
*��������� ������ ������� � ���������� ����� ��������� ��������.
*�������� namePortBuff - ��������� �� ��������� ������ � ������� ������ lenghtWord.
*������ ��������� COM ������� � ����� ������!
*rKey - ��������� �� ����������, ���������� ��������� ��������� �������.
*���������� ����� ����� ����!!! int ����.
*
*Scans the reestr key and return number of read character.
*Argument namePortBuff - is point on 2 dimensional array with the lenght of the string - lenghtWord.
*Each of the following COMport - writes is next line
*rKey - point to variable that recives the handles of an open partition.
*return count of  byte!!! of the int type
*/

int scanPort(TCHAR *namePortBuff, int lenghtWord);


/*
*��������� ��������� COM ���� ��� ������. ��� �������� ���������� ���������� 0.
*���� ���� ����� ������ ���������� 1, ���� ���� ����������� ���������� 2.
*HANDLE hSer - ��������� ����������, ���� ����� ������� ���������� �����.
*LPCSTR COM - �������� COM �����, ������� �� ������ �������
*
*Open select COM port for operation. if successful return 0.
*If file is not open - return 1, if the file is missing - return 2.
*HANDLE hSer - variable pointer, where the file descriptor will be placed
*LPCSTR COM - name COM port, when you want to open.
*/

int openCOMport(HANDLE *hSer, LPCTSTR COM);