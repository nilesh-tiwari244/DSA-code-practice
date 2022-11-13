#include<iostream>
using namespace std;
void printasc(int n)
{if (n==1)
{cout<<n<<" ";
return;}
cout<<n<<" ";
printasc(n-1);
return;
}

int main()
{int n;
cout<<"enter last digit";
cin>>n;
printasc(n);
return 0;


}