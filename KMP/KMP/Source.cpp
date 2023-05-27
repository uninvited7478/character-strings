#include <bits/stdc++.h> 
using namespace std;

void KMP(string pattern, string text)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; ++i)
    {
        while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];
        if (pattern[i] == pattern[j]) j++;
        pi[i] = j;
    }
    for (int i = 0, j = 0; i < n; ++i)
    {
        while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == m) {
            cout << i - j + 1 << '\n';
            j = pi[j - 1];
        }
    }
}

int main()
{
    string text = "abaabababbbaabababaaa";
    string pattern = "aba";

    KMP(pattern, text);

    return 0;
}