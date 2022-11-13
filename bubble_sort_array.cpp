#include<iostream>
using namespace std;
int main()
{
    int n,mini,c,po;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
  for (int j=0;j<n-1;j++)
        {
        for (int m=0;m<n-1-j;m++)
            {if (a[m]>a[m+1])
                { c=a[m];
            a[m]=a[m+1];
            a[m+1]=c;
                 }
            }
             
    }
      for (int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    
   
    return 0;
}