#include<iostream>
using namespace std;

void permurepeat(int a[],int n,int ch,int si)
{int i,j,kk;
sort (a,a+n);

if (n==0)
{
cout<<ch<<endl;
return;
}
for (i=n-1;i>=0;i--)
{while ((a[i-1]==a[i]) && (i>=1))
  {i--;}
    kk=a[n-1];
a[n-1]=a[i];
a[i]=kk;
int b[n-1];
for (j=0;j<n-1;j++)
b[j]=a[j];
if (ch<0)
permurepeat(b,n-1,a[n-1],1);
else
permurepeat(b,n-1,(a[n-1]*pow(10,si))+ ch,si+1);    
}
}

int main()
{int a[4]={1,2,4,3};
permurepeat(a,4,-1,1);
return 0;
}