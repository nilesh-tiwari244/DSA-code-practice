#include<iostream>
using namespace std;
int check(int a[],int x,int y)
{//if any nom between x and y  greater
    int i=y-1,xx=0;
    int minb=min(a[x],a[y]);
    while (i>x)
    {if (a[i]>=minb)
    return -1;
    else
    xx+=minb-a[i];  
    i--;
    }
    if(x==i)
    return xx;//sum of water collected
}
int rainwater(int a[],int n)
{int arr=0,i=0,k;
while(i<=n-3)
{
k=n-1;
while(k>i+1)
{if (check(a,i,k)!=-1)
{arr+=check(a,i,k);
i=k-1;
break;
}
k--;
}
i++;
}
return arr;
}

int main()
{int n=12;
int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
cout<<"area="<<rainwater(a,n);
//int a[]={3,1,0,7};
//cout<<"area="<<check(a,0,3);
return 0;
}