#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/* 
Problem: https://leetcode.com/problems/minimum-time-to-complete-trips/

*/

/*
Solution:
Things to note:
1. The worst case answer would be same as totalTrips*(minimum trip time amongst all the buses)
2. We can run multiple buses independently at the same time, so we need to complete as many trips as possible concurrently

Basic idea is to use binary search over the answer. We can find the answer in following way,
- lower limit : 0, upper limit : totalTrips*(minimum trip time amongst all the buses)
- for any time "mid" between lower and upper limit,
- number of trips completed by a bus with trip time t will be mid/t
- trips completed in mid time t1 = sum(mid/t for t in time[])
- if t1 >= totalTrips, we can look for lower mid time
- else we can look for higher mid time
*/
long long minimumTime(vector<int> time, int totalTrips) {
        sort(time.begin(), time.end());
        long long ans = 0, n = time.size();
        long long s = 1, e = (long long)time[0]*totalTrips;
        long long mid;
        while(s<e) {
            mid = (s+e)/2;
            long long temp = 0;
            for(int i=0; i<n; i++) {
                if (time[i]<=mid){
                    temp += mid/time[i];
                }
                else
                    break;
            }
            if (temp < totalTrips) {
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }

int main() {
    cout << minimumTime({1, 2, 3}, 5) ; // expected correct answer: 3
}
