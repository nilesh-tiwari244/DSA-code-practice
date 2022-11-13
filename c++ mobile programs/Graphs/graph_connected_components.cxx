#include<iostream>
#include<vector>
using namespace std;
void markcon(int n,vector<vector<int>> adl,vector<bool> &vis,int &si){
    vis[n]=true;
    si++;
    for(int i=0;i<adl[n].size();i++){
        if (!vis[adl[n][i]]){
            markcon(adl[n][i],adl,vis,si);
        } 
    }
    return;
}
int main(){
    int i,j,cc=0,x,y,n,m;
    cin>>n>>m;
    vector<vector<int>> adl(n+1);
    vector<bool> vis(n+1,false);
    for (i=0;i<m;i++){
        cin>>x>>y;
        adl[x].push_back(y);
        adl[y].push_back(x);
    }
    int si;
    vector<int> ans;
    for (i=1;i<n+1;i++){
        if (!vis[i]){
           si=0;
           cc++; 
           markcon(i,adl,vis,si);
          ans.push_back(si);
        }
    }
    cout<<endl<<"elements= ";
    for (i=0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
    }
    cout<<endl;
    int su=0;
    //for friends count
    int k=0;
    for (i=0;i<ans.size();i++){
        k+=ans[i];
        su+=ans[i] * (n-k);
    }
    cout<<"ways= "<<su;
    return 0;
}