#include<iostream>
#include<vector>
using namespace std;
int main(){ //tabulation method
vector<int> a={10,20,30,20,30}; 
int p=1e9,i,j,k,n=a.size()-1; //n=3
int dp[5][5];
for(i=n-1;i>=0;i--){
    for(j=n-1;j>=0;j--){
        dp[i][j]=-1;
        if(i==j)
        dp[i][j]=0;
    }
}
for(i=n-1;i>=0;i--){ // O(n^3)
    for(j=i+1;j<=n-1;j++){
        p=1e9;
        for(k=i+1;k<=j;k++){
            p=min(p,dp[i][k-1]+dp[k][j] + (a[i]*a[k]*a[j+1]));
        }
        dp[i][j]=p;
    }
}
for(i=0;i<n;i++){
    for(j=0;j<n;j++)
        cout<<dp[i][j]<<"  ";
    cout<<endl;
}
return 0;
}