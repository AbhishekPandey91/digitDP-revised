// https://leetcode.com/problems/count-of-integers/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    using ll = long long;
    string s;
    ll dp[23][2][230];
    const int mod = 1e9 + 7;

    ll dfs(int i, int tight, int sum, int min_sum, int max_sum)
    {
        if (i == s.size())
        {
            if (sum >= min_sum && sum <= max_sum)
                return 1;
            else
                return 0;
        }
        if (dp[i][tight][sum] != -1)
            return dp[i][tight][sum];
        ll res = 0;
        int limit = tight ? s[i] - '0' : 9;
        for (int d = 0; d <= limit; d++)
        {
            int newSum = sum + d;
            if (newSum <= max_sum)
            {
                res = (res + dfs(i + 1, tight && (d == limit), newSum, min_sum, max_sum)) % mod;
            }
        }
        return dp[i][tight][sum] = res % mod;
    }

    ll solve(string &n, int min_sum, int max_sum)
    {
        s = n;
        memset(dp, -1, sizeof(dp));
        return (dfs(0, 1, 0, min_sum, max_sum)) % mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        int sum = 0;
        int v = 0;
        for (char ch : num1)
        {
            sum += (ch - '0');
        }
        if (sum >= min_sum && sum <= max_sum)
            v = 1;
        return ((solve(num2, min_sum, max_sum) - solve(num1, min_sum, max_sum) + v) % mod + mod) % mod;
    }
};