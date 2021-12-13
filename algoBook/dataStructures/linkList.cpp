#include <bits/stdc++.h>
using namespace std;

template <typename T> 
struct LinkListNode
{
    T val;
    LinkListNode *next;

    LinkListNode(T val)
    {
        this->val = val;
        this->next = NULL;
    }
};

template <typename T> 
class LinkList {
private:
    bool deleteNode(LinkListNode<T>* curr, LinkListNode<T>* prev)
    {
        if(curr == NULL) return false;
        else
        {
            if(curr->next == NULL)
            {
                tail = prev;
            }

            if (prev == NULL)
            {
                head = head->next;
            }
            else
            {
                prev->next = curr->next;
            }
            size--;
            return true;
        }
    }

public:
    LinkListNode<T>* head;
    LinkListNode<T>* tail;
    int size;
    
    LinkList() 
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

    bool deleteByVal(T val)
    {
        LinkListNode<T>* curr = head;
        LinkListNode<T>* prev = NULL;
        while(curr != NULL)
        {
            if(curr->val == val) break;
            prev = curr;
            curr = curr->next;
        }

        return deleteNode(curr, prev);
    }

    bool deleteByPosition(int pos)
    {
        LinkListNode<T>* curr = head;
        LinkListNode<T>* prev = NULL;

        while(curr != NULL && pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }

        return deleteNode(curr, prev);
    }
};


int main()
{
    LinkList<int> linkList;

    linkList.addNode(4);
    linkList.addNode(6);
    linkList.addNode(9);
    linkList.addNode(8);

    linkList.print();

    linkList.deleteByPosition(4);
    linkList.addNode(3);
    linkList.addNode(3);
    linkList.print();
}