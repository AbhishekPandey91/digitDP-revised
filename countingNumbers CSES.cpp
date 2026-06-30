//  Your task is to count the number of integers between a and b where no two adjacent digits are the same. {https://cses.fi/alon/task/2220} , {0 <=a,b<=1e18}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

string s;
ll dp[20][2][2][11];

ll dfs(int i,int tight,int isStarted ,int prev){
    if(i==s.size()) return 1;
    if(dp[i][tight][isStarted][prev+1]!=-1) return dp[i][tight][isStarted][prev+1];

    ll res=0;
    int limit=tight ? s[i]-'0' :9;

    if(isStarted){
        for(int d=0;d<=limit;d++){
            if(prev!=d) res+=dfs(i+1,tight && (d==limit) , isStarted , d);
        }
    }
    else{
        for(int d=0;d<=limit;d++){
            if(d==0){
                res+=dfs(i+1,tight && (d==limit) , isStarted, -1); // prev=-1 , bcz we have not yet started to fill
            }
            else{
                res+=dfs(i+1,tight && (d==limit) , 1, d); 
            }
        }
    }
    return dp[i][tight][isStarted][prev+1]=res;
}

ll solve(ll n){
    if(n<0) return 0;
    s=to_string(n);
    memset(dp,-1,sizeof(dp));
    return dfs(0,1,0,-1);
}

int main(){
    ll l,r;
    cin>>l>>r;
    cout<<solve(r)-solve(l-1);
    return 0;
}