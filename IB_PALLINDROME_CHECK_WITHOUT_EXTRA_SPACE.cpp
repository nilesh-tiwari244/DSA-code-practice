#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int isPalindrome(int A) {
    if(A==0)
    return 1;
    if (A<0)
    return 0;
    int b,d,k,g,i;
    b=A;
    d=0;
    while(b>0){
        b=b/10;
        d++;
    }
    cout<<d<<endl;
    k=pow(10,d-1);
    g=10;
    cout<<k<<" "<<g<<endl;
    for(i=1;i<=d/2;i++){
        if ((A/k)!=(A%g)) //9 9
        return 0;
        A=A%k;//229
        A=A/g;//22
        k=k/100;//10
    }
    return 1;
}
int main(){
    int a=2147447412;
    int n=isPalindrome(a);
        cout<<n;
    
    return 0;
}
