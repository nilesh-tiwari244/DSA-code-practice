#include<iostream>
#include<vector>
using namespace std;
void arrange(vector<int> &A) {
    int i,j,n,pp;
    n=A.size();
    for (i=0;i<n;i++){
        if (A[i])
        for (j=0;j<n;j++){
            if (A[j]==i)
            {if (j>=i){
                cout<<i<<endl;
            A[j]=A[i];
            A[i]=A[A[i]];
           cout<<i<<" pe "<<A[i]<<"  "<<j<<" pe "<<A[j]<<endl;
            }
             break;
            }
        }

        //4 0 2 1 3

        //3 4 2 0 1
    }
    return;
}
 int main(){

     vector<int> v={4,0,2,1,3};
     arrange(v);
     for (int i=0;i<v.size();i++)
     cout<<v[i]<<" ";
     return 0;

 }