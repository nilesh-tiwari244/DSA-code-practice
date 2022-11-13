#include<iostream>
#include<string>
using namespace std;
void replpi(string str)
{int n=str.length();
string s1;
if (n==1)
{cout<<str[0];
return;
}
if ((str[0]=='p') && (str[1]=='i'))
{cout<<"3.14";
s1=str.substr(2);
replpi(s1);
return;
}
else
{cout<<str[0];
s1=str.substr(1);
replpi(s1);
return;	
}
}

int main()
{string s1="mynamepipispipinip";
replpi(s1);
return 0;
}