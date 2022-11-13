#include<iostream>
using namespace std;

int* mergee(int* a,int m,int* b,int n)
{int *c=new int [m+n];
int i=0,j=0,k=0;
while (k<m+n)
{while ((i<m)&&(j<n))
   { if (a[i]<=b[j])
    {c[k]=a[i];
    i++;
    k++;}
    else
    {c[k]=b[j];
    j++;
    k++;}
  }
  if (i==m)
 { while (j<n)
{  c[k]=b[j];
j++;
k++;}
 }
  if (j==n)
 { while (i<m)
{  c[k]=a[i];
i++;
k++;}
}} 
 return c;   
}




int* mergesort(int*a,int n)
{int i;
    if (n==1)
return a;
    
    int n1=n/2;
int* c=new int[n1];
int* d=new int[n-n1];

for (i=0;i<n1;i++)
c[i]=a[i];
for (i=0;i<n-n1;i++)
d[i]=a[n1+i];

c=mergesort(c,n1);
d=mergesort(d,n-n1);
a=mergee(c,n1,d,n-n1);

    return a;
}




int main()
{int i;
int n;
cout<<"enter n=";
cin>>n;
int*c=new int[n];
cout<<"enter the elements=";

for (i=0;i<n;i++)
cin>>c[i];

cout<<"entered array is= ";
i=0;
while (i<n)
{cout<<c[i]<<" ";
i++;
}

c=mergesort(c,n);

cout<<endl;
cout<<"sorted array is= ";
i=0;
while (i<n)
{cout<<c[i]<<" ";
i++;
}
return 0;
}