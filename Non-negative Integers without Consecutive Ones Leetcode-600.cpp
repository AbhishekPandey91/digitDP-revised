// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC -> 30*2*2*3*2;
    // SC -> 30*2*2*3;

    string s;
    string toBinary(int n)
    {
        if (n == 0)
            return "0";
        string k;
        while (n)
        {
            k += (n & 1) + '0';
            n >>= 1;
        }
        reverse(k.begin(), k.end());
        return k;
    }

    int dfs(int i, int tight, int started, int prev, vector<vector<vector<vector<int>>>> &dp)
    {
        if (i == s.size())
            return 1;
        if (dp[i][tight][started][prev + 1] != -1)
            return dp[i][tight][started][prev + 1];
        int res = 0;
        int limit = tight ? s[i] - '0' : 1;
        if (started)
        {
            for (int d = 0; d <= limit; d++)
            {
                if (!(prev == 1 && d == 1))
                    res += dfs(i + 1, tight && (d == limit), 1, d, dp);
            }
        }
        else
        {
            for (int d = 0; d <= limit; d++)
            {
                if (d == 0)
                    res += dfs(i + 1, tight && (d == limit), 0, prev, dp);
                else
                    res += dfs(i + 1, tight && (d == limit), 1, d, dp);
            }
        }
        return dp[i][tight][started][prev + 1] = res;
    }

    int solve(int n)
    {
        s = toBinary(n);
        int size = s.size();
        vector<vector<vector<vector<int>>>> dp(size + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(3, -1))));
        return dfs(0, 1, 0, -1, dp);
    }

    int findIntegers(int n)
    {
        return solve(n);
    }
};