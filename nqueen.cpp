#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> afterplacing(vector<vector<int>> a,int n,int i,int j) 
{int r,sy1,sy2,k1,k2;

for (r=0;r<n;r++)
a[r][j]=0;

for (r=0;r<n;r++)
a[i][r]=0;

sy1=-1;
while ((sy1==1) || (sy1==-1))
{sy2=-1;
    while ((sy2==1) || (sy2==-1))
{k1=i;
k2=j;
    while ( (  k1>=0   ) &&  ( k1<n    ) && (  k2>=0   ) &&  ( k2<n    )  )
     {  
        a[k1][k2]=0;
        k1=k1+sy1;
        k2=k2+sy2;
    }
sy2+=2;
}
sy1+=2;
}

a[i][j]=1;
    return a;
}


vector<vector<int>> nqueen(vector<vector<int>> a,int n,int j)
{ if (a[n-1][n-1]!=5)
{
    int k1,k2;
vector<vector<int>> b;
b=a;
if (j==n-1)
{   for (k1=0;k1<n;k1++)
    {   if (a[k1][j]==2)
        {   a[k1][j]=1;
            return a;
        }
    }
    a[n-1][n-1]=5;
    return a;
}

for (k2=0;k2<n;k2++)
{   if (a[k2][j]==2)
    {   a[k2][j]=1;
        a=afterplacing(a,n,k2,j);
        a=nqueen(a,n,j+1);
        if (a[n-1][n-1]==5)
        {   a=b;
        }
        else
        return a;
    }
}
a[n-1][n-1]=5;
return a;
}
else
return a;
}


int main()
{int n,i,j;
cout<<"enter the size of matrix= ";
cin>>n;
vector<vector<int>> a(n,vector<int> (n,2));
a=nqueen(a,n,0);
//a=afterplacing(a,n,1,1);
if (a[n-1][n-1]==5)
{cout<<"not possible";
return 0;
}
cout<<endl<<"positons of queens will be= "<<endl;
for (i=0;i<n;i++)
{{for (j=0;j<n;j++)
cout<<a[i][j]<<"    ";
}
cout<<endl;
}
    return 0;
}