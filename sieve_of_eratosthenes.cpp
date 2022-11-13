#include<iostream>
using namespace std;
int main()
{ int n,i,j;
cout<<"enter maximum number=";
cin>>n;
int a[n+1];
for (i=0;i<=n;i++)
a[i]=0;

i=2;
int p;
while ((i)<=n)
{if (a[i]==0)
cout<<i<<" ";
p=i;
j=i*p;
while (j<=n)
{a[j]=-1;
p++;
j=i*p;
}
i++;
while (a[i]!=0)
i++;

}


return 0;
}