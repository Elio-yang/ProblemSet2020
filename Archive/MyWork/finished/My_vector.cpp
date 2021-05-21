#include <string>
#include<cassert>
#include <iostream>

using namespace std;
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
/*
int main()
{
        int c = 20;
        vector<string> a;
        vector<string> b;
        for (int i = 0 ; i < 3; i++) {
                a.push_back("hello");
        }
        b = a;
        for (vector<string>::iterator it = b.begin(); it != b.end(); it++) {
                cout << *it << " " << endl;
        }
        return 0;
}
*/