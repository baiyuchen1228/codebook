#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define start first.second
#define endd first.first
#define weight second
vector<pair<pair<lld,lld>,lld> > v1;
int bi_se(lld s, lld t,lld goal){
    if(s==t){//need rest
        if(goal <= v1[s].endd) return s-1; // or <
        else return s;
    }
    lld mid = (s+t)/2;
    if(goal <= v1[mid].endd) return bi_se(s,mid,goal);
    else return bi_se(mid + 1,t,goal);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    lld n;
    cin >> n;//activities
    lld s,t,w;
    v1.push_back({{0,0},0});
    for(lld i = 0;i < n;i++){
        cin >> s >> t >> w;
        v1.push_back(make_pair(make_pair(t,s),w));
    }
    vector<lld> dp;
    dp.push_back(0);
    sort(v1.begin(),v1.end());
    for(lld i = 1;i <= n;i++){
        lld tmp = bi_se(0,i - 1,v1[i].start);
        lld ch = dp[tmp] + v1[i].weight;
        dp.push_back(max(ch,dp[i-1]));
    }
    cout << dp[n] << "\n";
    return 0;
}
