#include<iostream>
using namespace std;

int checkperf(int n){
    if (n<=5)
    return 0;
    int i,su=0;
    for (i=1;i<n;i++){
        if (n%i==0)
        su+=i;
    }
    if (su==n)
    return 1;
    else
    return 0;
}
int maxperf(int a[],int n,int k){
    int i,su=0,ma=INT_MIN;
    for (i=0;i<n;i++)
    {a[i]=checkperf(a[i]);
    }
    for (i=0;i<k;i++){
        su+=a[i];
    }
    ma=max(su,ma);
    for (i=k;i<n;i++){
        su=su+a[i]-a[i-k];
        ma=max(ma,su);
    }
    return ma;
}
    
int main(){
    int n=8,k=4;
    int a[]={28,2,3,6,496,99,8128,24};
    cout<<endl;
    cout<<maxperf(a,n,k);
    return 0;
    }