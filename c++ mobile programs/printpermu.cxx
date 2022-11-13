#include<iostream>
#include<string>
using namespace std;
void printpermu(string a,string b)
{int i,n;
n=a.length();
if (n==0)
{cout<<b<<endl;
return;
}
    for (i=0;i<n;i++)
    {
    string kp=a;
  string k=b+a[i];
    kp.erase(i,1);
        printpermu(kp,k);
        
    }
    return;
    
    
    
}

int main()
{string A="abcd";
string B="";
printpermu(A,B); 
return 0;
}
