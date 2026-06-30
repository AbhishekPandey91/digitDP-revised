#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
ll dp[20][2][20];

ll dfs(int i,int tight,ll cnt){
    if(i==s.size()) return cnt;
    if(dp[i][tight][cnt]!=-1) return dp[i][tight][cnt];
    int limit = tight ? s[i]-'0' : 9;
    ll res=0;
    for(int d=0;d<=limit;d++){
        res+=dfs(i+1,tight&&(d==limit) , cnt+(d==3));
    }
    return dp[i][tight][cnt]=res;
}

ll solve(ll n){
    if(n<0) return 0;
    s=to_string(n);
    memset(dp,-1,sizeof(dp));
    return dfs(0,1,0);
}
int main(){
    ll l=34; ll r=1e18;
    cout<< solve(r)-solve(l-1);
    return 0;
}