#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
bool mycomp(pair<int,int>& a,pair<int,int>& b){
    return a.first<b.first;
}
vector<int> order(vector<int> &A, vector<int> &B) {
    int n=A.size();
    vector<int> vv;
    if (n==1){
        vv.push_back(A[0]);
        return vv;
    }
    vector<pair<int,int> > hh(n);
    int i;
    for (i=0;i<n;i++){
        hh[i].first=A[i];
        hh[i].second=B[i];
    }
    sort(hh.begin(),hh.end(),mycomp);
    vector<int> gg(n);
    vector<int> kk(n,0);
    int r,j,fl;
    for (i=0;i<n;i++){
    	fl=hh[i].second;
    	j=0;
		while (fl>=0 && j<n){
			if (kk[j]==0)
				fl--;
			j++;
		}
		j--;
        gg[j]=hh[i].first;
        kk[j]=1;
    }
return gg;
}
//5 3 2 6 1 4
//0 1 2 0 3 2
int main(){
	int n,i;
	//cin>>n;
	n=6;
	vector<int> a(n);
	vector<int> b(n);
    a[0]=5;
    b[0]=0;
    a[1]=3;
    b[1]=1;
    a[2]=2;
    b[2]=2;
    a[3]=6;
    b[3]=0;
    a[4]=1;
    b[4]=3;
    a[5]=4;
    b[5]=2;
	vector<int> sol;
	sol=order(a,b);
	cout<<endl;
	for (i=0;i<n;i++)
	cout<<sol[i]<<" ";
	return 0;
}
