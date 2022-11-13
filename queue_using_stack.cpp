#include<iostream>
#include<stack>
using namespace std;
class queue{
public:
stack <int> st1;
stack <int> st2;

bool empty()
{return (st1.empty());
}

void push(int a)
{st1.push(a);
}

int front()
{int a;
if (st1.empty())
{cout<<"queue is empty";
return -1;
}
st2=st1;
while (!st2.empty())
{a=st2.top();
st2.pop();
}
return a;
}

void pop()
{if (st1.empty())
{cout<<"queue is empty";
return;
}
while (!st1.empty())
{st2.push(st1.top());
st1.pop();
}
st2.pop();
while (!st2.empty())
{st1.push(st2.top());
st2.pop();
}
}

};

int main()
{queue qt;
cout<<qt.empty()<<endl;
qt.push(1);
qt.push(2);
qt.push(3);
cout<<qt.empty()<<endl;
cout<<"front entry"<<qt.front()<<endl;
qt.pop();
cout<<"front entry"<<qt.front()<<endl;
qt.pop();
cout<<"front entry"<<qt.front()<<endl;
cout<<qt.empty()<<endl;
qt.push(4);
qt.push(5);
cout<<"front entry"<<qt.front()<<endl;
qt.pop();
cout<<"front entry"<<qt.front()<<endl;
cout<<qt.empty()<<endl;
    return 0;
}