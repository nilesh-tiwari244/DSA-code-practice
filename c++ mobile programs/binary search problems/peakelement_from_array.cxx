#include<iostream>
using namespace std;
int peakelement(int a[],int lo,int hi){
    int mi=lo+(hi-lo)/2;
    
    if ((a[mi]>a[mi+1])&&(mi==lo))
    return a[mi];
    else if (mi==lo)
    return peakelement(a,lo+1,hi);
    
     if ((a[mi]>a[mi-1])&&(mi==hi))
    return a[mi];
    else if(mi==hi)
    return peakelement(a,lo,mi-1);
    
    if ((a[mi]>a[mi-1])&&(a[mi]>a[mi+1]))
    return a[mi];
    else if (a[mi]>a[mi-1])
    return peakelement(a,mi,hi);
    else if (a[mi]>a[mi+1])
    return peakelement(a,lo,mi);
    else{
        if (peakelement(a,mi,hi)!=-1)
        return peakelement(a,mi,hi);
        else if(peakelement(a,lo,mi)!=-1)
        return peakelement(a,lo,mi);
        else
        return -1;
}
}

int main(){
    int n=7;
    int a[]={1,2,3,2,4,7,8};
    cout<<peakelement(a,0,n-1);
    return 0;
}