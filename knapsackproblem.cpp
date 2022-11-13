#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int knapmax(vector <vector <int>> a,int w)  // TRUST YOUR FUNCTION
{int n,i,j,kk=0;
n=a.size();

int maxi=INT_MIN;

if (n==1)
{if (a[0][0]<=w)
return a[0][1];
else 
return 0;
}

if (n==0)
return 0;

vector <vector <int>> kuu;
kuu=a;

for (i=0;i<n;i++)
    {a=kuu;
    if (a[i][0] <= w)
       {a.erase((a.begin())+i);
            kk = kuu[i][1] + ( knapmax ( a, (w - kuu[i][0]) ) );   
       }
     if (kk>maxi)
     maxi=kk;
    }
return maxi;


}



int main()
{int n,w,i,j;
//cout<<"enter number of items= ";
//cin>>n;
n=3;
//cout<<"enter the capacity of the bag= ";
//cin>>w;
w=50;

/*
vector <vector <int>> a(n);
vector <int> k(2);
for (i=0;i<n;i++)
{
a[i]=k;
}
cout<<"enter the weights of the n items= ";
for (i=0;i<n;i++)
{
cin>>a[i][0];
}
cout<<"enter the value of n items= ";
for (i=0;i<n;i++)
{
cin>>a[i][1];
}
*/

vector<vector<int>> a {
                { 10, 100 },
                { 20, 50},
                { 30, 150 },
            };

for (i=0;i<n;i++)
{for (j=0;j<2;j++)
        {cout<<a[i][j]<<" ";
        }
        cout<<endl;
}
cout<<endl;



int maxi=knapmax(a,w);
cout<<"maximum carryable value will be= "<<maxi;


/*
a.pop_back();
cout<<endl<<a.size();
for (i=0;i<n;i++)
{for (j=0;j<2;j++)
        {cout<<a[i][j]<<" ";
        }
        cout<<endl;
}
*/
    return 0;
}