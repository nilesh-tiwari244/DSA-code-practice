#include<iostream>
#include<vector>
#include<map>
using namespace std;
int kthfrequent(int a[],int n,int p){
    int i;
    map<int,int> mp;
    for (i=0;i<n;i++){
        mp[a[i]]++;
    }
    map<int,int> :: iterator it;
    map<int,vector<int>> rev;
    for (it=mp.begin();it!=mp.end();it++){
        rev[it->second].push_back(it->first);
        cout<<it->first<<"   "<<it->second<<endl;
    }
    cout<<endl;
    int k=0,ans=0;
    map<int,vector<int>> ::iterator itt;
    for (itt=rev.begin();itt!=rev.end();itt++){
        k++;
        cout<<itt->first<<" - ";
        for (i=0;i<(itt->second).size();i++)
        cout<<(itt->second)[i]<<" ";
        cout<<endl;
        if (k==p)
        ans=itt->first;
    }cout<<endl;
    return ans;
}
int main(){
    int n=7;
       int a[]={1,3,2,3,2,2,5};
    cout<<kthfrequent(a,n,3);
    return 0;
}