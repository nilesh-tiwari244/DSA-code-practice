#include<iostream>
#include<vector>
using namespace std;
class Trie{
    public:
    class node{
        public:
        bool end;
        node* next[26];
        node(){
            end=false;
            for(int i=0;i<26;i++)
            next[i]=NULL;
        }
    };
    node* trie;
    Trie(){
        trie=new node();
    }
    void insert(string st);
    bool find(string st);
};
void Trie:: insert(string st){
    int i=0,n;
    n=st.size();
    node* it=trie;
    while (i<n){
        if (it->next[st[i]-'a']==NULL)
            it->next[st[i]-'a']=new node();
            it=it->next[st[i]-'a'];
            i++;
    }
    it->end=true;
    return;
}
bool Trie:: find (string st){
    int i=0,n;
    n=st.size();
    node* it=trie;
    while (i<n){
        if (it->next[st[i]-'a']==NULL)
        return false;
        it=it->next[st[i]-'a'];
        i++;
    }
    return it->end;  
}
int main(){
    Trie *dict=new Trie;
    dict->insert("nilesh");
    dict->insert("tiwari");
    cout<<endl<<dict->find("kumar");
    cout<<endl<<dict->find("tiwari");
    cout<<endl<<dict->find("nilesh");
    cout<<endl<<dict->find("kar");
    return 0;
}
