#include<iostream>
using namespace std;
int main()
{int n1,n2,i,j,k,r,c,sum;
cout<<"enter n1,n2 and n3=";
cin>>n1>>n2>>k;
int a[n1][n2];
cout<<"enter values of  matrix a=";
for (i=0;i<n1;i++)
{for (j=0;j<n2;j++)
{cin>>a[i][j];
}}
cout<<endl;

for (i=0;i<n1;i++)
{for (j=0;j<n2;j++)
{cout<<a[i][j]<<" ";
}
cout<<endl;
}
cout<<endl;
r=0;c=n2-1;
while((r<n1)||(c>=0))
{if (a[r][c]==k)
{cout<<"found";
return 0;
}
if (a[r][c]>k)
{c--;
}
else 
{
  r++;  
}
}
cout<<"not found";
return 0;
}