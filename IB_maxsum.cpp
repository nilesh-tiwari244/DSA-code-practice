#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
int i,s,k=0,n,x,j,s1;
n=A.size();
s=INT_MIN;
for (i=n-1;i>=n-B;i--)
k+=A[i];
if(s<k)
s=k;
s1=s;
for (i=1;i<=B;i++)
{k=s1-A[n-B+i-1]+A[i-1];
if(s<k)
s=k;
s1=k;
}

/*for (i=0;i<B;i++)
k+=A[i];
if(s<k)
s=k;
k=0;
for (i=n-1;i>=n-B;i--)
k+=A[i];
if(s<k)
s=k;
*/

/*for (i=0;i<=B;i++)
{k=0;
    for (x=0;x<i;x++)
k+=A[x];
    for (j=n-1;j>=n-B+i;j--)
k+=A[j];
if(s<k)
s=k;
}
*/
return s;
}



int main()
{int i,n,B,k,s;
cin>>n;
cout<<"enter B";
cin>>B;
vector <int> a;
for (i=0;i<n;i++)
{cin>>k;
a.push_back(k);
}
s=solve(a,B);
cout<<s;
    return 0;

}