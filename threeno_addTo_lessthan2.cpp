#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

float chan(string A){
    int i,j,k,n=A.size();
    string pr,af;
    for(i=0;i<n;i++){
        if (A[i]=='.'){
            for(j=i+1;j<n;j++){
                af+=A[j];
            }
            break;
        }
        else{
            pr+=A[i];
        }
    }
    float ff,gr;
    int gh,pp,n2=af.size();
    if (n2!=0){
    gh=stoi(af);
    ff=gh/pow(10,n);        
    }
    else
    ff=0;
    pp=stoi(pr);
    gr=pp+ff;
    return gr;
}
int fin(vector<float> &v,int st){
    int n=v.size();
    int x=v[st-1];
    int re,en=n-1;
    while (st<en){
        re=x+v[st]+v[en];
        if (re>1 && re<2){
            return 1;
        }
        else if (re<1){
            st++;
        }
        else{
            en--;
        }
    }
    return 0;
}
int solve(vector<string> &A) {
    int i,j,k,n=A.size();
    vector<float> vv(n);
    for (i=0;i<n;i++){
        vv[i]=chan(A[i]);
    }
    sort(vv.begin(),vv.end());
    int ggh;
    for (i=0;i<n-2;i++){
        if (vv[i]>2){
            return 0;
        }
        ggh=fin(vv,i+1);
        if (ggh==1)
        return 1;
    }
    return 0;
}
int main(){
	//vector<string> v;
	string st="1.45";
	cout<<chan(st);
	return 0;
}
