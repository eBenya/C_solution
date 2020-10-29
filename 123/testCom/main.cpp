#include <iostream>
#include "scanCOMport"


#define LENNAME 7

int main() {

	HKEY rKey = 0;
	char buffer[100][LENNAME] = { 0 };
	unsigned long len = scanPort(rKey, &buffer[0][0], LENNAME);
	if (len > 0) {
		
		len = len / LENNAME;
		printf("len = %d\n", len);
		for (size_t i = 0; i < len; i++){
			printf("name port - ");
			int j = 0;
			while ( buffer[i][j] != '\0') {
				putchar(buffer[i][j++]);
			}
			putchar('\n');
		}
	}
}
