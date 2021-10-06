#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0, curr = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i])
            curr++;
        else
            curr = 0;
        ans = max(ans, curr);
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int T = 1;
    // cin >> T;

    for(int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << findMaxConsecutiveOnes(v) << endl;
    }

    return 0;
}
