#include<iostream>
using namespace std;


void shiftt(int a[],int i,int st)
{int k;
int ma=a[i];
for (k=i-1;k>=st;k--)
a[k+1]=a[k];
a[st]=ma; 
    return;
}


void quicksort(int a[],int st,int ed)
{if (st>=ed)
return;
if (st<0) 
return;

int ch,p,i;
ch=a[st];
p=st;
for (i=st+1;i<=ed;i++)
{if (ch>a[i])
{shiftt(a,i,st);
p++;
}
}
quicksort(a,st,p-1);
quicksort(a,p+1,ed);
return;   
}

    
    
    
    

int main()
{
    int i,n;
    cout<<"enter size of array";
    cin>>n;
    int a[n];
    for (i=0;i<n;i++)
    cin>>a[i];
    
    quicksort(a,0,n-1);
    
    cout<<"sorted array is= ";
    for (i=0;i<n;i++)
    cout<<a[i]<<" ";
    
    return 0;
}
    