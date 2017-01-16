#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[4] = { 0, 1, 2, 3 };
    int* ptr = arr;
    
    *ptr = arr[ 1 ];            // set arr[0] to 1
    
    *(ptr + 1) = arr[0] * 10; // set arr[1] to 10 (bug:*ptr + 1)
    
    ptr += 2;
    
    ptr[0] = arr[1] * 10;
    
    ptr[1] = 1000;
    
    ptr = arr + 4; // shits pointer to the end of the array
    
    while (ptr > arr)
    {
        ptr--;
        cout << " " << *ptr;    // print values
    }
    cout << endl;
    return( 0 );
    
}
