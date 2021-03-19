/*
 编号为1…N的N个小朋友玩游戏，他们按编号顺时针围成一圈，从第一个人开始按逆时针次序报数，
 报到第M个人出列；然后再从下个人开始按顺时针次序报数，报到第K个人出列；再从下一个人开
 始按逆时针次序报数，报到第M个人出列；再从下个人开始按顺时针次序报数，报到第K个人出列……
 以此类推不断循环，直至最后一人出列。请编写程序按顺序输出出列人的编号。


输入格式:

输入为3个正整数，分别表示N、M、K，均不超过1000。

输出格式:

输出为一行整数，为出列人的编号。每个整数后一个空格。

 */
#include <cstdio>
using namespace std;

struct node {
        int id;
        node *prev;
        node *next;

        node(int i) : id(i), prev(this), next(this)
        {}
};

struct student_circle {
        int size;
        node *p_stu;
        node *p_cur;

        explicit student_circle(int n) : size(n)
        {
                p_stu = new node(1);
                auto w = p_stu;
                p_cur = p_stu;
                for (int i = 2; i <= n; i++) {
                        auto stu = new node(i);
                        auto tmp = w->next;

                        stu->next = tmp;
                        stu->prev = w;
                        w->next = stu;
                        p_stu->prev = stu;
                        w = stu;
                }
        }

        int r_k(int k)
        {
                node *tmp;
                for (int i = 1; i < k; i++) {
                        tmp = p_cur;
                        p_cur = p_cur->next;
                }
                auto p_free = p_cur;
                auto p_tmp = p_cur->next;
                printf("%d ", p_cur->id);
                tmp->next = p_tmp;
                p_tmp->prev = tmp;
                p_cur = p_cur->next;
                delete p_free;
                size--;
        }

        int l_m(int m)
        {
                node *tmp;
                for (int i = 1; i < m; i++) {
                        tmp = p_cur;
                        p_cur = p_cur->prev;
                }
                auto p_free = p_cur;
                auto p_tmp = p_cur->prev;
                printf("%d ", p_cur->id);
                tmp->prev = p_tmp;
                p_tmp->next = tmp;
                p_cur = p_cur->prev;
                delete p_free;
                size--;
        }
        void play_game(int m,int k){
                for(;;){
                        if(size==0){
                                break;
                        }
                        l_m(m);
                        r_k(k);
                }
        }
};
int main()
{
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        student_circle circle(n);
        circle.play_game(m,k);
        return 0;
}