#include<iostream>
#include<queue>
using namespace std;
class stack{
    int n;
public:
queue <int> qt;
stack()
{n=0;}
int empty()
{return (qt.empty());
}
int size()
{return n;}

void pop()
{n--;
    if (qt.empty())
{cout<<"empty";
return;}
int a=qt.front();
qt.pop();
if (qt.empty())
return;
else
{pop();
n++;
addlast(a);
}
return;
}

void addlast(int a)
{if (qt.empty())
{qt.push(a);
return;}
    int hh=qt.front();
qt.pop();
addlast(a);
qt.push(hh);
return;
}

void push(int a)
{n++;
qt.push(a);
return;
}

int top()
{if (qt.empty())
{cout<<"empty";
return -1;}
int b=qt.front();
qt.pop();
if (qt.empty())
{qt.push(b);
    return b;}
int k=top();
addlast(b);
return k;
}
};





int main()
{stack st;
cout<<st.empty();
st.push(1);
st.push(2);
st.push(3);
cout<<endl<<st.empty()<<endl;
cout<<st.top();
cout<<endl<<st.top();
cout<<endl<<st.top();

st.pop();
cout<<endl<<st.top();
cout<<endl<<st.top();
cout<<endl<<st.top();

/*
st.push(4);
st.push(5);
cout<<endl<<st.top();
st.push(6);
st.pop();
cout<<endl<<st.top();
cout<<endl<<st.top();

cout<<endl<<st.size();
*/
    return 0;
}