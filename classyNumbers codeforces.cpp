// Count the numbers which contains no more than 3 non-zero digits in given range.

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

string s;
ll dp[20][2][4];

ll dfs(int i,int tight, int curNonZeroDigits){
    if(i==s.size()) return 1;
    if(dp[i][tight][curNonZeroDigits]!=-1) return dp[i][tight][curNonZeroDigits];

    int limit= tight ? s[i]-'0' :9;
    ll res=0;
    for(int d=0;d<=limit;d++){
        int newCurNonZeroDigits= curNonZeroDigits + (d!=0);
        if(newCurNonZeroDigits<=3){
            res +=dfs(i+1,tight && (d==limit) , newCurNonZeroDigits);
        }
    }
    return dp[i][tight][curNonZeroDigits]=res;
}

ll solve (ll n){
    if(n<0) return 0;
    s=to_string(n);
    memset(dp,-1,sizeof(dp));
    return dfs(0,1,0);
}

int main(){
    ll l=34; ll r=1e18;
    cout<<solve(r)-solve(l-1);
    return 0;
}