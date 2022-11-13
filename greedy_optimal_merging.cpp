#include<iostream>
#include<vector>
#include <queue>
#include<map>
using namespace std;
int minmer(int a[],int n){
    int i,min=0,k1,k2;
    priority_queue<int,vector<int>,greater<int>> pp;
    for(i=0;i<n;i++)
    pp.push(a[i]);
    while(pp.size()>1){
        k1=pp.top();
        pp.pop();
        k2=pp.top();
        pp.pop();
        min+=k1+k2;
        pp.push(k1+k2);
    }
    return min;
}
int main(){
    int a[4]={5,4,2,7};
    cout<<endl<<minmer(a,4);
    return 0;  
}