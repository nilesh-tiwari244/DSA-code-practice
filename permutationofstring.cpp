#include<iostream>
#include<string>
using namespace std;
void substrings(string str,string ch)
{int n=str.length();
if(n==0)
    {cout<<ch<<endl;
    return;
    }
int i;
for (i=0;i<n;i++)
{substrings(((str.substr(0,i))+(str.substr(i+1,n-i-1))),ch+str[i]);
}

}

int main()
{
cout<<"enter no. of elements=";
string str;
int i;
cin>>i;
cin.ignore();
getline(cin,str);
substrings(str,"");
    return 0;
}