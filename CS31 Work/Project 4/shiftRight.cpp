#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int shiftRight( string array[ ], int n, int amount, string placeholderToFillEmpties );



int main()
{
    string placeholderToFillEmpties;

    string a [10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};


    shiftRight (a, 10, 4, "$");

    for (int i = 0; i < 10; i++)
        cout << a[i] << endl;


}

int shiftRight( string array[ ], int n, int amount, string placeholderToFillEmpties )
{
    int counter = 0;
    int k = 0;
    int index_last_placeholder = 0;

    if (amount < 0)
        return -1;
    if (amount > n)
        return -1;

    for (k = n - 1; k >= amount; k--) // works backwards to ensure array elements not lost before shifted
    {
        array[k] = array[k - amount];
        counter++; // tracks how many array elements are left after the shift
    }

    index_last_placeholder = amount; // for clarification

    for (int i = 0; i < index_last_placeholder; i++) // replaces the shifted elements in array
    {
        array[i] = placeholderToFillEmpties;
    }
    cerr << counter << endl;
    return counter;
}
