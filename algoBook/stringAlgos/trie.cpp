#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char ch;
    TrieNode * childs[27];
};

void insert(TrieNode*  root, string key)
{
    int chint = 0;
    for( int i=0 ; i<key.size() ; i++ )
    {
        chint = key[i] - 96;
        if(root -> childs[chint] != NULL)
        {
            root = root -> childs[chint];
        }
        else
        {
            TrieNode *tmp = new TrieNode();
            tmp->ch = key[i];
            root->childs[chint] = tmp;
            root = tmp;
        }
    }
    TrieNode *tmp = new TrieNode();
    tmp->ch = '*';
    root->childs[0] = tmp;
}

bool search(TrieNode*  root, string key)
{
    int chint = 0;
    for( int i=0 ; i<key.size() ; i++ )
    {
        chint = key[i] - 96;
        if(root -> childs[chint] != NULL)
        {
            root = root -> childs[chint];
        }
        else
        {
            return false;
        }
    }
    return root->childs[0] != NULL;
}


int main()
{
    TrieNode *root = new TrieNode();
    insert(root, "abcd");
    insert(root, "abcde");
    insert(root, "abc");
    insert(root, "bcd");

    cout << search(root, "bcd") << endl;
    cout << search(root, "dabc") << endl;

    return 0;
}