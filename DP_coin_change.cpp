#include<iostream>
#include<vector>
using namespace std;
// memoization (space=n*v) (time=n*v)
vector<vector<int>> dpm(100,vector<int> (100,-1));
int coinchng(int n,vector<int> a){

int  k=a.size();
    cout<<n<<"  "<<k<<endl;
if (n==0)
    return 1;
if (k==0)
    return 0;
if (n<0)
    return 0;
if (dpm[n][k]!=-1)
    return dpm[n][k];
int j,i,pp,co=0;
vector<int> b;
for (j=1;j<k;j++)
    b.push_back(a[j]);
pp=coinchng(n-a[0],a);
co+=pp;
if (n-a[0] >=0)
dpm[n-a[0]][k]=pp;
dpm[n][k-1]=coinchng(n,b);
co+=  dpm[n][k-1]; 
dpm[n][k]=co;
return co;    
}

int main(){
    cout<<"Hello";
    // int i,n;
    // cin>>n;
    // vector<int> a={1,2,3};
    // int dd=coinchng(n,a);
    // cout<<endl;
    // for (i=0;i<=n;i++)
    // cout<<dpm[i][a.size()]<<" ";
    // cout<<endl<<endl<<dd;
    return 0;
}

/*
//its tabulation with space optimization (space=v)
vector<int> dp(1000,-1);
int main(){
int i,j,pp,n;
cin>>n; 
vector<int> a={1,2,3};
dp[0]=1;
for (i=1;i<=n;i++)
dp[i]=0;
for (i=0;i<a.size();i++){
for (j=0;j<=n;j++){
if (j-a[i]<0)
pp=0;
else
pp=dp[j-a[i]];
dp[j]+=pp;
}
}
for (i=0;i<=n;i++)
    cout<<dp[i]<<" ";
return 0;
}
*/