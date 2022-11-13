#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stock(int a[],int n)
{vector<int> ans;
int i,fl=1;
stack<int> st;
for (i=0;i<n;i++)
{fl=1;
if ((!st.empty())&&(a[st.top()]<a[i]))
{   while( (!st.empty())&&(a[st.top()]<a[i]))
        st.pop();
    if (st.empty())
        fl=i+1;
    else
        fl=i-st.top();
 }
ans.push_back(fl);
st.push(i);
}
return ans;     
}

int main()
{int i,n=11;
    int a[]={100,75,80,76,92,108,120,110,43,46,2};
    vector<int> b=stock(a,n);
    cout<<endl;
    for (i=0;i<b.size();i++)
    {cout<<b[i]<<" ";
    }
    
    return 0;
}