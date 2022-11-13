#include<iostream>
using namespace std;

void checksort (int a[],int n)
{if (n==1)
{cout<<"yes";
return;}
if (a[n-1]>=a[n-2])
checksort(a,n-1);
else
cout<<"no";
return;
}

int main()
{int n,i;
cout<<"enter size of array";
cin>>n;
int a[n];
for (i=0;i<n;i++)
{cin>>a[i];
}
checksort(a,n);
cout<<endl;
/*for (i=0;i<n;i++)
{cout<<a[i];
}*/
    return 0;
}