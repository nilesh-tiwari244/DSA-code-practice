#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > dp(100000,vector<int> (3,-1));
int kee(vector<vector<int> > &A,int st,int en,int co){
    int n=A.size();
    if (dp[st][co]!=-1)
    return dp[st][co];
    if (n-1==st){
    	dp[st][co]=A[st][co];
    	cout<<endl<<st<<" "<<en<<" "<<co<<" "<<" = "<<dp[st][co]<<endl;
        return A[st][co];
    }
     cout<<endl<<st<<" "<<en<<" "<<co<<" "<<" = "<<dp[st][co]<<endl;
    int i,s=0;
    int g=INT_MAX;
    for (i=0;i<3;i++){
        if (i!=co)
        g=min(kee(A,st+1,en,i),g);
    }
    dp[st][co]=g+A[st][co];
     cout<<endl<<st<<" "<<co<<" "<<" = "<<dp[st][co]<<endl;
    return g+A[st][co];
}
int solve(vector<vector<int> > &A) {
    int n=A.size();
    if (n==1){
        return min(A[0][0],min(A[0][1],A[0][2]));
    }
    int i,g=INT_MAX;
    for (i=0;i<3;i++){
        g=min(kee(A,0,n-1,i),g);
    }
    cout<<"hello";
    return g;
}
int main(){
	int i,j,n,k;
	cin>>n;
	vector<vector<int> > A(n);
	vector<int> pp(3);
	for (i=0;i<n;i++){
		pp.clear();
		for (j=0;j<3;j++){
			cin>>k;
			pp[j]=k;
		}
		A[i]=pp;
	}
	cout<<endl<<solve(A)<<endl;
	for (i=0;i<n;i++){
		cout<<dp[0][0]<<" "<<dp[0][1]<<"  "<<dp[0][2];
	}
	return 0;
}
/*

2
1 2 3
10 11 12

*/

