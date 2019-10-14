/*���������� 2.6. �������� ������� setbits(x, p, n, y),
������������ �������� x, � ������� n �����, ������� � p-� �������,
�������� �� n ������ �������� �� y ��������� ���� �� ����������).*/

#include <cstdlib>
#include <iostream>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main(){
    
    unsigned int bin1 = 23193; // 0101 1010 1001 1001
    int pos = 7;
    int count = 2;
    unsigned int bin2 = 54012; // 1101 0010 1111 1100
    
    
    
    printf("%d\n",setbits(bin1, pos, count, bin2) );
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y){
         
         unsigned int yy = (((y >> (p-n)) & ~(~0 << n)) << (p-n));
         unsigned int xx = x & ~(~(~0 << n) << (p-n));
         
         return yy|xx;
         }
