#include <cstdlib>
#include <iostream>

int binsearch(int x, int v[], int n);

int main(){
    
    int hide = 67;
    int mass[10] = {0, 20, 23, 34, 54, 65, 66, 75, 87, 99};
    int max = 10;
    
    printf("%d\n", binsearch(hide, mass, max));
     
    system("PAUSE");
    return EXIT_SUCCESS;
}

int binsearch(int x, int v[], int n){
    
    int low, high, mid;

    mid = -1;
    low = 0;
    high = n - 1;
    
    while ( (low <= high)) {
                  
        mid = (low + high) / 2;
                
        if (x < v[mid]) high = mid - 1;
           else low = mid + 1 ;
        }
    
    if ( x != v[mid]) mid = -1;    
    return mid; /* совпадения нет */
    }
