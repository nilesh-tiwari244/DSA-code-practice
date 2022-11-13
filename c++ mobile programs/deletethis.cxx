#include<iostream>
#include<vector>
using namespace std;
void arrange(vector<int> &A) {
    int i,j,n,pp,qq,zz,hg,k,nn;
    n=A.size();
    for (i=0;i<n;i++){
    pp=A[i];
    A[i]=A[pp];
         for (j=i+1;j<n;j++){
             if (A[j]==i){
                  nn=A[j];
                  A[j]=pp;
                 break;
             }
         }
         
         if (j!=pp){
         for (int hg=0;hg<n;hg++){
             if (A[hg]==j){
                 qq=A[hg];
                 A[hg]=i;
             }
         }
         }
         
 /*
            for (int hg=0;hg<n;hg++){
             if (A[hg]==j){
                 if (hg>i)
*/   
         for (int hhh=0;hhh<n;hhh++)
         cout<<A[hhh]<<" ";
         cout<<endl;
    }       
    return;
}
 int main(){

//vector<int> v={4,3,1,5,0,2};//0 5 3 2 4 1   
        
        /*    0 3 1 5 4 2       0 index
               0 5 3 5 4 2       1 index
               0 5 3 2              
       */    
  vector<int> v={4,0,2,1,3};//3 4 2 0 1
  
     arrange(v);
  //   for (int i=0;i<v.size();i++)
 //    cout<<v[i]<<" ";
     return 0;

 }