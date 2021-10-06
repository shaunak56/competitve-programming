#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string t1, string t2) {
    int n = t1.size(), m = t2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<=m ; j++) {
            int temp = 0;
            if (t1[i-1] == t2[j-1]) {
                temp = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max({temp, dp[i][j-1], dp[i-1][j]});
        }
    }
    return dp[n][m];
}

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int T = 1;
    // cin >> T;

    for(int t = 1; t <= T; t++) {
        string t1, t2;
        cin >> t1 >> t2;
        cout << longestCommonSubsequence(t1, t2) << endl;
    }

    return 0;
}
