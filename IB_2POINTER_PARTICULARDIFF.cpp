#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<int> &A, int B) {
    B=abs(B);
   sort(A.begin(),A.end());
    int st,en,c,d,n=A.size();
    st=0;en=1;
    if(B==0)
    return 1;
    if (n<=1)
    return 0;
    if(B>A[n-1]-A[0])
    return 0;
    
    while((st<en)&&(en!=n)){
        c=A[st];
        d=A[en];
        if (d-c < B){
            while(d-c < B){
                en++;
                if(en<n)
                d=A[en];
                else 
                break;
            }
            if(en==n)
            {cout<<"1111";
            return 0;
            }
            if (d-c == B)
            return 1;
        }
        /*
            while(d-c > B){
                st++;
                if (st<en)
                c=A[st];
                else
                break;
            }
            if (st==en)
            {en++;
            if(en<n)
                d=A[en];
                else 
                break;
            }
            if(en==n)
            return 0;
            if (d-c == B)
            return 1;
        }
        */
           /* while((d-c > B)&&(st<en)&&(en<n)){
                st++;
                en++;
                c=A[st];
                d=A[en];
            }
            if(en==n)
            return 0;
            if (d-c == B)
            return 1;
        }
        */
        else if (d-c > B){
        while(d-c > B){
                st++;
                if (st<en)
                c=A[st];
                else
                break;
            }
            if (st==en)
            {en++;
            if(en<n)
                d=A[en];
            }
            if(en==n)
             {cout<<"22222";
            return 0;
            }
            if (d-c == B)
            return 1;
        }
        else
        return 1;
    }
     cout<<"333";
            return 0;
            
}
int main(){
    int n,B=-42;
    vector<int> A={-259, -825, 459, 825, 221, 870, 626, 934, 205, 783, 850, 398};
    cout<<solve(A,B);
}
