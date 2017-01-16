#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// declaration of functions

int locateMinimum( const string array[ ], int n );

int findLastOccurrence ( const string array [ ], int n, string target);

int flipAround( string array[ ], int  n );

bool hasNoDuplicates ( const string array[ ], int n);

void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize );

int shiftRight( string array[ ], int n, int amount, string placeholderToFillEmpties );

bool isInIncreasingOrder( const string array[ ], int  n );




int main()
{
    
    // test cases for locateMinimum
    
    string a [5] = {"aaa", "aa", "a", "aaaa", "a"};
    string b [7] = {"aaa", "bbb", "aa", "bbbb", "a", "bb", "a"};
    
    assert (locateMinimum(a, 5) == 2);
    assert (locateMinimum (b, 7) == 4);
 
    
    // test cases for findLastOccurence
    
    string c [5] = {"alpha", "beta", "gamma", "delta", "beta"};
    string d [5] = {"alpha", "beta", "delta", "delta", "epsilon"};
    string e [1] = {" "};
    
    assert (findLastOccurrence ( c, 5, "beta") == 4);
    assert (findLastOccurrence (d, 5, "delta") == 3);
    assert (findLastOccurrence(d, 5,  "gamma") == -1);
    assert (findLastOccurrence(e, 1, "a") == -1);
    
    // test cases for flipAround
    
    string f [5] = {"a", "b", "c", "d", "e"};
    string g [10] = {"z", "x", "a", "a", "a", "z", "e", "f", "eight", "z"};
    
    assert (flipAround (f, 5) == 2);
    assert (flipAround (g, 10) == 5);
    assert (flipAround (f, 0) == 0);
    
    
    // test cases for hasNoDuplicates
    
    string h [6] = {"alpha", "beta", "gamma", "delta", "epsilon"};
    string i [1] = {" "};
    string j [6] = {"alpha", "beta", "alpha", "beta", "gamma", "alpha"};
    string k [0];
    
    assert ( hasNoDuplicates (h, 5));
    assert ( hasNoDuplicates (i, 1));
    assert (! hasNoDuplicates (j, 6));
    assert ( hasNoDuplicates(k, 0));
    
    // test cases for unionWithNoDuplicates
    
    string l [5] = {"a", "b", "a", "d", "a"};
    string m [5] = {"e", "e", "e", "d", "b"};
    string n [5] = {"e", "e", "b", "d", "z"};
    string o [3] = {"a", "b", "c"};
    string p [2] = {"e", "f"};
    
    string resultingString[20];
    int resultingSize = 0;
    
    
    unionWithNoDuplicates(l, 5, m, 5, resultingString, resultingSize);
    
    unionWithNoDuplicates(m, 5, n, 5, resultingString, resultingSize);
    
    
    unionWithNoDuplicates(l, 5, n, 5, resultingString, resultingSize);
    
    
    unionWithNoDuplicates(o, 3, p, 2, resultingString, resultingSize);
    
    
    unionWithNoDuplicates(l, 5, m, -1, resultingString, resultingSize);
    
    // test cases for shiftRight
    
    string q [10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    
    shiftRight (q, 10, 4, "$");
    
    
    // test cases for isInIncreasingOrder
    
    string t [6] = {"xy", "xy", "x", "x", "y", "xy"};
    string r [5] = {"hi", "cat", "hell", "hello", "heroes"};
    string s [4] = {"art", "bart", "cart", "dart"};
    
    assert (! isInIncreasingOrder(t, 6));
    assert (! isInIncreasingOrder (r, 5 ));
    assert ( isInIncreasingOrder (s, 4 ));
    
    
}

// function definition for locateMinimum
int locateMinimum( const string array[ ], int n )
{
    int minimum = 0;
    string minimum_value = array[0];
    
    if (n <= 0) // can't have size of array be equal to or less than 0
        return -1;
    
    for (int k = 1; k < n; k++) // cycling through aray
    {
        
        if (array[k] < minimum_value)// if we find an element smaller than the current minimum vallue
        {
            minimum_value = array[k]; // change minimum value to new element
            minimum = k; // change the index of minimum value
        }
    }
    return minimum;
}

// function definion of findLastOccurence
int findLastOccurrence ( const string array [ ], int n, string target)
{
    int b = -1; // default setting of last occurence if element not found
    
    if (n <= 0) // can't have n equal to or less than 0
        return -1;
    
    for (int k = 0; k < n; k++) // cycle through the array
    {
        if (array[k] == target) // if element of array matches target string
            b = k; // change index of target strign
    }
    return b;
}

// function definition of flipAround
int flipAround( string array[ ], int  n )
{
    string temporary;
    int amount_of_flips = 0;
    amount_of_flips = n / 2; // determines how many flips must be made
    
    for (int k = 0; k <= amount_of_flips; k++) // cycles through array
    {
        temporary = array[k]; // assign left hand array value to temporary variable
        array[k] = array[n-1-k]; // assign right hand array value to left hand array
        array [n-1-k] = temporary; // asign left hand array value to right hand
    }
    
    return amount_of_flips; // return amount of flips
}

// function definition of hasNoDuplicates
bool hasNoDuplicates (const string array [ ], int n)
{
    bool result = true; // assume result is true
    
    if (n < 0) // false if array size less than 0
        return false;
    
    for (int k = 0; k < n; k++) // keeping one array element constant
    {
        for (int i = k + 1; i < n; i++) // cycles through the rest of the array
        {
            if (array [k] == array [i]) // if there are duplicates return false
                result = false;
        }
    }
    return result; // return result
}

// function definition for unionWithNoDuplicates
void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize)
{
    if ((n1 <= 0) || (n2 <= 0)) // if either of array sizes equal to or less than 0
    {
        resultingSize = -1;
        return;
    }
    
    int index = 0; // keeping track of resulting array's size
    resultingSize = 0; // returning the valu eof resulting array's size
    
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
    
    for (int l = 0; l < n2; l++) // same as above but for array2
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
}


// function definition ofr shiftRight
int shiftRight( string array[ ], int n, int amount, string placeholderToFillEmpties )
{
    int counter = 0;
    int k = 0;
    int index_last_placeholder = 0;
    
    if (n < 0)
        return -1;
    if (amount < 0) // can't have amount parameter be 0
        return -1;
    if (amount > n) // cannot exceed n
        return -1;
    
    for (k = n - 1; k >= amount; k--) // works backwards to ensure array elements not lost before shifted
    {
        array[k] = array[k - amount];
        counter++; // tracks how many array elements are left after the shift
    }
    
    index_last_placeholder = amount; // for clarity
    
    for (int i = 0; i < index_last_placeholder; i++) // replaces the shifted elements in array
    {
        array[i] = placeholderToFillEmpties;
    }
    return counter;
}


// function definition for isIncreasingOrder
bool isInIncreasingOrder( const string array[ ], int  n )
{
    if (n < 0)
        return false;
    
    if (n == 0 || n == 1) // always true
        return true;
    
    for (int i = 0; i < n - 1; i++) // cycling through array
    {
        if (array[i] < array[i + 1]) // if element is smaller than one before it
            continue;
        else // return false
            return false;
    }
    
    return true;
}
