#include<iostream>
using namespace std;
int main(){
    int a,b,fl,i,j;
    cout<<"enter size of matrix=";
    cin>>a>>b;
    int ma[a][b];
    for (i=0;i<a;i++)
    {   for (j=0;j<b;j++)
            cin>>ma[i][j];
    }
      cout<<endl;
     for (i=0;i<a;i++)
    {   for (j=0;j<b;j++)
            cout<<ma[i][j]<<" ";
            cout<<endl;
    }

    for (i=0;i<a-1;i++)
    {for (j=i;j<b;j++) 
    {fl=ma[i][j];
    ma[i][j]=ma[j][i];
    ma[j][i]=fl;
    }}
    cout<<endl;
     for (i=0;i<a;i++)
    {   for (j=0;j<b;j++)
            cout<<ma[i][j]<<" ";
            cout<<endl;
    }


}