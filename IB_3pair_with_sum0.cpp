#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > threeSum(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int>> sol;
    long long a,st,en,b,c,i,j,k,n=A.size(),pp=0;
    long long su;
    for(i=0;i<n-2;i++){
        a=A[i];
        st=i+1;
        en=n-1;
        while(st<en){
            su=a+A[st]+A[en];
            cout<<i<<"  "<<su<<"   "<<st<<"  "<<en<<endl;
            if (su>0){
                while((A[en]==A[en-1])&&(st<en))
                en--;
                en--;
                if ((st<en)&&(a+A[st]+A[en]==0)){
                    if ((pp!=0)&&(sol[pp-1][1]!=A[st])){
                    sol.push_back({a,A[st],A[en]});
                    pp++;
                }}
            }
            else if (su<0){
                while((A[st]==A[st+1])&&(st<en))
                st++;
                st++;
                if ((st<en)&&(a+A[st]+A[en]==0)){
                if ((pp!=0)&&(sol[pp-1][1]!=A[st])){
                    sol.push_back({a,A[st],A[en]});
                    pp++;
                }}
            }
            else{

                //if ((pp!=0)&&(sol[pp-1][1]!=A[st])){
                sol.push_back({a,A[st],A[en]});
                //pp++;
                //}
                while((A[en]==A[en-1])&&(st<en))
                en--;
                en--;
                while((A[st]==A[st+1])&&(st<en))
                st++;
                st++;
            }
        }
        while((A[i]==A[i+1]) && (i<n-3))
            i++;
    }
    return sol;
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
    vector<int> A={ 2147483647, -2147483648, -2147483648, 0, 1 }; //-4 -1 1 2
    //-214  -214  0   1   2147
    vector<vector<int>> sol=threeSum(A);
    for(int i=0;i<sol.size();i++){
        for (int j=0;j<3;j++){
            cout<<sol[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}