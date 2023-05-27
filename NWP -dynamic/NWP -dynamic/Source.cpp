#include <bits/stdc++.h> 
using namespace std;

void longestCommonSubstringDP(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxiSubstringLength = 0;
    int posS1 = -1;
    int posS2 = -1;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (s1[i] == s2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                if (dp[i + 1][j + 1] > maxiSubstringLength)
                {
                    maxiSubstringLength = dp[i + 1][j + 1];
                    posS1 = i - maxiSubstringLength + 1;
                    posS2 = j - maxiSubstringLength + 1;
                }
            }
            else
            {
                dp[i + 1][j + 1] = 0;
            }
        }
    }
    if (maxiSubstringLength > 0)
    {
        cout << "Longest Common Substring: " << s1.substr(posS1, maxiSubstringLength) << '\n';
        cout << "Longest Common Substring length: " << maxiSubstringLength << '\n';
        cout << "In s1 on position: " << posS1 << '\n';
        cout << "In s2 on position: " << posS2 << '\n';
    }
    else {
        cout << "No common substrings found\n";
    }
}

int main()
{
    string s1 = "AAABBA";
    string s2 = "ABAABBAAA";

    longestCommonSubstringDP(s1, s2);

    return 0;
}