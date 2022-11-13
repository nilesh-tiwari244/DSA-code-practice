#include<iostream>
using namespace std;

bool check(int a[],int n,int m,int x){
    int i,su=0;
    for (i=0;i<m;i++){
        su+=a[i];
    }
    //cout<<su<<endl;
    if (su>=x)
    return true;
    int lo,hi;
    lo=0;
    hi=m-1;
    i=m;
    while (i<n){
        su=su+a[i]-a[i-m];
        //cout<<su<<endl;
        if (su>=x)
        return true;
        i++;
    }
    return false;
}
        

int minsubarray(int a[],int n,int x){//O(nlogn)
    int lo=0,hi=n,mi,ans=-1;
    if (!check(a,n,n,x))
    return -1;
    while (lo<hi){
        mi=lo+(hi-lo)/2;
        //cout<<"trial mi= "<<mi<<endl;
        if (check(a,n,mi,x))
            {hi=mi-1;
            ans=mi;
            //cout<<endl<<"poss= "<<mi;
            }
        else
            lo=mi+1;
}
cout<<endl;
return ans;
}


int minsubopt(int a[],int n,int x){//this is an optimum way O(n) of finding this 
    int lo,hi,su=0,ans=INT_MAX;
    lo=-1;
    hi=-1;
    while ((lo<=hi)&&(hi<=n-1)){
        while ((su<x)&&(hi<n)){
            hi++;
            su+=a[hi];
        }
        if(su>=x)
        ans=min(ans,hi-lo);
        while ((su>=x)&&(lo<=hi)){
            lo++;
            su-=a[lo];
        }
       // cout<<hi<<"  "<<lo<<endl;
        if (su+a[lo]>x)
        ans=min(ans,hi-lo+1);
    }
    cout<<endl;
    return ans;
}
int main(){
    int n=7;
    int x=6;
    int a[]={1,2,3,3,4,7,1};
    cout<<minsubarray(a,n,x);
    cout<<endl;
    cout<<minsubopt(a,n,x);
    return 0;
}