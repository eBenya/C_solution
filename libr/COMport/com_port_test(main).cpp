// com_port_test.cpp : Defines the entry point for the console application.
//

#include <windows.h>
#include <tchar.h>
#include "scanCOMport.h"

#define LENNAME 7



int main() {

	TCHAR buffer[100][LENNAME] = { 0 };
	unsigned long len = scanPort(&buffer[0][0], LENNAME);
	if (len > 0) {

		len = len / LENNAME;
		printf("len = %d\n", len);
		for (size_t i = 0; i < len; i++){
			printf("name port - ");
				_tprintf(TEXT("%s\n"), buffer[i]);
			putchar('\n');
		}
	}
}