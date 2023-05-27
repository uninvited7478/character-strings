#include <bits/stdc++.h> 
using namespace std;

int prefSufNaive(string s)
{
    int n = s.size();
    int i = n - 1;
    while (i > 0)
    {
        if (s.substr(0, i) == s.substr(n - i, i))
        {
            break;
        }
        i--;
    }
    return i;
}

int prefSufMP(string s)
{
    int n = s.size();
    vector<int> pi(n + 1);
    pi[0] = -1;
    int b = -1;
    for (int i = 1; i <= n; ++i)
    {
        while (b > -1 && s[b] != s[i - 1])
        {
            b = pi[b];
        }
        b++;
        pi[i] = b;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "ABACABAB";

    cout << prefSufNaive(s) << '\n';
    cout << prefSufMP(s) << '\n';

    return 0;
}