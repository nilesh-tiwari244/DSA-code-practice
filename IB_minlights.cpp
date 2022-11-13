#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;
int minlight(vector<int> &A, int B) {
int n,i,j,il=-1,re1,re2,s=0,tr,s1=0,di,pre;
n=A.size();
re2=-1;
while (re2<n-1)
{   s1=0;
    for (i=re2+B;i>pre;i--)
        {
            s1+=A[i];
        if (s1>0)
            {s++;
            re2=i+B-1;
            break;
            }
        }
    if (s1==0)
    return -1;
    pre=i;
}
return s;
}


/*
re2=-1;
re1=n;
s1=0;
for (i=B-1;i>=0;i--)
{s1+=A[i];
if (s1>0)
{s++;
re2=i+B-1;
break;
}
}
if (s1==0)
return -1;
//cout<<re2;
cout<<endl;
if (re2>=n-1)
return 1;

s1=0;
for (i=n-B;i<=n-1;i++)
{s1+=A[i];
if (s1>0)
{s++;
re1=i-(B-1);
    break;
}
}
if (s1==0)
return -1;
//cout<<re1;
if (re1<=0)
return 1;

while (di>1)
{s1=0;
for (i=re2+B-1;i>=re2;i--)
{s1+=A[i];
if (s1>0)
{s++;
re2=i+B-1;
i=re2+B;
break;
}
}
if (s1==0)
return -1;
di=re1-re2;
}


return s;
}
*/

int main()
{int n,B,k,i,sum;
vector <int> x;
cin>>n;
cout<<"enter vectors= ";
for (i=0;i<n;i++)
{cin>>k;
x.push_back(k);
}
cout<<"enter power of light= ";
cin>>B;
sum=minlight(x,B);
cout<<endl<<sum;




    return 0;
}