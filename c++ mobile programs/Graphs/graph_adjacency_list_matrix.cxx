#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m,i,x,y,j;
    cin>>n>>m;
    //for adjacency matrix
    vector<vector<int>> adm(n+1,vector<int> (n+1,0));
    //as node names start from 1 not zero
    cout<<"enter adjacency matrix edges"<<endl;
    for (i=1;i<=m;i++){
        cout<<"enter edges  "<<i<<endl;
        cin>>x>>y;
        adm[x][y]=1;
        adm[y][x]=1;
    }
    for(i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            cout<<adm[i][j]<<" ";
        }
        cout<<endl;
    }
    //for adjacency list
    vector<int> adl[n+1];
      cout<<"enter adjacency list edges"<<endl;
      for (i=1;i<=m;i++){
        cout<<"enter edges  "<<i<<endl;
        cin>>x>>y;
        adl[x].push_back(y);
        adl[y].push_back(x);

    }
     for (i=1;i<=n;i++){
        cout<<i<<"-> ";
        for(j=0;j<adl[i].size();j++){
            cout<<adl[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}