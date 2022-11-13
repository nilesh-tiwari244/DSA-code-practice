#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

bool operator < (const pair<int,int>  &pp,const pair<int,int> &qq){
    return (pp.first<qq.first);
}

vector<int> mergeksorted(vector<vector<int>> a){
    vector<int> v;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pp; //making min heap priority queue
    int i,k=a.size();
    int index[k]={0};
    int arr,sizee[k];
    pair<int,int> pa;
    for(i=0;i<k;i++)
    sizee[i]=a[i].size();

    for (i=0;i<k;i++){
    pp.push(make_pair(a[i][index[i]],i));
    }

    while(!pp.empty()){
    pa=pp.top();
    pp.pop();
    arr=pa.second;
    v.push_back(pa.first);
    if ((index[arr]+1)<sizee[arr]){
        index[arr]+=1;
        pp.push(make_pair(a[arr][index[arr]],arr));
    }
    }
    return v;
}
int main(){
int i;
int k=3;
vector<int> qq;
vector<vector<int>> pp(k);
pp[0]={1,3,5,7,9};
pp[1]={2,4,6};
pp[2]={8,10,12,13,16,18,19};
qq=mergeksorted(pp);
for (i=0;i<qq.size();i++)
cout<<qq[i]<<" ";
return 0;
}
