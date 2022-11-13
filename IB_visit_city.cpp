#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool pos(int k,int a,vector<int> &B){
    if (k<=0)
    return false;
    if (k>a)
    return false;
    int i,j,n=B.size();
    for(i=0;i<n;i++){
        if ((B[i]==k-1)||(B[i]==k+1))
            return true;
    }
    return false;
}
bool fou(int a,vector<int>& cc){
    int n=cc.size(),i=0,j;
    while(cc[i]<=a){
        if (cc[i]==a)
        return true;
        i++;
    }
    return false;
}
int solve(int A, vector<int> B) {
    int i,j,k,n=B.size(),an=0;
    if (n==A)
    return 1;
   cout<<"size of B= "<<n<<endl;
    vector<int> cc=B;
    sort(cc.begin(),cc.end());
    vector<int> dd=cc;
   // cout<<"elements= "<<cc[0]<<" "<<cc[1]<<endl;
    int nn=1;
    i=1;
    while(cc.size()!=A){
        if (!fou(i,cc)){
            if (pos(i,A,cc)){
                cc.push_back(i);
               cout<<"calling for= "<<i<<"with n="<<cc.size()<<endl;
                j=solve(A,cc);
                sort(cc.begin(),cc.end());
                an=(an+j)%(1000000007);
                i=0;
            }
        }
        i++;
    }
    return an;
}
int main(){
    vector<int> v={1};//24 42
    int a=10;
    int n=solve(a,v);
        cout<<n;
    
    return 0;
}