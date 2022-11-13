#include<iostream>
#include<vector>
using namespace std;
vector<int> dp(100,-1);
int lonsub(vector<int> a,int en){
     int i,j,k,pp,n,ans=0;
     n=a.size();
     dp[0]=1;
     if (dp[en]!=-1)
     return dp[en];
     dp[en]=1;
     for(i=0;i<en;i++){
        dp[i]=lonsub(a,i); 
         if (a[en]>=a[i])
         dp[en]=max(dp[en],dp[i] +1);
     }return dp[en];
}
int main(){
    int i,j,k,pp,n,ans=0;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    j=lonsub(a,n-1);
    for(i=0;i<=n-1;i++)
        j=max(j,dp[i]);
    cout<<j;
    return 0;
}
/*
9
10 22 9 333 211 50 52 60 30  ---6
*/