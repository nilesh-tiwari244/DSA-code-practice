#include<iostream>
#include<stack>
#include<string>
using namespace std;

string infixtoprefix(string s)
{string ans="";
reverse(s.begin(),s.end());
int i=0;
stack<char> st;
while(i<s.size())
{if (s[i]=='(')
s[i]=')';
else if (s[i]==')')
s[i]='(';
i++;
}
i=0;
while(i<s.size())
{   if (s[i]=='(')
    {st.push(s[i]);
    i++;
    }
    else if (s[i]==')')
    {while ((!st.empty())&&(st.top()!='('))
        {ans+=st.top();
        st.pop();
        }
    if (!st.empty())
        st.pop();
    i++;
    }
    else if(s[i]=='+')
    {while((!st.empty())&&((st.top()=='+')||(st.top()=='-')||(st.top()=='*')||(st.top()=='/')||(st.top()=='^'))&&(st.top()!='('))
        {ans+=st.top();
        st.pop();      
        }
     st.push(s[i]);    
       i++; 
    }
    else if(s[i]=='-')
    {while((!st.empty())&&((st.top()=='+')||(st.top()=='-')||(st.top()=='*')||(st.top()=='/')||(st.top()=='^'))&&(st.top()!='('))
        {ans+=st.top();
        st.pop();      
        }
     st.push(s[i]);    
       i++; 
    }
    else if(s[i]=='*')
    {while((!st.empty())&&((st.top()=='*')||(st.top()=='/')||(st.top()=='^'))&&(st.top()!='('))
        {ans+=st.top();
        st.pop();      
        }
     st.push(s[i]);    
       i++; 
    }
    else if(s[i]=='/')
    {while((!st.empty())&&((st.top()=='*')||(st.top()=='/')||(st.top()=='^'))&&(st.top()!='('))
        {ans+=st.top();
        st.pop();      
        }
     st.push(s[i]);    
       i++; 
    }
    else if(s[i]=='^')
    {while((!st.empty())&&(st.top()=='^')&&(st.top()!='('))
        {ans+=st.top();
        st.pop();      
        }
     st.push(s[i]);    
       i++; 
    }
    else 
    {ans+=s[i];
    i++;
    }  
}
  while(!st.empty())  
  {ans+=st.top();
  st.pop();
  }
  reverse(ans.begin(),ans.end());
return ans; 
}


int main()
{string s="(a-b/k)*(a/g-p)";
s=infixtoprefix(s);
cout<<endl;
cout<<"return="<<s;
return 0;
}

