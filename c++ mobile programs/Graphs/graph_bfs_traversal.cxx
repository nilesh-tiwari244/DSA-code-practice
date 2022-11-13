#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n,m,i,j,x,y;
    cout<<"enter nodes and edges= ";
    cin>>n>>m;
    vector<bool> vis(n+1,false);
    vector<vector<int>> adl(n+1);
    cout<<"enter the edges= ";
    for (i=1;i<=m;i++){
        cout<<"enter "<<i<<" edge= ";
        cin>>x>>y;
        adl[x].push_back(y);
        adl[y].push_back(x);
    }
    cout<<endl<<"BFS traveral= "<<endl;
    queue<int> q;
    q.push(1);
    vis[1]=true;
    while (!q.empty()){
        int pp=q.front();
        cout<<pp<<endl;
        q.pop();
        for (j=0;j<adl[pp].size();j++){
            if (!vis[adl[pp][j]]){
                q.push(adl[pp][j]);
                vis[adl[pp][j]]=true;
            }
        }
    }
    return 0;
}
                
    
        
    