#include<iostream>
#include<vector>
using namespace std;
int main(){
    int i,j,k,pp,n,ans=0;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    vector<int> dp(n,1);
    for(i=1;i<n;i++){
        for(j=i-1;j>=0;j--){
            if (a[j]<=a[i]){
            dp[i]=max(dp[i],1+dp[j]);
            }
        }
        ans=max(ans,dp[i]);
    }
    for(i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl<<ans;
    return 0;
}
/*
9
10 22 9 33 21 50 52 60 30  ---6
*/