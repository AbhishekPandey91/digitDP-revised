// https://leetcode.com/problems/numbers-with-repeated-digits/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[11][2][2][1 << 10];
    string s;
    int dfs(int pos, int tight, int started, int mask)
    {
        if (pos == s.size())
        {
            return 1;
        }
        if (dp[pos][tight][started][mask] != -1)
            return dp[pos][tight][started][mask];

        int limit = tight ? s[pos] - '0' : 9;
        int ans = 0;

        for (int d = 0; d <= limit; d++)
        {
            int ntight = tight && (d == limit);

            if (!started)
            {
                if (d == 0)
                {
                    ans += dfs(pos + 1, ntight, 0, mask);
                }
                else
                {
                    ans += dfs(pos + 1, ntight, 1, mask | (1 << d));
                }
            }
            else
            {
                if (mask & (1 << d))  continue;
                ans += dfs(pos + 1, ntight, 1, mask | (1 << d));
            }
        }

        return dp[pos][tight][started][mask] = ans;
    }

    int numDupDigitsAtMostN(int n)
    {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));

        int distinct = dfs(0, 1, 0, 0);
        return n - (distinct - 1);
    }
};