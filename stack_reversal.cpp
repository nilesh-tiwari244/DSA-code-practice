#include<iostream>
#include<stack>
using namespace std;

void addelementatbottom(stack<int>& s,int val)
{if(s.empty())
{s.push(val);
return;
}
int b=s.top();
s.pop();
addelementatbottom(s,val);
s.push(b);
return;
}

void reversestack(stack<int>& s)
{if (s.empty())
return;
int a=s.top();
s.pop();
reversestack(s);
addelementatbottom(s,a);
return;
}

int main()
{stack <int> s;
for (int i=1;i<8;i++)
s.push(i);
cout<<"stack is="<<endl;
stack <int> kkk;
while(!s.empty())
{cout<<s.top()<<endl;
s.pop();
}
s=kkk;
reversestack(s);
cout<<endl;
cout<<"reversed stack is="<<endl;
while(!s.empty())
{cout<<s.top()<<endl;
s.pop();
}
    return 0;
}