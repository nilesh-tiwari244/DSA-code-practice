#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> dp(100,vector<int> (100,-1));
int knapsack(vector<vector<int>> a,int s,int st){
    if (s<=0)
    return 0;
    int n,i,j,v1=0,v2,mini=0;
    n=a.size();
    if (st==n)
    return 0;
    if (dp[s][st]!=-1)
    return dp[s][st];
    i=st;
    if (s-a[i][0] >= 0)
    v1=a[i][1] + knapsack(a,s-a[i][0],st+1);
    v2=knapsack(a,s,st+1);
    mini=max(v1,max(v2,mini));
    dp[s][st]=mini;
    return mini;
}
int main(){
    int i,j,n,s,z1,z2,sol;
    cin>>n>>s;
    vector<vector<int>> a;
    for(i=0;i<n;i++){
    cin>>z1>>z2;
    a.push_back({z1,z2});}
    sol=knapsack(a,s,0);
    cout<<endl<<endl<<sol;
    return 0;
}


3 60
15 60
30 100
40 150

3 50
1 60
1 100
1 150

*/