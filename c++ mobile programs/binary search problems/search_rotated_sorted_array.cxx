#include<iostream>
using namespace std;
int find(int a[],int lo,int hi,int k){
        cout<<lo<<" "<<hi<<endl;
    int x,mi;
      mi=(lo+hi)/2;
      if ((lo==hi)&&(a[lo]!=k))
      return -1;
      if (lo>hi)
      return -1;
      if ((hi-lo==1)&&(a[lo]!=k)&&(a[hi]!=k))
      return -1;
      if (a[mi]==k)
      return mi;
      if (a[lo]==k)
      return lo;
      if (a[hi]==k)
      return hi;
      
  
      
    if (k>a[lo]  &&  k>a[hi]){
      if ((a[mi]<k)&&(a[mi]>a[hi])){
          return find(a,mi,hi,k);
      }
      else {
              return find(a,lo,mi,k);
      }
    }
    else if ((k<a[lo])  &&  (k<a[hi])){
           if ((a[mi]>k)&&(a[mi]<a[hi])){
          return find(a,lo,mi,k);
      }
      else{
              return find(a,mi,hi,k);
      }
    }
    else{
          if (a[mi]>k)
          return find(a,lo,mi,k);
          else
          return find(a,mi,hi,k);    
    }     
    }
    
    
int main(){
    int n=11;
    int a[]={4,7,9,14,17,21,26,35,1,2,3};
    cout<<find(a,0,n-1,35);
    return 0;
}
    