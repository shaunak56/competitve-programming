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
    
        int n;
        cin>>n;

        int a[2*n+1]={0}, b[2*n+1]={0};
        int vis[2*n+1] = {0};
        bool flag=1;
        
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            if(x!=-1 and y!=-1){
                a[x]=y;
                b[y]=x;
            }
            if(x!=-1)
                vis[x]++;
            else
                vis[y]++;
            if(x!=-1 and vis[x]>1){
                cout<<"No"<<endl;
                return 0;
            }
            if(y!=-1 and vis[y]>1){
                cout<<"No"<<endl;
                return 0;
            }
        }

        for(int k=1;k<=2*n;k++){
            if(a[k]==0 && b[k]==0){
                bool flag2=0;
                for(int i=1;i<=2*n;i++){
                    int j,diff=i;
                    for(j=k;j<=2*n;j++){
                        if((a[j]==j+diff and (b[j+diff]==0 or b[j+diff]==j)) or (j-diff >0 and b[j]==j-diff and (a[j-diff]==j or a[j-diff]==0)) or (j-diff >0 and b[j]==0 and a[j-diff]==0) or (a[j]==0 and b[j+diff]==0))    
                            continue;
                        break;
                    }
                    if(j==2*n+1)
                        flag2=1;
                }
                if(!flag2)
                    flag=0;
            }
            else if(a[k]){
                int diff = a[k]-k;
                // if(diff<=0 or a[k]>2*n){
                //     cout<<"No"<<endl;
                //     return 0;
                // }
                for(int j=k;j<=a[k];j++){
                    // cout<<k<<" "<<j<<endl;
                    if((a[j]==j+diff and (b[j+diff]==0 or b[j+diff]==j)) or (j-diff >0 and b[j]==j-diff and (a[j-diff]==j or a[j-diff]==0)) or (j-diff >0 and b[j]==0 and a[j-diff]==0) or (a[j]==0 and b[j+diff]==0))    
                    {
                        continue;
                    }
                    flag=0;
                }
            }
            else{
                int diff = k-b[k];
                // if(diff<=0){
                //     cout<<"No"<<endl;
                //     return 0;
                // }
                for(int j=b[k];j<=k;j++){
                    if((a[j]==j+diff and (b[j+diff]==0 or b[j+diff]==j)) or (j-diff >0 and b[j]==j-diff and (a[j-diff]==j or a[j-diff]==0)) or (j-diff >0 and b[j]==0 and a[j-diff]==0) or (a[j]==0 and b[j+diff]==0)){
                        continue;
                    }
                    flag=0;
                }
            }
        }
        if(flag)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }

    return 0;
}

/*
    1 4
    2 5
    3 6

    1 2 3 4 5 6
    

*/