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
bool comp(vector<int> const a,vector<int> const b){
    return a[0]<b[0];
}
int main(){
    int i,j,n,m,x,y,w;
    cin>>n>>m;
    vector<int> k1(n+1);
    vector<vector<int>> edge(m,{0,0,0});
    vector<vector<int>> ans;
    parent=k1;
    sz=k1;
    for(i=1;i<=n;i++)
    make_set(i);
    for(i=0;i<m;i++){
        cin>>x>>y>>w;
        edge[i][0]=w;
        edge[i][1]=x;
        edge[i][2]=y;
    }
    int pp=0;
    sort(edge.begin(),edge.end(),comp);
      for(i=0;i<m;i++){
         if (find_set(edge[i][1])!=find_set(edge[i][2])){
           ans.push_back(edge[i]);
           union_set(edge[i][1],edge[i][2]);
           pp++;
    }
      }
      cout<<pp<<endl;
      for (i=0;i<=pp;i++){
              cout<<ans[i][1]<<"  "<<ans[i][2]<<"  "<<ans[i][0]<<endl;
      }
    return 0;
}

/*
8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1
8 5 1

*/