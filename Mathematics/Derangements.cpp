// Permutation such that no element appears in its original position
#include <bits/stdc++.h>
using namespace std;
 
using namespace std;
 
int countDer(int n)
{
    // base case
    if (n == 1 or n == 2) return n - 1;

    // Variable for just storing
    // previous values
    int a = 0;
    int b = 1;
 
    // using above recursive formula
    for (int i = 3; i <= n; ++i) {
        int cur = (i - 1) * (a + b);
        a = b;
        b = cur;
    }
 
    // Return result for n
    return b;
}
 
// Driver Code
int main()
{
    cout << "Count of Derangements is " << countDer(4);
    return 0;
}