
#ifndef PROBLEMSET_MY_STL_H
#define PROBLEMSET_MY_STL_H

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#include <iostream>
#include <cstring>
#include <cassert>
/* max要根据文件变化 */
#define maxn 100000
#define maxsize 100000
/* STACK operation*/
template<typename T>
class stack{
private:
        static constexpr int Empty=-1;
        int _size;
        int Low;
        int Top;
        T *arr;
        int max_size;
public:
        explicit stack<T>(int n): Top(Empty), max_size(n), Low(0), _size(0){
                arr =new T[n];
                if (arr== nullptr){
                        std::cerr<<"heap overflow"<<std::endl;
                        return;
                }
        }
        int empty(){
                return (Top==Empty || _size == 0);
        }
        void push(T d){
                if(Top==max_size-1){
                        std::cerr<<"stack full error"<<std::endl;
                        return ;
                }
                arr[++Top]=d;
                ++_size;
        }
        void pop(){
                if(empty()){
                        std::cerr<<"stack empty error"<<std::endl;
                        return;
                }
                --Top;
                --_size;

        }
        T top(){
                return arr[Top];
        }
};
/*QUEUE operation*/
template<typename T>
class queue{
        static constexpr int Empty=-1;
        int size;
        int Front;
        int Rear;
        T *arr;
public:
        queue<T>():Front(1),Rear(0),size(0){
                arr=new T[maxn];
        }

        void pop(){
                ++Front;
                --size;
        }
        void push(T e){
                arr[++Rear]=e;
                ++size;
        }
        T& front(){
                return arr[Front];
        }
        bool empty(){
                return size==0;
        }
        ~queue<T>(){
                delete []arr;
        }
};
/*single LIST operation*/
template<typename T>
class list_node {
public:
        T data;
        list_node<T> *next;

        list_node(T d = 0)
        {
                data = (T) d;
                next = nullptr;
        }
};
template<typename T>
class forwardList {
        int size;
public:
        list_node<T> *head;

        forwardList<T>() : size(0)
        {
                head = new list_node<T>;
                ++size;
        }

        void push_back(T d)
        {
                list_node<T> *tmp = head;
                while (tmp->next != nullptr) {
                        tmp = tmp->next;
                }
                /*tmp->next=nullptr
                 * tmp--->nullptr
                 * tmp-->new_node-->nullptr
                 * */
                auto new_node = new list_node<T>(d);
                new_node->next = tmp->next;
                tmp->next = new_node;
                ++size;
        }

        void push_head(T d)
        {
                list_node<T> *tmp = head;
                auto new_node = new list_node<T>(d);
                new_node->next = tmp->next;
                tmp->next = new_node;
                ++size;
        }

        void push_pos_k(int k, T d)
        {
                /*在第k个节点后插入，k=0为push_head*/
                if (k > size) {
                        std::cerr << "invalid! position k doesn't exit" <<  std::endl;
                        return;
                }
                list_node<T> *new_node = new list_node<T>(d);
                list_node<T> *tmp = head;
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
                        std::cerr << "invalid! position k doesn't exit or can't be deleted!" <<  std::endl;
                        return;
                }
                list_node<T> *tmp = head;
                list_node<T> *prev;
                for (int i = 0; i < k; i++) {
                        prev = tmp;
                        tmp = tmp->next;
                }
                prev->next = tmp->next;
                tmp->next = nullptr;
                delete tmp;
        }

private:
        void delete_list(list_node<T> *node_s)
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

        void print_list(list_node<T> *node_s)
        {
                if (node_s == nullptr) {
                        std::cout <<  std::endl;
                        return;
                }
                std::cout << node_s->data << " ";
                print_list(node_s->next);
        }

        list_node<T> *find(list_node<T> *&node_s, T d)
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
        list_node<T> *operator[](int k)
        {
                if (k >= size || k == 0) {
                        std::cerr << "out of range or can't be accessed" <<  std::endl;
                        return nullptr;
                }
                list_node<T> *tmp = head->next;
                for (int i = 0; i < k; i++) {
                        tmp = tmp->next;
                }
                return tmp;
        }

};

/*C-QSORT function*/
// function for swap two elements
void swap(void* v1, void* v2, int size)
{
        /*
         * buffer is array of characters which will
         * store element byte by byte
         * memcpy will copy the contents from starting
         * address of v1 to length of size in buffer
         * byte by byte.
         * */
        char buffer[size];


        memcpy(buffer, v1, size);
        memcpy(v1, v2, size);
        memcpy(v2, buffer, size);
}
/*
 * v is an array of elements to sort.
 * size is the number of elements in array
 * left and right is start and end of array
 * (*comp)(void*, void*) is a pointer to a function
 * which accepts two void* as its parameter
 */
void _qsort(void* v, int size, int left, int right,
            int (*comp)(void*, void*))
{
        void *vt, *v3;
        int i, last, mid = (left + right) / 2;
        if (left >= right)
                return;

        // casting void* to char* so that operations
        void* vl = (char*)(v + (left * size));
        void* vr = (char*)(v + (mid * size));
        swap(vl, vr, size);
        last = left;
        for (i = left + 1; i <= right; i++) {

                /*
                 * vl and vt will have the starting address
                 * of the elements which will be passed to
                 * comp function.
                 */
                vt = (char*)(v + (i * size));
                if ((*comp)(vl, vt) > 0) {
                        ++last;
                        v3 = (char*)(v + (last * size));
                        swap(vt, v3, size);
                }
        }
        v3 = (char*)(v + (last * size));
        swap(vl, v3, size);
        _qsort(v, size, left, last - 1, comp);
        _qsort(v, size, last + 1, right, comp);
}
/*just use it like it used to be! the same interface as what in stdlib.h*/
void qsort(void* _base, std::size_t _nmemb, std::size_t _size, int (*_cmp)(void*, void*)){
        _qsort(_base, _size, 0, _nmemb - 1, _cmp);
}
/*PAIR structure*/
template<typename T>
class pair{
        T first;
        T second;
        pair<T>(T f,T s):first(f),second(s){}
        T get_first() const{
                return first;
        }
        T get_second() const{
                return second;
        }
        bool operator<(const pair<T>& b)const{
                if (first!=b.first){
                        return first<b.first;
                }else{
                        return second<b.second;
                }
        }
};
/*HEAP operation*/
template<typename T>
class priority_queue{
private:
        //当前的大小
        int size;
        //最大的规模
        int Capcity;
        //堆的存放
        T* Contains;
public:
        //无参构造函数
        priority_queue<T>():size(0),Capcity(maxsize){
                Contains=new T[maxsize + 1];
        }
        void push(T E)
        {
                int i;
                for(i=++size; Contains[i / 2] > E; i>>=1){
                        Contains[i]=Contains[i >> 1];
                }
                Contains[i]=E;
        }

        T top()
        {
                return Contains[1];
        }

        void pop()
        {
                int i,child;
                T last_ele=Contains[size--];
                for(i=1;2*i<=size;i=child){
                        child=i<<1;
                        if (child!=size && Contains[child + 1] < Contains[child]){
                                child++;
                        }
                        if (last_ele > Contains[child]){ Contains[i]=Contains[child];}
                        else break;
                }
                Contains[i]=last_ele;
        }
        bool empty()
        {
                return size==0;
        }
};
/*VECTOR operation*/
template < typename T>
class vector {
public:
        typedef T * iterator;
        vector()
        {
                _size = 0;
                _buf = new T[1];
                _capacity = 1;
        }

        vector(int s, T const& a)
        {
                if (s > _max_capacity) {
                        s = _max_capacity;
                }
                _size = s;
                _capacity = 1;
                while (_capacity < _size) {
                        _capacity *= 2;
                }
                _buf = new T[_capacity];
                for (size_t i = 0; i < _size; i++) {
                        _buf[i] = a;
                }
        }

        ~vector()
        {
                delete[] _buf;
        }
        size_t size() const
        {
                return _size;
        }

        void push_back(const T& val)
        {
                if (_size < _capacity) {
                        _buf[_size] = val;
                        _size++;
                        return ;
                } else if (_size == _max_capacity) {
                        return ;
                }
                _capacity *= 2;
                if (_capacity >= _max_capacity) {
                        _capacity = _max_capacity;
                }
                T * tmp = new T[_capacity];
                for (size_t i = 0; i < _size; i++) {
                        tmp[i] = _buf[i];
                }
                tmp[_size] = val;
                _size++;
                delete[] _buf;
                _buf = tmp;
        }
        T& operator[](int index)
        {
                assert(index >= 0 && index < _size);
                return _buf[index];
        }
        vector<T>& operator=(const vector<T>& a)
        {
                if (this == &a) {
                        return *this ;
                }
                delete[] _buf;
                _size = a._size;
                _capacity = a._capacity;
                _buf = new T[_capacity];
                for (size_t i = 0; i < _size; i++) {
                        _buf[i] = a._buf[i];
                }
                return *this;
        }

        bool empty() const
        {
                if (_size == 0) {
                        return true;
                }
                return false;
        }
        iterator begin() const
        {
                return _buf;
        }
        iterator end() const
        {
                return _buf + _size;
        }
private:
        size_t  _size;
        size_t  _capacity;
        T*      _buf;
        const size_t _max_capacity = 65536;
};

#endif //PROBLEMSET_MY_STL_H