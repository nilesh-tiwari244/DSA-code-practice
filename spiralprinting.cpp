#include<iostream>
#include<vector>
using namespace std;
int main()
{int n,m,i,j,k;
cin>>n>>m;
vector<vector <int>> a(n);

for (i=0;i<n;i++)
{a[i]=vector<int>(m);
    for (j=0;j<m;j++)
{
cin>>k;
a[i][j]=k;
}
}

for (i=0;i<n;i++)
{cout<<endl;
    for (j=0;j<m;j++)
{
cout<<a[i][j]<<" ";
}
}

//cout<<endl<<a.size()<<endl<<a[1].size();

cout<<endl<<endl;

int ro=1,cl=1,tcr=1,le,rowstart,rowending,columnstart,columnending;
rowstart=0;
rowending=m-1;
columnstart=0;
columnending=n-1;
le=1;
while(le<=m*n)
{
    if(tcr==1) //row printing
    {tcr=0;
        if (ro==1) //increasing order
        {ro=0;
            for (i=rowstart;i<=rowending;i++)
            {cout<<a[columnstart][i]<<" ";
            le+=1;}
//            rowstart=0;
//            rowending=m-1;
            columnstart+=1;
 //           columnending=columnending;
            
        }
        else if (ro==0)
        {ro=1;
            for (i=rowending;i>=rowstart;i--)
            {cout<<a[columnending][i]<<" ";
            le+=1;}
//            rowstart=0;
//            rowending=n;
//            columnstart=0;
            columnending-=1;
            
        }

    }
    else if (tcr==0)   //column printing
    {tcr=1;
        if (cl==1)  //increasing order
        {cl=0;
            for (i=columnstart;i<=columnending;i++)
            {cout<<a[i][rowending]<<" ";
            le+=1;}
//            rowstart=0;
            rowending-=1;
//            columnstart=0;
//            columnending-=1;
           
        }
        else if (cl==0)
        {cl=1;
            for (i=columnending;i>=columnstart;i--)
            {cout<<a[i][rowstart]<<" ";
            le+=1;}
            rowstart+=1;
//            rowending-=1;
//            columnstart=0;
//            columnending-=1;
            
        }


    }


}


return 0;
}