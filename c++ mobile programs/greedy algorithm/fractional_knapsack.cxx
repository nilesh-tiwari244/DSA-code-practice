//#include<bitsstd/c++.h>
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int maxval(vector<pair<int,int>> vp,int x){
     int i,k,tan,an=0,n=vp.size(),moo;
     if (x<=0)
     return 0;
     
    if (n==1){
        if(vp[0].second > x)
        return 0;
        else
        return vp[0].first;
    }
    
  vector<pair<int,int>> pp;
    i=0;
    while (i<n){
        pp.clear();
        tan=0;
        if (vp[i].second<=x){
            
        for (k=0;k<n;k++){
            if (k!=i)
        pp.push_back(vp[k]);
        }
        moo=maxval(pp,x-(vp[i].second));
         tan=vp[i].first+moo;
          if (n==5)
        {
        cout<<endl<<"ele= "<<pp[i].first<<endl;
        cout<<tan<<endl;
        }
       
        }
        i++;
        an=max(tan,an);
        
        }
    return an;
}
int main(){
    vector<pair<int,int>> vp;
    int x=20;
    vp={make_pair(21,7),make_pair(24,4),make_pair(12,6),make_pair(40,5),make_pair(30,6)};
    cout<<endl<<maxval(vp,x);
    return 0;
}