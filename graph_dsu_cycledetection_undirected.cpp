#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
vector<int> sz;
void make_set(int x)
{
    parent[x]=x;
    sz[x]=1;
    return ;
}
int find_set(int a){
    if (parent[a]==a)
        return a;
        parent[a]=parent[parent[a]];
    return parent[a];
}
void union_set(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if (a!=b){
        if(sz[a]<sz[b])
        swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
    return;
}
int main(){
    int i,j,n,m,x,y;
    cin>>n>>m;
    vector<int> k1(n+1);
    parent=k1;
    sz=k1;
    for(i=1;i<=n;i++)
    make_set(i);
    for(i=0;i<m;i++){
        cin>>x>>y;
        if (parent[x]==parent[y]){
            cout<<"loop is there ";
            return 0;
    }
    else
        union_set(x,y);
    }
    cout<<"no loops ";
    return 0;
}