#include<iostream>
#include<set>
#include<vector>
using namespace std;
vector<vector<vector<int>>> adl;
set<int> ss;
vector<int> dis;

void dijik(int st){
    int gg;   
        ss.insert(st);
        for (auto i=0;i<adl[st].size();i++){
            dis[adl[st][i][2]]=min(adl[st][i][0],dis[adl[st][i][2]]);
            ss.insert(adl[st][i][2]);
        }
       set<int> :: iterator it;
        while(!ss.empty()){
        gg=(*ss.begin());
        ss.erase(ss.begin());
        for (auto i=0;i<adl[gg].size();i++){
            if ((dis[gg]+adl[gg][i][0])<dis[adl[gg][i][2]]){
                ss.insert(adl[gg][i][2]);
                dis[adl[gg][i][2]]=dis[gg]+adl[gg][i][0];                
        }
        }
        }
  return;    
}

int main(){
    int i,j,n,m,x,y,w,st;
    cin>>n>>m;
    vector<vector<vector<int>>> ad(n+1);
    vector<int> sd(n+1,INT_MAX);
    adl=ad;
    dis=sd;
    for(i=0;i<m;i++){
        cin>>x>>y>>w;
        adl[x].push_back({w,x,y});
        adl[y].push_back({w,y,x});
    }
    cin>>st;
    dis[st]=0;
    dijik(st);
    for (i=1;i<n+1;i++){
        cout<<dis[i]<<"  ";
    }   
return 0;    
}

/*

4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

*/