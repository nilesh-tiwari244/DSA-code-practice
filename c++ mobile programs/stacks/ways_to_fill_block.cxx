#include<iostream>
using namespace std;

int wayblockpos(int n)
{if (n<0)
return 0;
if (n==0)
return 1;

int s= wayblockpos(n-1) +wayblockpos(n-2);
return s;
}

int main ()
{int n;
cout<<"enter n= ";
cin>>n;
cout<<endl<<wayblockpos(n);
return 0;
}
