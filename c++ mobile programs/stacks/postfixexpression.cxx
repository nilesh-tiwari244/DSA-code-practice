#include<iostream>
#include<stack>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int calcu(string s) //postfix expression
{int i=0,a,b;
stack<int> st;
while (i<s.size())
{if ((s[i]=='+')|| (s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='^'))
{b=st.top();
    st.pop();
    a=st.top();
    st.pop();
    
    if (s[i]=='+')
    st.push(a+b);
     else if (s[i]=='-')
    st.push(a-b);
     else if (s[i]=='/')
    st.push(a/b);
    else  if (s[i]=='*')
    st.push(a*b);
    else  if (s[i]=='^')
    st.push(pow(a,b));
    i++;
    }
    else if(s[i]==' ')
    i++;
    else
    {string jk="";
        while (s[i]!=' ')
    {jk+=s[i];
    i++;
    }
    st.push(stoi(jk));
    i++;
    }
}
cout<<endl;
cout<<"result=";
    return st.top();   
}


int main()
{string s;
getline(cin,s);
cout<<calcu(s);
return 0;
}