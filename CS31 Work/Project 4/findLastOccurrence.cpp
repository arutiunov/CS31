#include <iostream>
#include <string>
#include <cassert>

using namespace std;


int findLastOccurrence ( const string array [ ], int n, string target);

int main()
{
    string a [5] = {"alpha", "beta", "gamma", "delta", "beta"};
    string b [5] = {"alpha", "beta", "delta", "delta", "epsilon"};
    string c [1] = {" "};
    
    assert (findLastOccurrence ( a, 5, "beta") == 4);
    assert (findLastOccurrence (b, 5, "delta") == 3);
    assert (findLastOccurrence(b, 5,  "gamma") == -1);
    assert (findLastOccurrence(c, 1, "a") == -1);


}


int findLastOccurrence ( const string array [ ], int n, string target)
{
    int b = -1;

    if (n <= 0)
        return -1;

    for (int k = 0; k < n; k++)
    {
        if (array[k] == target)
            b = k;
    }
    return b;
}
