#include<iostream>
using namespace std;
void printdec(int n)
{if (n==1)
{cout<<n<<" ";
return;
}
printdec(n-1);
cout<<n<<" ";
return;
}

int main()
{int n;
cout<<"enter last digit";
cin>>n;
printdec(n);
return 0;


}