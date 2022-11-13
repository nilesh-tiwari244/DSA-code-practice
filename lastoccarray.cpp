#include<iostream>
using namespace std;

int lastposfirst(int a[],int n,int k)
{  int jj=0;
    
    if (n==1)
        {if (a[n-1]==k)
            {cout<<n-1<<" ";
        cout<<endl;
        return 1;}
        return 0;
        }
        
    if (a[n-1]==k)
    {cout<<n-1<<" ";
    return 1;}

    else
    jj=lastposfirst(a,n-1,k);
    }




 
 int main()
{int n;
cout<<"enter size of array";
cin>>n;
int a[n],i,k;
cout<<endl;
cout<<"enter the array";
for (i=0;i<n;i++)
cin>>a[i];
cout<<"enter no. to be found";
cin>>k;
i=lastposfirst(a,n,k);
return 0;
}