#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize );


int main()
{

    string a [5] = {"a", "b", "c", "d", "a"};
    string b [5] = {"e", "e", "e", "d", "b"};
    string c [5] = {"e", "e", "b", "d", "z"};
    string d [3] = {"a", "b", "a"};
    string e [2] = {"e", "f"};


    string resultingString[20];
    int size = 20;



    unionWithNoDuplicates(a, 5, b, 5, resultingString, size);

    for (int k = 0; k < size; k++)
        cout << resultingString[k] << endl;

    cout << "---" << endl;

    unionWithNoDuplicates(a, 5, c, 5, resultingString, size);

    for (int j = 0; j < size; j++)
        cout << resultingString[j] << endl;


    unionWithNoDuplicates(b, 5, c, 5, resultingString, size);
    for (int k = 0; k < size; k++)
        cout << resultingString[k] << endl;


}

void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize)
{
    int index = 0;
    resultingSize = 0;

    for (int j = 0; j < n1; j++) // keeping one element constant
    {
        int duplicates = 0;
        for (int k = 0; k <= index; k++) // cycling through resultingString array from left to right
        {
            if (array1[j] == resultingString[k]) // if there is a duplicate found
                duplicates++; // increase the count of duplicates
        }
        if (duplicates == 0) // if there are no duplicates between array1 and resultingString
        {
            resultingString[index] = array1[j]; // place element from array1 into resultingString
            index++; // move index of resultingString over by 1
            resultingSize++;
        }
    }

    for (int l = 0; l < n2; l++)
    {
        int duplicates = 0;
        for (int m = 0; m <= index; m++ )
        {
            if (array2[l] == resultingString[m])
                duplicates++;
        }
        if (duplicates == 0)
        {
            resultingString[index] = array2[l];
            index++;
            resultingSize++;
        }

    }
    cerr << resultingSize << endl;
}
