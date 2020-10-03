#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 998244353
#define endl "\n"


int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int T=1;
    // cin>>T;

    for(int t=1;t<=T;t++){
        int x,y;
        cin>>x>>y;

        cout<<(x+y)/2<<" "<<(x-y)/2<<endl;


    }

    return 0;
}
