#include <cstdio>

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
};

