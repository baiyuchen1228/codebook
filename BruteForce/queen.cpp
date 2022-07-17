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

int n = 4;
int cnt;
bool col[5],diag1[5],diag2[5];
void search(int y){
    if(y == n){
        cnt ++;
    }
    else{
        REP(x,0,n-1){
            if(col[x] || diag1[y+x] || diag2[x-y+n-1])continue;
            col[x] = diag1[y+x] = diag2[x-y+n-1] = 1;
            search(y+1);
            col[x] = diag1[y+x] = diag2[x-y+n-1] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    search(0);
    cout << cnt << '\n';

    return 0;
}