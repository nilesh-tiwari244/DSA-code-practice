#include<iostream>
#include<vector>
using namespace std;
bool check(int a[],int n,int m,int d){
    int i=0;
    int pp=0;
    int s;
    while ((i<m)&&(pp<n)){
        s=0;
        while (s<=d){
             if (pp>n)
             return true;
             s+=a[pp];
             pp++;
        }
        pp--;
        i++;
    }
    if (pp<n)
    return false;
    else
    return true;
}
int allo_min(int a[],int n,int m){
    int min;
    if (m>n)
    return -1;
    
    int l=0;
    int i,h=0;
    for (i=0;i<n;i++)
    h+=a[i];
    
    int ch,pp; 
     ch=(l+h)/2;
    while ((l<h)&&(l!=ch)&&(h!=ch)){
        if(check(a,n,m,ch)){
            h=ch;
            pp=ch;
        }
        else
            l=ch;
            ch=(l+h)/2;
           // cout<<l<<"  "<<h<<endl;
           // cout<<endl<<ch<<endl;
    }
    return pp;
}

int main(){
    int n=4;
    int m=3;
    int a[]={12,34,67,90};
    int minpage=allo_min(a,n,m);
    cout<<minpage<<endl;l
    cout<<"HELLO";
  //cout<<check(a,n,m,70);
    return 0;
}