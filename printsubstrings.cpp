#include<iostream>
#include<string>
using namespace std;
void substrings(string str,string ch)
{int n=str.length();
if(n==0)
    {cout<<ch<<endl;
    return;
    }char cg=str[0];
    string k=str.substr(1);
substrings(k,ch);
substrings(k,ch+cg);

}

int main()
{
cout<<"enter no. of elements=";
string str;
getline(cin,str);
substrings(str,"");
    return 0;
}