#include<iostream>
#include<stack>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int calcu(string s)
{int i=s.size() - 1,a,b;
stack<int> st;
while (i>=0)
{if ((s[i]=='+')|| (s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='^'))
{a=st.top();
    st.pop();
    b=st.top();
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
    i--;
    }
    else if(s[i]==' ')
    i--;
    else
    {string jk="";
        while (s[i]!=' ')
    {jk=s[i]+jk;
    i--;
    }
    st.push(stoi(jk));
    i--;
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