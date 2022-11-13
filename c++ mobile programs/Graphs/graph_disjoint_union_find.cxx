#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
vector<int> sz;

void make(int k){
    parent[k]=k;
    sz[k]=1;
}
int find_set(int k){
    if (k==parent[k])
    return k;
    parent[k]=find_set(parent[k]);
    return parent[k];
}
void union_set(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if (a!=b){
        if (sz[a]<sz[b])
        swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
   return; 
}
      
int main(){
    int n,i,m,x,y;
    cin>>n>>m;
    vector<int> kk(n+1);
    parent =kk;
    sz=kk;
    for (i=1;i<n+1;i++)
    make(i);
    for(i=0;i<m;i++){
      cin>>x>>y;
      union_set(x,y);    
    }
    cout<<endl;
      for (i=1;i<n+1;i++)
    cout<<parent[i]<<"  ";
    return 0;
}
    
    
    
    