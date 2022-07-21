#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Function to print the number
void catalan(int n)
{
    ll cat_ = 1;
    // For the first number
    cout << cat_ << " "; // C(0)
    // Iterate till N
    for (ll i = 1; i <=n; i++)
    {
        // Calculate the number
        // and print it
        cat_ *= (4 * i - 2);
        cat_ /= (i + 1);
        cout << cat_ << " ";
    }
}
// Driver code
int main()
{
    int n = 5;
    // Function call
    catalan(n);
    return 0;
}
// there are Cn binary trees of n nodes
// there are Cn−1 rooted trees of n nodes