#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{int s,n,i,su,j;
cin>>s>>n;
int a[n];
for (i=0;i<n;i++)
cin>>a[i];

i=0;
j=0;
su=0;

while((j<=n-1) && (su!=s))
{su=su+a[j];
if (su==s)
{cout<<"indexes are"<<i<<" and "<<j;
return 0;
}
if (su>s)
{while (su>s)
   { su-=a[i];
   i+=1;
   if (su==s)
    {cout<<"indexes are"<<i<<" and "<<j;
    return 0;
    }
    }
}        
    j=j+1;
}
	return 0;
}