#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#define endl "\n"


int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t=1;
    // cin>>t;

    while(t--){

        int n;
        string s;
        cin>>n>>s;
        int cnt=0;
        int fre[4]={0};
        for(int i=0;i<n;i++){
            fre[0] = fre[1]=fre[2]=fre[3]=0;
            for(int j=i;j<n;j++){
                if(s[j]=='A')
                    fre[0]++;
                if(s[j]=='T')
                    fre[1]++;
                if(s[j]=='G')
                    fre[2]++;
                if(s[j]=='C')
                    fre[3]++;
                if(fre[0]==fre[1] and fre[2]==fre[3])
                    cnt++;
            }
        }

        cout<<cnt<<endl;

   }

    return 0;
}