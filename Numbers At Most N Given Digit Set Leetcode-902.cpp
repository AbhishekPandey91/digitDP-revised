// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string s;
    int dp[10][2][2];

    int dfs(int i, int tight, int started, vector<string> &digits)
    {
        if (i == s.size())
            return started;
        if (dp[i][tight][started] != -1)
            return dp[i][tight][started];
        int res = 0;
        int limit = tight ? s[i] - '0' : 9;

        if (!started)
        {
            for (int x = 0; x < digits.size(); x++)
            {
                int d = digits[x][0] - '0';
                if (d > limit)
                    continue;
                if (d == 0)
                {
                    res += dfs(i + 1, tight && (d == limit), 0, digits);
                }
                else
                {
                    res += dfs(i + 1, tight && (d == limit), 1, digits);
                }
            }
        }
        else
        {
            for (int x = 0; x < digits.size(); x++)
            {
                if (digits[x] == "0")
                    continue;
                int d = digits[x][0] - '0';
                if (d <= limit)
                {
                    res += dfs(i + 1, tight && (d == limit), 1, digits);
                }
            }
        }
        return dp[i][tight][started] = res;
    }

    int solve(int n, vector<string> &digits)
    {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dfs(0, 1, 0, digits);
    }

    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        digits.push_back("0");
        return solve(n, digits);
    }
};