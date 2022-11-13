#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int repeated( vector<int> &A)
{
int n,i,j,k;
float cc;
sort (A.begin(),A.end());
n=A.size();
cc=n/3;
j=A[0];
k=0;

for (i=1;i<n;i++)
{if (A[i]==j)
{k=k+1;
if (k>=cc)
return j;
}
else
{k=0;
j=A[i];
}    
}
return -1;
}

int main()
{int n,m,i,jpos,bb;
cout<<"enter n=";
cin>>n>>m;
vector <vector int> a;
for (i=0;i<n;i++)
{vector <int> v;
    for (j=0;j<m;j++)
{cin>>bb;
v.push_back(bb);
}
a.pushback(v);
}

for (i=0;i<n;i++)
{
    for (j=0;j<m;j++)
    {cout<<a[i][j];
cout<<endl;
    }
}
	return 0;
}