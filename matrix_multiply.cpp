#include<iostream>
using namespace std;
int main()
{int n1,n2,n3,i,j,k,sum;
cout<<"enter n1,n2 and n3=";
cin>>n1>>n2>>n3;
int a[n1][n2];
int b[n2][n3];
int c[n1][n3];
cout<<"enter values of  matrix a=";
for (i=0;i<n1;i++)
{for (j=0;j<n2;j++)
{cin>>a[i][j];
}}

cout<<"enter values of  matrix b=";

for (i=0;i<n2;i++)
{for (j=0;j<n3;j++)
{cin>>b[i][j];
}}

for (i=0;i<n1;i++)
{
k=0;
while(k<n3)
{sum=0;
    for (j=0;j<n2;j++)
{sum+=((a[i][j])*(b[j][k]));
}
c[i][k]=sum;
k+=1;
}
}

cout<<endl;

for (i=0;i<n1;i++)
{for (j=0;j<n3;j++)
{cout<<a[i][j]<<" ";
}
cout<<endl;
}
cout<<endl;

for (i=0;i<n1;i++)
{for (j=0;j<n3;j++)
{cout<<b[i][j]<<" ";
}
cout<<endl;
}

cout<<endl;

for (i=0;i<n1;i++)
{for (j=0;j<n3;j++)
{cout<<c[i][j]<<" ";
}
cout<<endl;
}


}