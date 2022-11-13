#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{int n,m,i,jpos,bb;
cout<<"ENTER SIZE OF ARRAY= ";
cin>>n;
int a[n];
cout<<endl<<"enter the array ";
for(i=0;i<n;i++)
cin>>a[i];
m=0;
jpos=0;
for (i=0;i<n;i++)
{m+=a[i];
if (m<0)
{a[i]=0;
m=0;
}
else
a[i]=m;
if (jpos<m)
jpos=m;
}
cout<<endl;
cout<<jpos;
cout<<endl;
for(i=0;i<n;i++)
cout<<a[i]<<" ";

	return 0;
}