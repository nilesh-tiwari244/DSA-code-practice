#include<iostream>
#include<string>
using namespace std;

string movexend(string str)
{int n=str.length();
if (n==1)
{return str;
}
string k=movexend(str.substr(1));
if (str[0]== 'x')
return (k+'x');
else
return (str[0]+k);
}

int main()
{string kk="myxbhxhdxxgg";
cout<<movexend(kk);
return 0;
}