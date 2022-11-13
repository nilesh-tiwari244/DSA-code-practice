#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int main(){
    map<int,int> ma;
    int i,j,la,k,sn,co=0,x,y,z,w;
    cin>>la>>sn;
    for (i=0;i<la;i++)
    {cin>>x>>y;
    ma[x]=y;
    }
      for (i=0;i<sn;i++)
    {cin>>z>>w;
    ma[z]=w;
    }
    queue<int> q;
    q.push(1);
    bool ff=false;
    vector<bool> vis(101,false);
    vis[1]=true;
    while (!q.empty() && !ff){
       int io=q.size();
       while (io--){
       j=q.front();
       q.pop();
       i=1;
       while ((i<7) && (j+i<101)){
            k=j+i;
            if (ma[k])
            k=ma[k];
            if (!vis[k]){
                vis[k]=true;
                if (k==100){
                ff=true;
                break;
                }
                q.push(k);
            }
            i++;
       }
       }
       co++;
    }
    if (ff)
    cout<<"co="<<co; 
    else 
    cout<<"not possible";
      return 0;  
    }
    
    