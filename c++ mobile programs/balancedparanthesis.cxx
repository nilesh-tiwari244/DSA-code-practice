#include<iostream>
#include<stack>
using namespace std;
int balancedparanthesis(string s)
{int i=0;
stack <char> st;
while (i<s.size())
       {    if ((s[i]=='(')||(s[i]=='{')||(s[i]=='['))
                st.push(s[i]);
            else 
                {
                 if (st.empty())
                return 0;
                 else if ((s[i]==')')&&(st.top()=='('))
                {
                st.pop();
                }
                 else if ((s[i]=='}')&&(st.top()=='{'))
                {
                st.pop();
                }
                 else if ((s[i]==']')&&(st.top()=='['))
                {
                st.pop();
                }
                else 
                { 
                return 0;
                }
                }
            i++;
       }
   if (st.empty())
   return 1;
   else
   return 0;
}
int main()
{cout<<balancedparanthesis("[{{()}");
return 0;
}