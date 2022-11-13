#include<iostream>
#include<vector>
#include<map>
using namespace std;
int fact(int n){
    int k=1,i;
    if (n<1)
    return 1;
    for(i=1;i<=n;i++)
    k=k*i;
    return k;
}
int combi(int n,int k){
    if(n<k)
    return 0;
    return (fact(n)/(fact(k)*fact(n-k)));
}
    
int countsumzerosubarray(int a[],int n){
    int i,sz=0,s;
    cout<<a[0]<<" ";
    for (i=1;i<n;i++){
        if (a[i]==0)
        sz++;
        a[i]=a[i-1]+a[i];       
        cout<<a[i]<<" ";
    }
    cout<<endl;
    map<int,int> mp;
    for (i=0;i<n;i++){
        mp[a[i]]++; 
    }
    s=0;
    map<int,int> :: iterator it;
    for (it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<"  "<<it->second;
        cout<<endl;
        if (it->first!=0)
       s+=combi(it->second,2);
       else
        s+=combi(((it->second)+1),2);
    }
    return s;
}
int main(){
  //  int n=7;
//    int a[]={1,-1,1,-1,0,-1,1};
    int n=4;
       int a[]={1,-1,1,-1};
    cout<<countsumzerosubarray(a,n);
    return 0;
}