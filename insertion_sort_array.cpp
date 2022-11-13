#include<iostream>
using namespace std;

void shifting(int a[],int n1,int k) //n1 is index of sorted array final and k is where it should be put
{int ss;
    ss=a[n1+1];
for (int i=n1;i>=k;i--)
{a[i+1]=a[i];  
}
a[k]=ss;
}


int posi(int a[],int n1,int x)
{
for (int g=0;g<=n1;g++)
{ if ((a[g]>x))
return g;
else if ((a[g+1]>=x))
return (g+1);
}
return n1+1;
}

int main()
{int n,pos;
cin>>n;
int a[n];
for (int i=0;i<n;i++)
cin>>a[i];

for (int j=1;j<n;j++)
{
    pos=posi(a,j-1,a[j]);
   shifting(a,j-1,pos);
 }   
for (int i=0;i<n;i++)
cout<<a[i]<<"  ";

	return 0;
}