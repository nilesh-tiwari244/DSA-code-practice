//#include<bitsstd/c++.h>
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
bool comp(pair<int,int> i,pair<int,int> j)
{return i.second<j.second;
}
int jobperf(vector<pair<int,int>> vp){
    int i,cen,an=1,n=vp.size();
    sort(vp.begin(),vp.end(),comp);
    cen=vp[0].second;
    i=1;
    while (i<n){
        if (vp[i].first>cen)
       { cen=vp[i].second;
       an++;
       }
       i++;
    }
    return an;
}
int main(){
    vector<pair<int,int>> vp;
    vp={make_pair(10,25),make_pair(5,7),make_pair(22,32)};
    cout<<endl<<jobperf(vp);
    return 0;
}