#include<iostream>
#include<deque>
using namespace std;

pair<int,int> maxi(int a[],int st,int n)
{int i=st+1,k=a[st],g=st;
while(i<n+st)
{if (a[i]>k)
{k=a[i];
g=i;
}
    i++;
}
pair<int,int> s={k,g};
    return s ;
}

void slidingwindow(int a[],int n,int k)
{int c,i,g;
  pair <int,int>hh;
  
if (n<=k)
{
    hh=maxi(a,0,n);
cout<<hh.first;
return;
}

  hh=maxi(a,0,k);
cout<<hh.first<<" ";
i=k;
while(i<n)
{while (((i-k)<hh.second)&& (i<n))
{if (a[i]<hh.first)
cout<<hh.first<<" ";
else
{hh={a[i],i};
cout<<hh.first<<" ";
}
i++;
}
hh=maxi(a,i-k+1,k);
}   
    return;
}
   
int main()
{int n=6;
int k=3;
    int a[]={9,8,17,2,11,5};
slidingwindow(a,n,k);
return 0;
}