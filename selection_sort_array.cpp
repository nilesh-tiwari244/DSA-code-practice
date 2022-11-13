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
    
  for (int j=0;j<n;j++)
        {mini=a[j];
        po=j;
        for (int m=j;m<n;m++)
            {if (a[m]<mini)
                {mini=a[m];
                 po=m;
                 }
            }
            c=a[j];
            a[j]=mini;
            a[po]=c;
             
    }
      for (int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    
   
    return 0;
}