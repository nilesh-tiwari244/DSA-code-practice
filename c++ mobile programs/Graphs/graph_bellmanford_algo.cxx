#include<iostream>
#include<vector>
using namespace std;
const int inf=1e9 +2;
int main(){
    int i,j,x,y,w,n,m,k,x1,y1,w1;
    cin>>n>>m;
    vector<vector<int>> edge;
    vector<int> dis(n+1,inf);
    for (i=0;i<m;i++){
        cin>>x>>y>>w;
        edge.push_back({x,y,w});
    }
    cin>>k;
    dis[k]=0;
    for (i=1;i<=n-1;i++){
        for (j=0;j<m;j++){
            x1=edge[j][0];
            y1=edge[j][1];
            w1=edge[j][2];
            dis[y1]=min(dis[y1],w1+dis[x1]);  
        } 
    }
    for (i=1;i<n+1;i++)
    cout<<dis[i]<<"  ";
    return 0;
}
/*

5 8
2 3 3
4 3 5
2 4 2
4 2 1
2 5 2
1 3 4
5 4 -3
1 2 -1
1
 
 0 -1 2 -2 1

4 4
1 2 24
1 3 3
1 4 20
3 4 12
1

0 24 3 15

*/
    