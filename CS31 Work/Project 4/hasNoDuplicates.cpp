#include <iostream>
#include <string>
#include <cassert>

using namespace std;


bool hasNoDuplicates ( const string array[ ], int n);

int main()
{
    string a [6] = {"alpha", "beta", "gamma", "delta", "epsilon"};
    string b [1] = {" "};
    string c [6] = {"alpha", "beta", "alpha", "beta", "gamma", "alpha"};
    string d [0];

    assert ( hasNoDuplicates (a, 5));
    assert ( hasNoDuplicates (b, 1));
    assert (! hasNoDuplicates (c, 6));
    assert ( hasNoDuplicates(d, 0));



}


bool hasNoDuplicates (const string array [ ], int n)
{
    bool result = true;
    if (n < 0)
        return false;

    for (int k = 0; k < n; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            if (array [k] == array [i])
                result = false;
        }
    }
    return result;
}
