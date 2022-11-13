#include<iostream>
#include<algorithm>
using namespace std;

int maxsumarrx(int a[],int n,int k,int x){
    int lo=0;
    int hi=k-1;
    int sl=0,sr=0;
    int i=0;
    int su=0;
    int maxi=0;
    while(i<k)
    {su+=a[i];
    i++;
    }
    if (su<=x)
  maxi=max(su,maxi);
    i=1;
    lo=0;
    hi=k-1;
    while (i<=n-k){
          sl+=a[lo+i-1];
        sr+=a[hi+i];
        if ((su+sr-sl<x)&&(su+sr-sl>maxi))
        {
                maxi=su+sr-sl;
                su=maxi;
                lo=i;
                hi=i+k-1;
                sr=0;
                sl=0;
        }
        i++;
    }
    cout<<"indexes= "<<lo<<"  "<<hi<<endl;
return maxi;
}
int main(){
    int n=6,k=3,x=20;
    int a[]={7,5,4,6,8,9};
    cout<<endl;
    cout<<"ans= "<<maxsumarrx(a,n,k,x);
    return 0;
}