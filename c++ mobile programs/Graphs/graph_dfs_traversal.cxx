#include<iostream>
#include<vector>
using namespace std;
void dfstraversal(vector<vector<int>>adl,vector<bool> &vis,int n){//postorder
    int i,j;
    j=n;
      
     if (!vis[j]){
 //cout<<j<<endl;//uncommentfor preorder
    vis[j]=true;
    for (i=0;i<adl[j].size();i++){
        dfstraversal(adl,vis,adl[j][i]);
    }
 cout<<j<<endl;//coment for preorder
     }
    return;       
}
int main(){
    int n,m,i,j,x,y;
    cin>>n>>m;
    vector<bool> vis(n+1,false);
    vector<vector<int>> adl(n+1);
    for (i=1;i<=m;i++){
        cin>>x>>y;
        adl[x].push_back(y);
        adl[y].push_back(x);
    }
    cout<<endl<<"DFS traveral= "<<endl;
    dfstraversal(adl,vis,1);
    return 0;
}
/*
7 7
1 2
1 3
2 4
2 5
2 6
2 7
3 7
*/