#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> inse(vector<string> a,string st){
    int i,j,k,pp,n=a.size();
    vector<string> vv;
    vv.push_back(st);
    for (i=0;i<n;i++){
        vv.push_back(a[i]);
    }
    return vv;
}
bool ispalin(string A,int st,int en){
    int i,j,k,pp,n=A.size();
    if (n==0)
    return true;
    if (en<st)
    return false;
    if (st==en)
    return true;
    while(st<en){
        if (A[st]!=A[en])
        return false;
        st++;
        en--;
    }
    return true;
}
vector<vector<string> >partition(string A) {

    int i,j,k,pp,n=A.size();
    string st;
    vector<vector<string> > v;
    vector<vector<string> > aa;
    if (n==1){
        v.push_back({A});
        return v;
    }
    if (n==0){
        v.push_back({""});
        return v;
    }
    for (i=0;i<n;i++){
        if (ispalin(A,0,i)){
            if(i<n-1)
            aa=partition(A.substr(i+1,n-i-1));
            else
            {aa.clear();
            v.push_back({A});
            }
            st=A.substr(0,i+1);
            for(j=0;j<aa.size();j++){
                v.push_back(inse(aa[j],st));
            }
        }
    }
    return v;
}
int main(){
    string a="efe";

    vector<vector<string>> v=partition(a);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    return 0;
}
