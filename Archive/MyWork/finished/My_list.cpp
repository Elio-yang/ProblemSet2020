/*provide single linked list*/
#include <iostream>

using namespace std;

template<typename T>
class node {
public:
        T data;
        node<T> *next;

        node(T d = 0)
        {
                data = (T) d;
                next = nullptr;
        }
};

template<typename T>
class forwardList {
        int size;
public:
        node<T> *head;

        forwardList<T>() : size(0)
        {
                head = new node<T>;
                ++size;
        }

        void push_back(T d)
        {
                node<T> *tmp = head;
                while (tmp->next != nullptr) {
                        tmp = tmp->next;
                }
                /*tmp->next=nullptr
                 * tmp--->nullptr
                 * tmp-->new_node-->nullptr
                 * */
                auto new_node = new node<T>(d);
                new_node->next = tmp->next;
                tmp->next = new_node;
                ++size;
        }

        void push_head(T d)
        {
                node<T> *tmp = head;
                auto new_node = new node<T>(d);
                new_node->next = tmp->next;
                tmp->next = new_node;
                ++size;
        }

        void push_pos_k(int k, T d)
        {
                /*在第k个节点后插入，k=0为push_head*/
                if (k > size) {
                        cerr << "invalid! position k doesn't exit" << endl;
                        return;
                }
                node<T> *new_node = new node<T>(d);
                node<T> *tmp = head;
                for (int i = 0; i < k; i++) {
                        tmp = tmp->next;
                }
                new_node->next = tmp->next;
                tmp->next = new_node;
                ++size;
        }

        void remove_posk(int k)
        {
                /*头节点不能删*/
                if (k > size || k == 0) {
                        cerr << "invalid! position k doesn't exit or can't be deleted!" << endl;
                        return;
                }
                node<T> *tmp = head;
                node<T> *prev;
                for (int i = 0; i < k; i++) {
                        prev = tmp;
                        tmp = tmp->next;
                }
                prev->next = tmp->next;
                tmp->next = nullptr;
                delete tmp;
        }

private:
        void delete_list(node<T> *node_s)
        {
                if (node_s->next == nullptr) {
                        delete node_s;
                        node_s = nullptr;
                        return;
                }
                delete_list(node_s->next);
        }

public:
        ~forwardList<T>()
        {
                printf("delete the list\n");
                delete_list(head);
                size = 0;
        }

        void print_list(node<T> *node_s)
        {
                if (node_s == nullptr) {
                        cout << endl;
                        return;
                }
                cout << node_s->data << " ";
                print_list(node_s->next);
        }

        node<T> *find(node<T> *&node_s, T d)
        {
                if (node_s == nullptr || node_s->data == d) {
                        /*一定要先判断是否为空，不然会段错误*/
                        if (node_s == nullptr) {
                                return nullptr;
                        } else {
                                return node_s;
                        }
                }
                find(node_s->next, d);
        }

        /*list[0] will be the first element (head->next)*/
        node<T> *operator[](int k)
        {
                if (k >= size || k == 0) {
                        cerr << "out of range or can't be accessed" << endl;
                        return nullptr;
                }
                node<T> *tmp = head->next;
                for (int i = 0; i < k; i++) {
                        tmp = tmp->next;
                }
                return tmp;
        }

};

/*test*/

int main()
{
        forwardList<int> list;
//        for (int i = 0; i < 100; i++) {
//                list.push_back(i);
//        }
//        list.print_list(list.head->next);
//        for (int i = 100 ; i <200 ; i++) {
//                list.push_head(i);
//        }
//        list.print_list(list.head->next);
        //list.remove_posk(300);
        for (int i = 0; i < 6; i++) {
                list.push_back(i);
        }
        list.print_list(list.head->next);
        node<int> *tmp_node = list.find(list.head->next, 7);
        if (tmp_node) {
                cout << tmp_node->data << " " << tmp_node->next->data << endl;
        }
        node<int> *tmp_node_2 = list.find(list.head->next, 4);
        if (tmp_node_2 == nullptr) {
                cout << "can't find node" << endl;
        } else {
                cout << "find!" << endl;
        }

        node<int> *tmp_node_3 = list[5];
        cout << "list[5]= " << tmp_node_3->data << endl;
        return 0;

}