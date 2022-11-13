#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<stack>
using namespace std;
int maxArea(vector<int> &A) {
int i=1,j,k=0,n=A.size(),gg,hh=0;
    stack<int> st;
    st.push(0);
    while (i<n){
        if ((i==0)||(A[i]>=A[st.top()])){
            st.push(i);
            i++;
        }
        else{
           j=st.top();
           k=0;
            while ((!st.empty())&&(A[st.top()]>=A[i])){
                gg=st.top();
                st.pop();
                if (!st.empty())
                k=max (k,(j-st.top())*(min(A[gg],A[j])));
                else
                k=max (k,(j+1)*(min(A[gg],A[j])));
            }
                k=max (k,(i-(gg)+1)*(min(A[gg],A[i])));
            st.push(i);
            i++;
        }
        hh=max(k,hh);
    }
    if (!st.empty()){
        k=0;
        j=st.top();
        while (!st.empty()){
                gg=st.top();
                k=max (k,(j-(gg)+1)*(min(A[gg],A[j])));
                st.pop();
            }
    }
        hh=max(k,hh);
        return hh;
}

 int main(){
    vector<int> a={90, 58, 69, 70, 82, 100, 13, 57, 47, 18 };
    int n=maxArea(a);
    cout<<endl<<n<<endl<<endl;
    return 0;
}
