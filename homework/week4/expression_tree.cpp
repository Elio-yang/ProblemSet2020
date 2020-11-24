#include <cstdlib>
#include <iostream>
#include <cctype>
struct vertex {
        char key;
        struct vertex *lc;
        struct vertex *rc;
};

vertex* creat();
void in_order(vertex *T);
int order_op(char op_r);
int main() {
        auto T = new vertex;
        T = creat();
        in_order(T);
        return 0;
}

vertex* creat() {
        char k;
        scanf("%c", &k);
        vertex* T;
        if (k == '#') {
                T = NULL;
        }
        else {
                T = new vertex;
                T->key = k;
                T->lc = creat();
                T->rc = creat();
        }
        return T;
}
void in_order(vertex *T) {
        if (T != nullptr) {
                if (T->lc){
                        bool flag = order_op(T->key) > order_op(T->lc->key);
                        if (flag) {
                                printf("(");
                        }
                        in_order(T->lc);
                        if (flag) {
                                printf(")");
                        }
                }
                printf("%c", T->key);
                if (T->rc) {
                        bool flag = order_op(T->key) >= order_op(T->rc->key);
                        if (flag ) {
                                printf("(");
                        }
                        in_order(T->rc);
                        if (flag ) {
                                printf(")");
                        }
                }
        }
}

int order_op(char op_r) {
        if (op_r == '+' || op_r == '-') {
                return 1;
        }
        else if (op_r == '*' || op_r == '/') {
                return 2;
        }
        else if ('a' <= op_r && op_r <= 'z') {
                return 3;
        }
}