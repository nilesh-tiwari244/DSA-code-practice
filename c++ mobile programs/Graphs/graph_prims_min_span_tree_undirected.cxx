#include<iostream>
#include<set>
#include<vector>
using namespace std;

set<vector<int>> ss;
vector<bool> vis;
vector<vector<vector<int>>> adl;
vector<vector<vector<int>>> ans;

void prims(int sou){
for (auto i=0;i<adl[sou].size();i++){
    if (!vis[adl[sou][i][2]])
        ss.insert({adl[sou][i][0],adl[sou][i][1],adl[sou][i][2]});
}
    set<vector<int>> :: iterator it,it1,it2;
    if (!ss.empty()){
        it=ss.begin();
        if (!vis[(*it)[2]]){
            vis[(*it)[2]]=true;
            ans[(*it)[1]].push_back({(*it)[2],(*it)[0]});
           int gg=(*it)[2];
           it1=ss.begin();
            while(it1!=ss.end()){
                it2=it1;
                it1++;
                if ((*it2)[2]==gg)
                    ss.erase(it2);
            }                                                             
            prims(gg);
        }
    }
    else
        return;
}
int main(){
    int n,m,x,y,i,j,w;
    cin>>n>>m;         
    vector<bool> vii(n+1,false);                      
    vis=vii;                                                                vector<vector<vector<int>>> al(n+1);           adl=al;  
    ans=al;                                                               for (i=0;i<m;i++)
        {cin>>x>>y>>w;
        adl[x].push_back({w,x,y});
        adl[y].push_back({w,y,x});
        }                                                                      vis[1]=true;                                                        prims(1);   
    cout<<endl<<endl;
    for (i=1;i<n+1;i++){
        for (j=0;j<ans[i].size();j++){
            cout<<i<<"  "<<ans[i][j][0]<<"  "<<ans[i][j][1]<<endl;
        }
    }
    return 0;
}
/*

4 5
1 2 10
1 3 5
2 3 15
2 4 2
3 4 40 

*/      