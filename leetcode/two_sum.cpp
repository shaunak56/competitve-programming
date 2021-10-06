#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {    
    map<int, vector<int> > m;
    for(int i=0;i<nums.size();i++)
        m[nums[i]].push_back(i);
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int i=0,j=nums.size()-1;
    while(i<j){
        int sum = nums[i]+nums[j];
        if(sum<target){
            i++;
        }
        else if(sum>target){
            j--;
        }
        else{
            ans.push_back(m[nums[i]][0]);
            if(nums[i]==nums[j])
                ans.push_back(m[nums[j]][1]);
            else
                ans.push_back(m[nums[j]][0]);
            
            return ans;
        }
        
    }
    return ans;
}


int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int T=1;
    // cin>>T;

    for(int t=1;t<=T;t++){
        int n, target;
        cin >> n >> target;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<int> ans = twoSum(v, target);
        cout << ans[0] <<" "<< ans[1] << endl;
    }

    return 0;
}
