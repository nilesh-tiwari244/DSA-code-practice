#include<iostream>
#include<vector>
using namespace std;
/* RECURSION
int ifsum(vector<int> a,int ss,int k)
{int i=0,n;
n=a.size();
if (k==1)
{    while(i<n)
        {if(a[i]==ss)
            return 1;
            i++;
        }
        return 0;
}
i=0;
k--;
vector<int> b=a;
vector<int>::iterator it=b.begin();
while(i<b.size())
{  b.erase(it+i);
  if (ifsum(b,ss-a[i],k))
      return 1;
  else
      b=a;
      i++;
}
return 0;    
}
*/

//O(n2) method
int ifsum(vector<int> a,int ss,int k)
{sort(a.begin(),a.end());
    int i=0,lo,hi;
    while(i<a.size()-2)
    {    lo=i+1;
          hi=a.size() - 1;
          while (lo<hi)
          {    if (a[lo]+a[hi]>ss-a[i])
                  hi--;
                else if (a[lo]+a[hi]<ss-a[i])
                  lo++;
                  else
                  return 1;
          }
                    i++;
}
return 0;    
}
int main()
{int n=6;
vector<int> a={12,9,3,4,5,7};
int kk=ifsum(a,15,3);

cout<<kk;
return 0;
}