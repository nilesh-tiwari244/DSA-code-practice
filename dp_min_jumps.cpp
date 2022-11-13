#include<iostream>
#include<vector>
using namespace std;

vector<int> dp(100,-1);
int minjump(vector<int> a,int st) {
    int n,i,j;
    n=a.size();
    if (st==n-1)
        {dp[n-1]=0;
        return 0;
        }
    if (a[st]<=0)
        {dp[st]=-2;
        return -2;
        }
    if(dp[st]!=-1)
        return dp[st];
    int mini=1e9;
    for(i=1;i<=a[st];i++){
        {if(st+i==n-1)
            {dp[st+i]=1;
            return 1;
            }
        dp[st+i]=minjump(a,st+i);
        if (dp[st+i]>0)
         mini=min(dp[st+i],mini);
        }
    }
    if(mini==1e9)
        {dp[st]=-2;
        return -2;
        }
    else{
        dp[st]=mini+1;
        return (mini+1);
    }
}
int main(){
int i;
vector<int> a={3,0,2,0,8,9,2,6,7,6,8,9};
cout<<minjump(a,0)<<endl;
 for(i=0;i<=a.size();i++)
     cout<<dp[i]<<"  ";
return 0;
}