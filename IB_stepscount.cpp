#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;
int coverPoints(vector<int> &A, vector<int> &B) {
int n,i,p1=0,p2=0,s=0,tr;
n=A.size();
for(i=0;i<n-1;i++)
{p1=abs(A[i+1]-A[i]);
p2=abs(B[i+1]-B[i]);
tr=max(p1,p2);
s+=tr;
}
return s;
}
int main()
{int n,k,kk,i,j,sum;
vector <int> x;
vector <int> y;
cin>>n;
cout<<"enter vectors";
for (i=0;i<n;i++)
{cin>>k;
x.push_back(k);
}
for (i=0;i<n;i++)
{cin>>kk;
y.push_back(kk);
}
sum=coverPoints(x,y);
cout<<endl<<sum;




    return 0;
}