#include<iostream>
#include<string>
using namespace std;
string remcop(string str)
{int n=str.length();
if (n==1)
return str;

string k;
k=remcop(str.substr(1));
if (str[0]==k[0])
return k;
else
return (str[0]+k);
}
int main()
{string hh="aabcdddeeeeeffg";
hh=remcop(hh);
cout<<hh;
return 0;
}
