#include<iostream>
#include<vector>
using namespace std;

bool check(int A,int m){
if(m==0)
    return true;
int dd=A/m;
if (m < (1+dd)){
    if(m*m <= A)
    return true;
    else 
    return false;
}
else
    return false;
}

int ssqrt(int A) {
    int n,st,en,mid;
    bool p=false;
    st=0;
    en=A;
    while (st<en){
         //cout<<st<<" "<<en<<endl;
         if (check(A,en)){
            return en;
            }
        if(en-st==1){
            return st;
        }
       
        if((st+en)%2==1)
        p=true;
        else 
        p=false;

        mid=(st+en)/2;
        if (check(A,mid)){
            st=mid;
        }
        else{
            if(!p)
            en=mid-1;
            else
            en=mid;
        }
    }
    return en;
}
int main(){
//int a=2147483647;
int a=3;
cout<<ssqrt(a)<<" "<<check(3,2);
return 0;
}