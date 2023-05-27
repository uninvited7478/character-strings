#include <bits/stdc++.h> 
using namespace std;

string lcsRek(string text1, string text2)
{
    if (text1 == "" || text2 == "") return "";
    if (text1.back() == text2.back())
    {
        return lcsRek(text1.substr(0, text1.size() - 1), text2.substr(0, text2.size() - 1)) + text1.back();
    }
    string res1 = lcsRek(text1.substr(0, text1.size() - 1), text2);
    string res2 = lcsRek(text1, text2.substr(0, text2.size() - 1));
    if (res1.size() >= res2.size())
    {
        return res1;
    }
    return res2;
}

int main()
{
    string firstText = "abacabbd";
    string secondText = "xaadcbdd";

    cout << lcsRek(firstText, secondText) << '\n';
    return 0;
}