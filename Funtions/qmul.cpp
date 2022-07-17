#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll qmul(ll x,ll y,ll m){
    ll res = 0;
    for(;y > 0;y >>= 1,x = (x+x) % m){
        if(y & 1)res = (res+x) % m;
    }
    return res;
}
int main(){
    

    return 0;
}