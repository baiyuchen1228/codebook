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

int n;
vi subset;
void search(int k){
    if(k == n + 1){
        for(auto x:subset){
        cout << x << ' ';
        }
        cout << '\n';
    }
    else{
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
        search(k + 1);
    }
}

vi permutation;
bool chosen[10];
void search2(){
    if(permutation.size() == n){
        for(auto x:permutation){
        cout << x << ' ';
        }
        cout << '\n';
    }
    else{
        REP(i,1,n){
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search2();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    REP(i,1,n){
        permutation.PB(i);
    }
    do{
        for(auto x:permutation){
        cout << x << ' ';
        }
        cout << '\n';
    }while(next_permutation(permutation.begin(), permutation.end()));
    // search2();
    return 0;
}