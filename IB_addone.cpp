#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &A) { // add one to number stored in vector
int p=A.size();
int cy,h,pp,sa,lk,j,u;
cy=1;
for (h=p-1;h>=0;h--)
{A[h]+=cy;
cy=(A[h])/10;
A[h]%=10;
}

if (cy>0)
{A.push_back(A[p-1]);
for (j=p-1;j>0;j--)
{A[j+1]=A[j];
}
A[0]=cy;
}
else
{
sa=0;
for (pp=0;pp<p;pp++)
{sa+=A[pp];
if(sa>0)
break;
}
for (lk=pp;lk<p;lk++)
{A[lk-pp]=A[lk];
}
for (u=0;u<pp;u++)
A.pop_back();
}


return A;
}


int main()
{int n,hh;
vector<int> a;
vector<int> k;
cout<<"enter size of number";
cin>>n;
for (int i=0;i<n;i++)
{
    cin>>hh;
    a.push_back(hh);
}
k=plusOne(a);
for (int i=0;i<(k.size());i++)
cout<<k[i]<<" ";
return 0;
}