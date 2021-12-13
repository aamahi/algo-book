#include <bits/stdc++.h>
using namespace std;

template <typename T> 
struct LinkListNode
{
    T val;
    LinkListNode *next;
    LinkListNode *prev;

    LinkListNode(T val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <typename T> 
class DoubleLinkList {
public:
    LinkListNode<T>* head;
    LinkListNode<T>* tail;
    int size;
    
    DoubleLinkList() 
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addNode(T val)
    {
        LinkListNode<T> *tmp = new LinkListNode<T>(val);

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }

        size++;
    }

    void print()
    {
        LinkListNode<T>* curr = head;
        
        while(curr != NULL)
        {
            if(head == curr)
            {
                cout << curr->val;
            }
            else
            {
                cout << " -> " << curr->val;
            }
            curr = curr->next;
        }

        cout << endl;
    }

    LinkListNode<T>* find(T val)
    {
        LinkListNode<T>* curr = head;
        
        while(curr != NULL)
        {
            if(curr->val == val) return curr;

            curr = curr->next;
        }

        return NULL;
    }

    bool deleteNode(LinkListNode<T>* node)
    {
        if(node == NULL) return false;

        if(node->prev == NULL) 
        {
            head = node->next;
            if(head != NULL)
            {
                head->prev = NULL;
            }
        }
        else if(node->next == NULL)
        {
            tail = node->prev;
            node->prev->next = NULL;    
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        size--;

        return true;
    }

    bool deleteByVal(T val)
    {
        return deleteNode(find(val));
    }

    bool deleteByPosition(int pos)
    {
        LinkListNode<T>* curr = head;

        while(curr != NULL && pos != 1)
        {
            curr = curr->next;
            pos--;
        }

        return deleteNode(curr);
    }
};


int main()
{
    DoubleLinkList<int> linkList;

    linkList.addNode(4);
    linkList.addNode(6);
    linkList.addNode(9);
    linkList.addNode(8);

    linkList.print();

    linkList.deleteByPosition(1);
    linkList.deleteByPosition(3);
    linkList.print();
}