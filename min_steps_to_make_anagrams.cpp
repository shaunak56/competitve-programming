#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/* 
Problem: https://leetcode.com/contest/weekly-contest-282/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/

*/

/*
Solution:
Things to note:
- We can only add the characters to the strings, and not remove them.
- anagram means both the strings should have equal frequency of all the characters

Therefore, minimum steps required would be the difference in frequency of each character present in both the strings
*/

int minSteps(string s, string t) {
    int f1[26] = {0}, f2[26] = {0};
    for (char c: s) {
        f1[c-'a']++;
    }
    for (char c: t) {
        f2[c-'a']++;
    }
    int ans = 0;
    for (int i=0; i<26; i++){
        ans += abs(f1[i]-f2[i]);
    }
    return ans;
}

int main() {
    cout << minSteps("leetcode", "coats") ; // expected correct answer: 7
}
