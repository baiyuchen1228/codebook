#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll GCD(ll a, ll b){
    return b ? GCD(b, a % b) : a;
}
int main(){
    return 0;
}