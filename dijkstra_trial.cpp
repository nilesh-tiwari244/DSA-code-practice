#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
vector<int> dis;
bool operator<(const pair<int,int> &p1,const pair<int,int> &p2){
    return p1.second<p2.second;
}
void dijktra(int st,vector<vector<vector<int>>> &edge){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (auto i=0;i<edge[st].size();i++){
        dis[edge[st][i][1]]=min(dis[edge[st][i][1]],edge[st][i][0]);
        pq.push(make_pair(edge[st][i][1],dis[edge[st][i][1]]));
    }
    while (!pq.empty()){
        auto j=pq.top();
        pq.pop();
        for (auto i=0;i<edge[j.first].size();i++){
            if (dis[edge[j.first][i][1]]>dis[j.first] + edge[j.first][i][0]){
                dis[edge[j.first][i][1]]=dis[j.first] + edge[j.first][i][0];
                pq.push(make_pair(edge[j.first][i][1],dis[edge[j.first][i][1]]));
            }
        }
    }
    return ;
}
int main(){
    int n,m,i,j,a,b,w,st;
    cout<<"enter no. of vetexes and edges= "<<endl;
    cin>>n>>m;
    cout<<"enter source node= "<<endl;
    cin>>st;
    vector<vector<vector<int>>> edge(n);
    cout<<endl<<" the edges with weights= "<<endl;
    for(i=0;i<m;i++){
        cin>>a>>b>>w;
        edge[a].push_back({w,b});
        edge[b].push_back({w,a});
    }
    for (i=0;i<n;i++){
        cout<<i<<" - ";
        for(j=0;j<edge[i].size();j++){
            cout<<"( "<<edge[i][j][1]<<" "<<edge[i][j][0]<<" ) ";
        }
        cout<<endl;
    }
    dis=vector<int> (n,INT_MAX);
    dis[st]=0;
    dijktra(st,edge);
    for (i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}

