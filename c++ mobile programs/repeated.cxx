#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int repeated( vector<int> &a)
{
int n,i,j,k;
float cc;
sort (a.begin(),a.end());
n=a.size();
cc=n/3;
j=a[0];
k=0;

for (i=1;i<n;i++)
{if (a[i]==j)
{k=k+1;
if (k>=cc)
return j;
}
else
{k=0;
j=a[i];
}    
}
return -1;
}

int main()
{int n,pos,bb;
cout<<"enter n=";
cin>>n;
vector <int> a;
for (int i=0;i<n;i++)
{cin>>bb;
a.push_back(bb);
}
pos=repeated(a);
cout<<endl;
cout<<pos<<"  ";

	return 0;
}