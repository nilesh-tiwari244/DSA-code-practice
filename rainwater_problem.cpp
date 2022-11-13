#include<iostream>
#include<stack>
using namespace std;

int larrec(int a[],int n)
{stack<int> st;
int i,arr=0,te,h,l;
for (i=0;i<n;i++)
{if ((st.empty())||(a[st.top()]>a[i]))
    {
        st.push(i);
    }
else 
    {while ((!st.empty()&&(a[st.top()]<a[i])))
        {h=a[st.top()];
        st.pop();
        }
        st.push(i);
    }
    if ((i==n-1))
        {while ((!st.empty()))
            {h=a[st.top()];
        l=i-st.top()+1;
        te=h*l;
        arr=max(arr,te);
        cout<<arr<<endl;
        st.pop();
        }

        }
}
return arr;
}

int main()
{int a[]={2,1,5,2,4,6,3,2};
cout<<endl<<larrec(a,8);
return 0;
}