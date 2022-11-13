#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
vector<int> cou(vector<int> &A, int a){
    int i,j,k,n=A.size();
    vector<int> v(2,0);
    for(i=0;i<n;i++){
            if (A[i]<a)
            j++;
            else{
              if (A[i]==a)  
                v[1]=1;
            break;
            }
        }
        v[0]=j;
        return v;
}
int solve(vector<int> &A, int B, int C) {
int j,i,k,n=A.size();
    if ((n==0)||(B<=0)){
        return 0;
    }
    if (C==0){
        return 0;
    }
    if (B==1){
        j=0;
        for(i=0;i<n;i++){
            if (A[i]<C)
            j++;
            else
            break;
        }
        return j;
    }
    int pp,zz,xx,an=0;
    pp=C;
    j=0;
    while (pp>0){
        pp=pp/10;
        j++;
    }
    //cout<<"size of c= "<<j<<endl;
    vector<int> mp;
    if (j<B)
    return 0;
    pp=0;
    if (j>B){
        if (A[0]==0){
            pp=(n-1)*(n-1);
        }
        else
            pp=n*(n-1);
        return pp;
    }
    else{
        pp=C; //21
        k=pow(10,j-1);//10
        xx=j;//2
        while (pp>0){
            zz=pp/k;//2
            pp=pp%k;//1
            mp=cou(A,zz);
            //cout<<mp[0]<<"  "<<mp[1]<<endl;
            if ((xx==j)&&(A[0]==0)){
            an=an+(mp[0] -1)*(pow(n,xx-1));
            }
            else
            an=an+(mp[0])*(pow(n,xx-1));
            //cout<<"fisrst an= "<<an<<endl;
            if (mp[1]==1){
                k=k/10;
                xx--;
            }
            else
            return an;
        }
        return an;
    }

}

int main(){
    vector<int> v={0,1,2,5};//24 42
    int a=10;
    int n=solve(v,2,21);
        cout<<endl<<endl<<n;
    
    return 0;
}
