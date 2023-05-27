#include <vector> 
#include <iostream> 
using namespace std;

vector<int> piTable(string s)
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
    return pi;
}

void mp(string text, string patt, vector<int>& pi)
{
    bool found = false;
    int j = 0;
    for (int i = 0; i < text.size(); ++i)
    {
        while (j > -1 && patt[j] != text[i])
        {
            j = pi[j];
        }
        j += 1;
        if (j == patt.size())
        {
            found = true;
            cout << i - j + 1 << '\n';
            j = pi[j];
        }
    }
    if (!found)
    {
        cout << -1 << '\n';
    }
}

int main()
{
    string p, s;

    cin >> p >> s;

    vector<int> pi = piTable(p);
    mp(s, p, pi);

    return 0;
}