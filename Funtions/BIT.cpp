#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll bit[100005],n,num[100005];

int lowbit(int x){
    return x& -x;
}

ll query(int i){ //prefix to i
    ll sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

void modify(int le,int ri,int x){ // a[le,ri] += x
    if(le <= 0 || le > ri) return;
    bit[le] += x;
    if(ri < n) bit[ri+1] -= x;
}

void add(int i,int x){ // a[i] += x
    while(i <= n){
        bit[i] += x;
        i += lowbit(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    memset(bit,0,sizeof(bit));
    for(int i = 1;i <= n;i++){
        cin >> num[i];
        add(i,num[i]);
    }
    return 0;
}