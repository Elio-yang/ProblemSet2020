#include <iostream>
#include <iterator>
#include <initializer_list>
#define M
#define N
#define P

template<typename T>
class Matrix{
protected:
    T m_A[M][P];
    T m_B[P][N];
    T *o_m_A;
    T *o_m_B;
public:

    Matrix();
    int row_f_loc(initializer_list<int> args);
    int col_f_loc(initializer_list<int> args);
    
};