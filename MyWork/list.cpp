/*循环双链表ADT*/
#include <cstdio>

template<typename T>class node{
public:
        T e;
        node<T>* prev;
        node<T>* next;
        node<T>(T val):e(val),prev(this),next(this){}
};

template<typename T>class list{
        int size;
        list<T>* head;
public:
        list<T>(){
              head=new node<T>;
        }
        void push(T val){
                node<T>* tmp=head;
                while (tmp->next!=tmp){
                        tmp=tmp->next;
                }
                /*在tmp后插入*/
                node<T> new_node=new node<T>(val);
        }

};

