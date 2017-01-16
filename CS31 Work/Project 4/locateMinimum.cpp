#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int locateMinimum( const string array[ ], int n );



int main()
{
    string a [5] = {"aaa", "aa", "a", "aaaa", "a"};
    string b [7] = {"aaa", "bbb", "a", "bbbb", "a", "bb", "a"};


    assert (locateMinimum (b, 7) == 2);

  //  assert (locateMinimum (a, 2) == 0);
 //   assert (locateMinimum(a, 3) == 0);

 //   assert (locateMinimum(b, 7) == 2);


}


int locateMinimum( const string array[ ], int n )
{
    int minimum = 0;
    string minimum_value = array[0];

    if (n <= 0)
        return -1;

    for (int k = 1; k < n; k++)
    {

        if (array[k] < minimum_value)
        {
            minimum_value = array[k];
            minimum = k;
        }
    }
    return minimum;
}
