#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int maxi(int a[],int n){
    int i,ans=0;
    for (i=0;i<n/2;i++)
        ans+=a[n-1-i]-a[i];
   return ans;   
}

int mini(int a[],int n){
    int i,ans=0;
    for (i=0;i<n-1;i=i+2)
    ans+=a[i+1]-a[i];
    return ans;   
}

int main(){
   int n,i;
   cin>> n;
    int a[n];
    for (i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    cout<<"min= "<<mini(a,n);
    cout<<endl<<"maxi= "<<maxi(a,n);
    return 0;
}