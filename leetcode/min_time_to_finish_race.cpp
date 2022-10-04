#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/* 
Problem: https://leetcode.com/problems/minimum-time-to-finish-the-race/

*/

/*
Solution:
Basic idea is to use dynamic programming approach that is similar to rod cutting problem.

1. Count minimum time required for each lap to complete, by any tire. Store this data in minMap.
2. Then for nth lap find the best possible route by following formula. 
   dp[i] = min(dp[j] + dp[i-j] + changeTime) for each j less than i. Store this in array dp
3. Answer will be stored in dp[n]
*/
int minimumFinishTime(vector<vector<int>> tires, int changeTime, int numLaps) {
    ll n = tires.size();
    map<ll, ll> minMap;
    for (ll i=0; i<n; i++) {
        ll t = tires[i][0], sum = tires[i][0];
        ll j=1;
        while (true) {
            if (minMap[j])
                minMap[j] = min(minMap[j], sum);
            else
                minMap[j] = sum;
            j++;
            if (t > changeTime)
                break;
            t *= tires[i][1];
            sum += t;
        }
    }
    vector<ll> dp(numLaps+1);
    dp[1] = minMap[1];
    // cout<<1<<" "<<dp[1]<<" "<<minMap[1]<<endl;
    for (int i=2; i<=numLaps; i++) {
        dp[i] = minMap[i] ? minMap[i] : INT_MAX;
        for (int j=1; j<i; j++) {
            dp[i] = min(dp[i], dp[j]+dp[i-j]+changeTime);
        }
        // cout<< i<<" "<<dp[i]<<" "<<minMap[i]<<endl;
    }
    return (int)dp[numLaps];
}

int main() {
    cout << minimumFinishTime({{1, 10}, {2, 2}, {3, 4}}, 6, 5) ; // expected correct answer: 25
}
