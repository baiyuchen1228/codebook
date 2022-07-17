#include <bits/stdc++.h>
#define F First
#define S Second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x = 5328; // 00000000000000000001010011010000
    cout << __builtin_clz(x) << '\n'; //19 前面幾個0
    cout << __builtin_ctz(x) << '\n'; // 4 後面幾個0
    cout << __builtin_popcount(x) << '\n'; // 幾個1
    x |= (1 << k) // k改成1
    x &= ~(1 << k); //k改成0


    for(int i = 31;i >= 0;i--){
        if(x & (1<<i))cout << '1';
        else cout << '0';
    }
    return 0;
}