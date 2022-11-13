#include<iostream>
#include<string>
using namespace std;
void revo(string str,int n)
{if (n==1)
{cout<<str[n-1];
return;
}
cout<<str[n-1];
revo(str,n-1);
}

int main()
{int n;
string str;
cout<<"enter size of string";

cin>>n;
cout<<"\n";
cout<<"enter string";

cout<<endl;

getline(cin,str);
getline(cin,str);
revo(str,n);
cout<<str;
return 0;
}