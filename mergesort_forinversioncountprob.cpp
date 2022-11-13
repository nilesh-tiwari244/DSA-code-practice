#include<iostream>
#include<vector>
using namespace std;
vector<int> mergesort(vector<int> a,int & z)
{if (a.size()==1)
return a;
int i,x=0,y=0,k=(a.size())/2;
vector<int> c;
vector<int> d;
for (i=0;i<k;i++)
c.push_back(a[i]);
for (i=k;i<=a.size()-1;i++)
d.push_back(a[i]);
c=mergesort(c,z);
d=mergesort(d,z);
a.clear();
while ((x<c.size()) && (y<d.size()))
{if (c[x]<d[y])
{a.push_back(c[x]);
x++;}
else
{a.push_back(d[y]);
y++;
z=z+(c.size()-x);
}}
while ((x==c.size())&&(y!=d.size()))
{a.push_back(d[y]);
y++;}
while ((x!=c.size())&&(y==d.size()))
{a.push_back(c[x]);
x++;
}return a;
}

int main()
{int i,z=0,n=8;
vector<int> a={3,5,6,9,1,2,7,8};
a=mergesort(a,z);
cout<<endl;
for (i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
cout<<"inversions="<<z;
    return 0;
}