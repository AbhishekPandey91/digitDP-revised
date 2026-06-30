// Calculate the numbers whose sum of digits is Prime.{ 0<=l,r<=1e8};

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

string s;
ll dp[10][2][90];
bool Prime[90];

void calculatePrime(){
    memset(Prime,true,sizeof(Prime));
    Prime[0]=Prime[1]=false;
    for(int i=2;i*i<90;i++){
        if(Prime[i]){
            for(int j=i*i; j<90; j+=i){
                Prime[j]=false;
            }
        }
    }
}

ll dfs(int i,int tight,int curSum){
    if(i==s.size()) {
        if(Prime[curSum]) return 1;
        else return 0;
    }
    if(dp[i][tight][curSum]!=-1) return dp[i][tight][curSum];
    ll res=0;
    int limit= tight ? s[i]-'0' : 9;
    for(int d=0;d<=limit;d++){
        res+= dfs(i+1,tight && (d==limit) , curSum+d);
    }
    return dp[i][tight][curSum] = res;
}

ll solve (ll n){
    if(n<0) return 0;
    s=to_string(n);
    memset(dp,-1,sizeof(dp));
    return dfs(0,1,0);
}

int main(){
    ll l=34; ll r=1e8;
    calculatePrime();
    cout<<solve(r)-solve(l-1);
    return 0;
}
