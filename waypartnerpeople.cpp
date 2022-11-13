#include<iostream>
using namespace std;
 
 int waypartnerpeople(int n)
 {
 if (n<=0)
 return 0;
 if (n==1)
 return 1;
 if (n==2)
 return 2;
 return (waypartnerpeople(n-1) +((n-1)* (waypartnerpeople(n-2) ) ));
 }

 int main()
 {int n;
 cout<<"enter number of people present=";
 cin>>n;
 cout<<waypartnerpeople(n);
 }