#include<iostream>
#include<vector>
using namespace std;

bool rattrack(int a[][nc],int nr,int nc)
{//int rx=nr-mr,ry=nc-mc+1,cx=rx+1,cy=ry-1;
if ((nr==1) && (nc==1) && (a[0][0]==1))
return true;
int i,j;
if (((a[0][1]==0) || (1>=nc)) && ((a[1][0]==0) || (1>=nr)))
return false;

if ((a[0][1]==0) || (1>=nc))
    {int b[nr-1][nc];
     for (i=0;i<nr-1;i++)
        {for (j=0;j<nc;j++)
        b[i][j]=a[i+1][j];
        }
        return (b,nr-1,nc);
    }
    
    if ((a[1][0]==0) || (1>=nr))
    {int b[nr][nc-1];
     for (i=0;i<nr;i++)
        {for (j=0;j<nc-1;j++)
        b[i][j]=a[i][j+1];
        }
        return (b,nr,nc-1);
    }
    int b[nr-1][nc];
     for (i=0;i<nr-1;i++)
        {for (j=0;j<nc;j++)
        b[i][j]=a[i+1][j];
        }
        bool tt=(b,nr-1,nc);
        
        if (tt=true)
        return true;
        else{
        int c[nr][nc-1];
     for (i=0;i<nr;i++)
        {for (j=0;j<nc-1;j++)
        c[i][j]=a[i][j+1];
        }
        return (c,nr,nc-1);	
        }
}

int main()
{int i,j;
    int a[5][5]= {{1,0,1,0,1},{1,1,1,1,1},{0,1,0,1,0},{1,0,0,1,1},{1,1,1,0,1}};
    
    for (i=0;i<5;i++)
    {for (j=0;j<5;j++)
    cout<<a[i][j]<<"  ";
    cout<<endl;
    }
    cout<<rattrack(a,a,5,5,5,5);
    return 0;
}