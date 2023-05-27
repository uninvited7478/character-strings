#include <bits/stdc++.h> 
using namespace std;

void boyerMoore(string pattern, string text, char alphabetStart, char alphabetEnd)
{
    vector<int> lastPos(alphabetEnd - alphabetStart, -1);

    for (int i = 0; i < pattern.size(); ++i)
    {
        lastPos[pattern[i] - alphabetStart] = i;
    }

    int posFounded = -1;
    int i = 0;
    while (i <= text.size() - pattern.size())
    {
        int j = pattern.size() - 1;
        while (j >= 0 && pattern[j] == text[i + j])
        {
            j--;
        }
        if (j >= 0)
        {
            i += max(1, j - lastPos[text[i + j] - alphabetStart]);
        }
        else
        {
            posFounded = i;
            cout << posFounded << '\n';
            i++;
        }
    }
}

int main()
{
    string p = "ABC";
    string s = "AAABBBCCCABCAAAABBBCABCBACBABCABC";

    boyerMoore(p, s, 'A', 'Z');

    return 0;
}