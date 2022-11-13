#include<iostream>
using namespace std;
#define n 100 
class stack{
    int *arr;
    int top;
    public:
    stack()
    {top=-1;
    arr=new int[n];
    }
    void push(int val)
    {if (top==n-1)
    {cout<<"stack overflow"<<endl;
    return;}
    top++;
    arr[top]=val;
    return;
    }
    void pop()
    {if (top==-1)
    {cout<<"stack underflow"<<endl;
    return;
    }
    top--;
    return;
    }
    
    int peek();
    
    bool empty()
    {return top==-1;
    }
};
int stack::peek()
{if (top==-1)
{cout<<"no element in stack";
return -1;}
return arr[top];
}
int main()
{stack s1;
s1.push(1);
s1.push(2);
s1.push(3);
cout<<endl<<s1.peek();
s1.pop();
cout<<endl<<s1.empty();
cout<<endl<<s1.peek();
s1.pop();
s1.pop();
s1.pop();
cout<<endl<<s1.peek();
cout<<endl<<s1.empty();  
return 0;
}