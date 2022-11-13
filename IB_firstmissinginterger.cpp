#include <iostream>
#include <vector>
using namespace std;

int firstinteger(vector<int> &A) { // add one to number stored in vector
int p,mini,j,po,m,c,h,mi,ma,pp,mn=0;
p=A.size();

for (j=0;j<p;j++)
{       
        mini=A[j];
        po=j;
        for (m=j;m<p;m++)
            {if (A[m]<mini)
                {mini=A[m];
                 po=m;
                 }
            }
            c=A[j];
            A[j]=mini;
            A[po]=c;            
}

for (j=0;j<p;j++)
{       
        if (A[j]==1)
        mn=1;
}
/*
if ((A[p-1])<=0)
return 1;
if ((A[0])>1)
return 1;

for (h=0;h<p-1;h++)
    { 
        ma=A[h];
    if ((ma+1)!=A[h+1])
        {if((ma+1)>0)
        {if (mn!=1)
        return 1;
        }
        else
        {if (mn!=1)
        return 1;
        }
        }
    }

return ((A[p-1])+1);
*/

if ((A[p-1])<=0)
return 1;
if ((A[0])>1)
return 1;

for (h=0;h<p-1;h++)
    { 
    ma=A[h];
    if(mn==1)
    {   if (((ma+1)!=A[h+1]) && ((ma)!=A[h+1]))
        return ma+1;
    }
    }
    if(mn!=1)
    return 1;
    return ((A[p-1])+1);



    }


int main()
{int n,hh;
vector<int> a;
int k;
cout<<"enter size of number";
cin>>n;
for (int i=0;i<n;i++)
{
    cin>>hh;
    a.push_back(hh);
}
k=firstinteger(a);
cout<<endl<<k<<" ";
return 0;
}