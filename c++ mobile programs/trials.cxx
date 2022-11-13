#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

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