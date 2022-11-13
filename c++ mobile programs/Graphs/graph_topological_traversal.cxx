#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n,m,i,j,x,y;
    map<int,int> mp;
    cin>>n>>m;
    vector<bool> vis(n+1,false);
    vector<vector<int>> adl(n+1);
    for (i=1;i<=m;i++){
        cin>>x>>y;
        mp[y]++;
        mp[x]+=0;
        adl[x].push_back(y);
    }
     vector<int> te;
    map<int,int> :: iterator it;
   while (1){
       te.clear();
   for (it=mp.begin();it!=mp.end();it++){
        if (it->second==0)
        {te.push_back(it->first);
        }}
   if (te.size()<1)
   break;
   for (i=0;i<te.size();i++){
            cout<<te[i]<<endl;
            mp[te[i]]=-1;
        for(j=0;j<adl[te[i]].size();j++)
        {mp[adl[te[i]][j]]--;
        }}}
    return 0;
}