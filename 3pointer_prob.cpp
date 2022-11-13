#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int i,j,st,en,d,n=A.size();


    vector<int> c={abs(B-(A[0]+A[1]+A[n-1])),(A[0]+A[1]+A[n-1])};

    for(i=0;i<n-2;i++){
        cout<<i<<"  "<<c[0]<<endl;
        st=i+1;
        en=n-1;
        d=A[i];
        while((en>st)&&(en<n)){
            
            if (d+A[st]+A[en] < B){
                st++;
                if ((abs(B-(d+A[st]+A[en]))<c[0])&&(st<en))
                    c={abs(B-(d+A[st]+A[en])),(d+A[st]+A[en])};
            }
            else if (d+A[st]+A[en] > B){
                en--;
                if ((abs(B-(d+A[st]+A[en]))<c[0])&&(st<en))
                    c={abs(B-(d+A[st]+A[en])),(d+A[st]+A[en])};
            }
            else
            return B;
        }
    }
    return c[1];
}
int main(){
   /*
    vector<vector<int> > A={{8,5},{0,4},{3,6}};
    int B=3;
*/
    /*
    vector<int> A={-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3 };
    int B=-1;
    */

    vector<int> A={ -10, -10, -10  }; //-4 -1 1 2
    int B=-5;

   cout<<threeSumClosest(A,B);
   cout<<endl<<"running fine";
    return 0;
}
