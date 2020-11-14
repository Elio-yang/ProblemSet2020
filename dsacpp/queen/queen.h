#pragma once

class Queen{
public:
        int x;
        int y;
        Queen(int xx=0,int yy=0):x(xx),y(yy){};
        /*重载==运算符，判断是否会冲突*/
        bool operator==(Queen const &q)const{
                return (q.x==x)||       //行冲突
                        (q.y==y)||      //列冲突
                        (x+y==q.x+q.y)||//正对角线
                        (x-y==q.x-q.y); //反对角线
                /*
                 * --------------------
                 *   |  |1 |2 |3 |  |
                 * --------------------
                 *   |  |4 |* |  |  |
                 * --------------------
                 *   |  |5 |  |6 |  |
                 * --------------------
                 *   queen * (x,y)
                 *   1: (x-1,y+1)--->x-1+y+1==x+y
                 *   2:  2.y==y
                 *   3: (x+1,y+1)--->x+1-y-1=x-y
                 *   4: 4.x==x
                 *   5: (x-1,y-1)--->x-1-y+1==x-y
                 *   6: (x+1,y-1)--->x+1+y-1==x+y
                 * */
        }
        bool operator!=(Queen const &q)const{
                return !(*this==q);
        }
};