#include<iostream>
#include<stack>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

void changetopost(string s) //infix  to postfix expression
{
    int i=0,a,b;
stack<char> st;
while (i<s.size())
{
    if ((s[i]=='+')|| (s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='^'))
{
    if (s[i]=='+')
    {while ((!st.empty()) && ((st.top()=='*')||(st.top()=='/')||(st.top()=='+')|| (st.top()=='-')|| (st.top()=='^')))
     {cout<<st.top()<<" ";
     st.pop();
     }
     st.push(s[i]);
     }
     else if (s[i]=='-')
    {while ((!st.empty()) && ((st.top()=='*')||(st.top()=='/')||(st.top()=='+')|| (st.top()=='-')|| (st.top()=='^')))
     {cout<<st.top()<<" ";
     st.pop();
     }
     st.push(s[i]);
    }
     else if (s[i]=='/')
   {while ((!st.empty()) && ((st.top()=='*')||(st.top()=='/')||(st.top()=='^')))
     {cout<<st.top()<<" ";
     st.pop();
     }
     st.push(s[i]);
     }
    else  if (s[i]=='*')
    {while ((!st.empty()) && ((st.top()=='*')||(st.top()=='/')||(st.top()=='^')))
     {cout<<st.top()<<" ";
     st.pop();
     }
     st.push(s[i]);
     }
    else  if (s[i]=='^')
    {
    while ((!st.empty()) && ((st.top()=='^')))
     {cout<<st.top()<<" ";
     st.pop();
     }
     st.push(s[i]);
     }
    i++;
    }
    else if (s[i]=='(')
    {st.push(s[i]);
    i++;
    }
    else if (s[i]==')')
    {while((!st.empty())&&(st.top()!='('))
    {cout<<st.top()<<" ";
       st.pop();
    }
    if (!st.empty())
    st.pop();
    i++;
    }
    else if(s[i]==' ')
    i++;
    else
    {
    cout<<s[i]<<" ";
    i++;
    }
    
}
while(!st.empty())
    {cout<<st.top()<<" ";
    st.pop();
    }
    return;   
}


int main()
{string s;
getline(cin,s);
changetopost(s);
return 0;
}