#include<iostream>
using namespace std;

bool ratmaze(int** a,int x,int y,int n,int** sol)
{   if ((x==n-1) && (y==n-1) && (a[x][y]==1))
    {   sol[x][y]=1;
        return true;
    }

    if ((x<=n-1) && (y<=n-1) && (a[x][y]==1))
    {sol[x][y]=1;
        if(ratmaze(a,x,y+1,n,sol))
        return true;
        
        if(ratmaze(a,x+1,y,n,sol))
        return true;
       
    }
    sol[x][y]=0;
    return false;
}

int main()
{int n,i,j;
cout<<"enter the size of matrix= ";
cin>>n;

int** p=new int* [n];
for (i=0;i<n;i++)
{
p[i]=new int [n];
}
cout<<endl<<"enter the matrix= ";
for (i=0;i<n;i++)
{for (j=0;j<n;j++)
{cin>>p[i][j];
}}

int** v=new int* [n];
for (i=0;i<n;i++)
{
v[i]=new int [n];
}
for (i=0;i<n;i++)
{for (j=0;j<n;j++)
{v[i][j]=0;
}}

for (i=0;i<n;i++)
{for (j=0;j<n;j++)
{cout<<p[i][j]<<" ";
}cout<<endl;
}
cout<<"is it possible= "<<ratmaze(p,0,0,n,v);
cout<<endl;
cout<<"path is "<<endl;
for (i=0;i<n;i++)
{for (j=0;j<n;j++)
{cout<<v[i][j]<<" ";
}cout<<endl;
}
    return 0;
}