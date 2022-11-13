#include<iostream>
using namespace std;

int maxsumarrx(int a[],int n,int k,int x){
    int lo=0;
    int hi=k-1;
    int sl=0,sr=0;
    int i=0;
    int su=0;
    int maxi=0;
    while(i<k)
    su+=a[i];
    if (su<=x)
    maxi=max(su,max);
    i=k;
    while (i<n){
        if (su+sr-sl<x)
        {
            if (su+sr-sl>maxi){
                
            }
        }
        sr+=a[i];
    }

}
int main(){
    int n=7,k=4,x=21;
    int a[]={1,2,4,5,7,4,2,22};
    cout<<maxsumarrx(a,n,k,x);
    return 0;
}