#include<iostream>
#include<vector>
using namespace std;
vector<int> addtofir(vector<int> &a,int b){
    int i,j,n=a.size();
    vector<int> bb;
    bb.push_back(b);
    for(i=0;i<n;i++)
    bb.push_back(a[i]);
    return bb;
}
vector<vector<int> > permute(vector<int> &A) {
    int i,j,k,pp,n=A.size();
    vector<vector<int>> v;

    if (n==1){
        v.push_back({A[0]});
        return v;
    }
    if (n<=0)
    return v;

    int n2;
    vector<int> b;
    vector<vector<int>> x;
    for (i=0;i<n;i++){
        b.clear();
        for(j=0;j<n;j++){
            if(j!=i)
            b.push_back(A[j]);
        }
        x=permute(b);
        n2=x.size();
        if (n2==0){
            v.push_back({A[i]});
        }
        else{
            for(k=0;k<n2;k++){
                v.push_back(addtofir(x[k],A[i]));
            }
        }
    }
    return v;
}
int main(){
    vector<int> a={1,2,3,4};
    vector<vector<int>> v=permute(a);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
