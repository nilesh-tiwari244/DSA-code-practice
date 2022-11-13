#include<iostream>
#include<vector>
using namespace std;

bool checklo(int n,vector<vector<int>>adl,vector<bool> &vis,int f){
    int i,p1;
    vis[n]=true;
    for(i=0;i<adl[n].size();i++){
        p1=adl[n][i];
        if ((vis[p1])&&(p1==f))
            return true;
        else if (checklo(p1,adl,vis,f))
            return true;
    }
    return false;
}
int main(){
    int n,m,i,j,x,y;
    cin>>n>>m;
    vector<vector<int>> adl(n+1);
    vector<bool> vis(n+1,false);
    for(i=0;i<m;i++){
        cin>>x>>y;
        adl[x].push_back(y);
    }
    for(i=1;i<n+1;i++){ //checks loop for disjointed graphs too
        if ((!vis[i]) && (checklo(i,adl,vis,i))){ //starts only if not visited yet
            cout<<"loop is there";
            return 0;}}
    cout<<"loop is not there";
    return 0;
}

/*

7 7
1 2
3 1
2 4
2 5
2 6
2 7
7 3

7 7
1 2
1 3
2 4
2 5
2 6
2 7
7 3

4 4
2 1
1 3
1 4
4 2

4 3
1 2
1 3
1 4

*/