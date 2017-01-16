#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int flipAround( string array[ ], int  n );


int main()
{
    string a [5] = {"a", "b", "c", "d", "e"};
    string b [10] = {"z", "x", "a", "a", "a", "z", "e", "f", "eight", "z"};

    flipAround (a, 5);
    flipAround (b, 10);

	/*
    for (int i = 0; i < 5; i++)
    {
        cerr << a[i] << endl;
    }



    for (int k = 0; k < 10; k++)
    {
        cerr << b[k] << endl;
    }
	*/


}


int flipAround( string array[ ], int  n )
{
    string temporary;
    int amount_of_flips = 0;
    amount_of_flips = n / 2;

    for (int k = 0; k <= amount_of_flips; k++)
    {
        temporary = array[k];
        array[k] = array[n-1-k];
        array [n-1-k] = temporary;
    }

    // cout << amount_of_flips << endl;
    return amount_of_flips;
}
