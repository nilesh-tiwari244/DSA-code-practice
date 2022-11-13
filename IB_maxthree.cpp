#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int solvee(vector <int> &A)
{int a,b,c,i,j,k,n,fl,cc=0,s,su,ai;
n=A.size();
s=INT_MIN;
a=A[0];
b=A[1];
ci=s;
for(i=2;i<n;i++)
    {c=A[i];
    if(s<3*c)
    {for (j=i-1;j>=1;j--)
            {if (A[j]<c)
                {b=A[j];
                if(s<3*b)
                {for (k=j-1;k>=0;k--) 
                    {if (A[k]<b)
                        {a=A[k];
                        su=a+b+c;
                        if (su>s)
                        {s=su;
                        //ai=a;
                        }
                        cc++;
                        }
                    }
                }}
            }   
    }
    }

    if (cc>0)
      return s;
    else
    return 0;


  
}

int main()
{int n,i,ss,k;
cout<<"enter n= ";
cin>>n;
vector <int> a;
cout<<"enter the vector= ";
for (i=0;i<n;i++)
{cin>>k;
a.push_back(k);
}
ss=solvee(a);
cout<<endl;
cout<<ss;
    return 0;
}