#include<iostream>
#include <bits/stdc++.h>
using namespace std;
template<class t>
class LIST{
private:
    struct node {
        t data;
        node *prev;
        node *next;
    };
    node *head, *tail;
public:
    class ITERATOR {
    private:
        node* INode;
      friend class LIST;
    public:
        ITERATOR(){
            INode=NULL;
        }
        ITERATOR(node *Pnode){
            INode=Pnode;
        }
        void operator++() {
            if (INode->next == NULL) {
                throw "out of list elements";
            }
            INode = INode->next;
        }
        void operator--() {
            if (INode->prev == NULL) {
                throw "out of list elements";
            }
            INode = INode->prev;
        }
        bool operator==(const ITERATOR& IT) {
            return INode == IT.INode;
        }
        t& operator*() {
            return INode->data;
        }

    };

    LIST() {
        head=tail=NULL;
    }

    LIST(t val, int size){
        head=tail=NULL;
        for (int i=0;i<size;i++){
            push_back(val);
        }
    }
    int size(){
        int count=0;
        node *current=head;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void insert(t val, ITERATOR pos) {
      if(pos .INode==tail){push_back(val);}
        node* newNode = new node;
        newNode->data = val;
        if (pos.INode == head) {
            newNode->next = head;
            pos.INode->prev = newNode;
            head = newNode;
        }
        else {
            newNode->next = pos.INode;
            newNode->prev = pos.INode->prev;
            pos.INode->prev->next=newNode;
            pos.INode->prev = newNode;

        }
    }
    void push_front(t val){
        insert(val,begin());
    }
    void push_back(t val)
    {
        node*newNode=new node;
        newNode->data=val;
        if(head==NULL)
        {
            head=newNode;
            newNode->prev=newNode->next=NULL;
            tail=newNode;
        }
        else
        {
            newNode->prev=tail;
            tail->next=newNode;
            newNode->next=NULL;
            tail=newNode;
        }
    }
    ITERATOR erase(ITERATOR pos) {
        if (pos == end() ){
            throw"out of list elements";   }
        if (pos.INode == head) {
            node* del = head;
            head = del->next;
            delete del;
            return pos.INode;
        }
         else if (pos.INode == tail) {
            node* del = tail;
           tail->prev->next=NULL;
           tail=del->prev;
            delete del;
            return pos.INode;
        }

        else {
            --pos;
            node *del=pos.INode->next;
            pos.INode->next=del->next;
            del->next->prev=pos.INode;
            delete del;
            return ++pos.INode;
        }
    }
    void pop_back()
    {
        node* tmp = tail;
        tail ->prev->next=NULL;
        tail=tmp->prev;
        delete tmp;
    }
    void pop_front()
    {
        node* tmp = head;
        head = tmp->next;
        delete tmp;
    }

    LIST <t> & operator=(LIST<t> li){
        if (head != NULL)
            deleteAllList();
        if (li.head == NULL)
        {
            head = tail= NULL;
        }
        else
        {
            node  *tmp;
            tmp = li.head;
            head=NULL;
            while (tmp != NULL)
            {
               push_back(tmp->data);
                tmp = tmp->next;
            }
        }
    }
    void print(){
        node * tmp=head;
        while(tmp!=NULL){
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<"\n";
    }

    void deleteAllList(){
        node *current;
        while (head !=NULL){
            current=head;
            head=head->next;
            delete current;}
        tail=NULL;
    }
    ITERATOR begin(){
        return ITERATOR(head);
    }
    ITERATOR end(){
        return ITERATOR(tail);
    }
    ~LIST() { deleteAllList();}

};
int main() {

    LIST<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_front(5);
    myList.insert(0,myList.begin());
    myList.pop_front();
    myList.pop_back();
    myList.print();
    cout<<myList.size()<<"\n";
    LIST<int>li (3,5);
    myList=li;
     myList.print();
    LIST<int>l(2,5);
    LIST<int>::ITERATOR it = l.end();
    --it;
    cout<<*it<<"\n";
    l.erase(it);
    l.print();
    LIST<int>::ITERATOR i = myList.begin();
    ++i;
    cout<<*i<<"\n";
    return 0;
}
