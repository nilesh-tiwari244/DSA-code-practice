#include<iostream>
#include<string>
using namespace std;

void hanoi(int n, char so,char he,char de)
{if (n==1)
    {cout<<"move from "<<so<<" to "<<de;
    cout<<endl;
    return;
    }
 hanoi(n-1,so,de,he);
 cout<<"move from "<<so<<" to "<<de;
 cout<<endl;
 hanoi(n-1,he,so,de);
    return;
}

int main()
{hanoi(5,'A','B','C');
return 0;
}