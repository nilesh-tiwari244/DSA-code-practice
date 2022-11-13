#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,i,j,x,y,w,m,a;
    cin>>n>>m;
    vector<int> k(n+1,1e9);
    vector<vector<int>> adm(n+1,k);
    for (i=0;i<m;i++){
            cin>>x>>y>>w;
            adm[x][y]=w;
    }
    for (i=1;i<n+1;i++)
    adm[i][i]=0;
      
    for (a=1;a<n+1;a++){
        for (i=1;i<n+1;i++){
            for (j=1;j<n+1;j++){
                if (adm[i][a]+adm[a][j] < adm[i][j])
                    adm[i][j]=adm[i][a]+adm[a][j];
            }
        }
    }
      for (i=1;i<n+1;i++){
            for (j=1;j<n+1;j++){
                if (adm[i][j]!=1e9)
                cout<<adm[i][j]<<"  ";
                else
                cout<<"-1"<<"  ";
            }
            cout<<endl;
      }
      return 0;
}

/*
4 4
1 2 5
1 4 10
2 3 3
3 4 1






*/