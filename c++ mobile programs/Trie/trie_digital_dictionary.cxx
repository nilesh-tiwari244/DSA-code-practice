#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Trie{
    public: 
    class node{
        public:
        node* next[26];
        bool endd;
        node(){
            for (int i=0;i<26;i++)
            next[i]=NULL;
            endd=false;
        }
    };
    node* trie;
    Trie(){
        trie=new node();
    }
    
    
    void insert(string st){
        node* it=trie;
        int i,j,n;
        n=st.size();
        i=0;
        while(i<n){
            if (it->next[st[i]-'a']==NULL)
                it->next[st[i]-'a']=new node();
                it=it->next[st[i]-'a'];
                i++;
        }
        it->endd=true;
        return;
    }
    
    
    vector<string> prin(node* kk,string pp){
        int i,j;
        node* tt=kk;
        vector<string> fog;
        vector<string> gho;
        if (kk->endd==true)
        {gho.push_back(pp);
        }
        string gg;
        char ch;
        for (i=0;i<26;i++){
               if (tt->next[i]!=NULL)
            {ch='a' + i;
            gg=ch;
            fog=prin(tt->next[i],pp+ gg);  
            for(j=0;j<fog.size();j++)
            gho.push_back(fog[j]);
        }
        }
        return gho; 
    }
    
    
    
    vector<string> search(string st){
        node* it=trie;
        int i,j,n;
        n=st.size();
        i=0;
        vector<string> ans;
        vector<string> answe;
        vector<string> aws;
        ans.push_back("");
        while (i<n){
             if (it->next[st[i]-'a']==NULL)
             {insert(st);
             return answe;
             }
             ans[0]+=st[i];
             it=it->next[st[i]-'a'];
             i++; 
        }
        int hh;
        if (it->endd==true)
        {answe.push_back(ans[0]);
        }
        char ch;
        string gg;
        for (hh=0;hh<26;hh++){
            if (it->next[hh]!=NULL)
           { ch='a' +hh;
           gg=ch;
           aws=prin(it->next[hh],ans[0]+ gg);
           for (i=0;i<aws.size();i++)
           answe.push_back(aws[i]);  
        }
        }
     return answe;   
    }
        
};


int main(){
    Trie* dict=new Trie();
    int i,j,n,q;
    
    cin>>n;
    vector<string> inp(n);
    for(i=0;i<n;i++)
    {cin>>inp[i];
    dict->insert(inp[i]);
    }
    
    cin>>q;
    vector<string> chk(q);
    vector<string> cc;
    vector<string> pr;
    for(i=0;i<q;i++)
    {cin>>chk[i];
    cc.clear();
    cc=dict->search(chk[i]);
    for(j=0;j<cc.size();j++)
    pr.push_back(cc[j]);
    }
    
    cout<<endl;
    for (j=0;j<pr.size();j++)
    cout<<pr[j]<<endl;
    return 0;
}
/*

3
nilesh
nilansh
tiwari
3
nil
kumar
ku

*/
