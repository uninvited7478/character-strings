# character-strings
The maximum specific prefix includes all characters
string s except for the last one. Maximum suffix
valid includes all characters in the string except
first:
max Pref(s) = s[0 : |s| - 1] max Suff(s) = s[1 : |s| ]
If a given string s has a prefix-suffix of length k, then
a period is an integer d such that the following condition holds:
s[0 : k] = s[d : n]
The maximum prefix-suffix of the string s is the longest prefix and
the suffix of this string that are equal to each other.
