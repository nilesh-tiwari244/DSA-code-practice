#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> addparen(vector<string> a){
    int n=a.size(),i,j,k;
    vector<string> xx(n);
    if (n==0)
    xx.push_back("()");

    for (i=0;i<n;i++){
        xx[i]="("+a[i]+")";
    }
    return xx;
}
vector<string> generateParenthesis(int A) {
    vector<string> v;
    vector<string> a;
    vector<string> b;

    if (A==1){
    v.push_back("()");
    return v;
    }
    if(A<=0){
        v.push_back("");
    return v;
    }

    int i,j,k,pp;
    for(i=A-1;i>=0;i--){// 0 1 2 // 
        a=generateParenthesis(i);
        a=addparen(a);
        b=generateParenthesis(A-i-1);
    for(j=0;j<a.size();j++){
        for(k=0;k<b.size();k++){
            v.push_back(a[j]+b[k]);
        }
    }

    }
    return v;
}
int main(){
    int a=3;
    vector<string> v=generateParenthesis(a);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
            cout<<v[i];
        cout<<endl;
    }
    return 0;
}
