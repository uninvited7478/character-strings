#include <bits/stdc++.h> 
using namespace std;

void longestCommonSubstringNaive(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    s1 = 'x' + s1 + 'x';
    s2 = 'y' + s2 + 'y';
    int maxiSubstringLength = 0;
    int posS1 = -1;
    int posS2 = -1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i] != s2[j])
            {
                continue;
            }
            int currSubstrLen = 1;
            while (s1[i + currSubstrLen] == s2[j + currSubstrLen])
            {
                currSubstrLen++;
            }
            if (currSubstrLen > maxiSubstringLength)
            {
                maxiSubstringLength = currSubstrLen;
                posS1 = i - 1;
                posS2 = j - 1;
            }
        }
    }
    if (maxiSubstringLength > 0)
    {
        //                                                 + 1 -> sentinel 
        cout << "Longest Common Substring: " << s1.substr(posS1 + 1, maxiSubstringLength) << '\n';
        cout << "Longest Common Substring length: " << maxiSubstringLength << '\n';
        cout << "In s1 on position: " << posS1 << '\n';
        cout << "In s2 on position: " << posS2 << '\n';
    }
    else
    {
        cout << "No common substrings found\n";
    }
}

int main()
{
    string s1 = "AAABBA";
    string s2 = "ABAABBAAA";

    longestCommonSubstringNaive(s1, s2);

    return 0;
}