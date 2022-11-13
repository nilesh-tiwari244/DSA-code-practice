#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{int n,i,j,cou,d,mc=1,po;
cout<<"enter n=";
cin>>n;
int a[n];
for (i=0;i<n;i++)
{cin>>a[i];
}

for (i=0;i<n-1;i++)
{    cou=1;
d=a[i+1]-a[i];
po=i;
    for (j=po+1;j<n;j++)
    {if ((a[j]-a[j-1])==d)
    {cou+=1;
    }
     else
     {i=j-2;
     break;
     }
    }
    if (mc<cou)
    mc=cou;
}
cout<<endl<<mc;
	return 0;
}