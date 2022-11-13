#include<iostream>
#include<vector>
using namespace std;
bool chebipar(int n,vector<vector<int>> adl,vector<int> &vis,int co){
    if (vis[n]!=0){
       if (vis[n]!=co)
       return false;
       return true;
    }
    vis[n]=co;
    int k;
    if (co==1)
    k=2;
    else
    k=1;
    for(int i=0;i<adl[n].size();i++){
        if (!chebipar(adl[n][i],adl,vis,k))
            return false;
    }
    return true;
}
int main(){
    int i,j,cc=0,x,y,n,m;
    cin>>n>>m;
    vector<vector<int>> adl(n+1);
    vector<int> vis(n+1,0);
    for (i=0;i<m;i++){
        cin>>x>>y;
        adl[x].push_back(y);
        adl[y].push_back(x);
    }
    for (i=1;i<n+1;i++){
        if (vis[i]==0){
           if(!chebipar(i,adl,vis,1)){
               cout<<"Its not bipartite";
               return 0;
           }
        }
    }
    cout<<"Its bipartite graph";
    return 0;
}