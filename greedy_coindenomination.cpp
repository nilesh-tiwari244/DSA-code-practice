#include<iostream>
#include<vector>
#include<map>
using namespace std;


map<int,int> coinfind(vector<int> v,int x){
    map<int,int> vp;
    int i;
    while(x>0){
    for(i=v.size()-1;i>=0;i--){
        if (v[i]<=x)
        {vp[v[i]]++;
        x=x-v[i];
        break;
    }
    }
    }
    return vp;
}
int main(){
    int x=7888,i;
    vector<int> v={1,2,5,10,20,50,100,200,500,2000};
    map<int,int> vp=coinfind(v,x);
    map<int,int> :: iterator it;
    for(it=vp.begin();it!=vp.end();it++){
        cout<<it->first<<"  "<<it->second<<endl;
    }
    return 0;  
}