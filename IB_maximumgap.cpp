#include<iostream>
#include<vector>
using namespace std;

int maximumgap(vector<int> &a)
{int n;
n=a.size();
if (n<2)
return 0;
vector<int> b(n);
b=a;


}

int main()
{int n,i,rr;
cout<<"enter size of vector";
cin>>n;
vector<int> a(n);
for (i=0;i<n;i++)
{cin>>a[i];
}
rr=maximumgap(a);
cout<<endl<<rr;
 
 return 0;
}