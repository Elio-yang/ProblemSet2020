#include <cstdlib>
#include <iostream>
#include <cctype>
struct node {
        char key;
        struct node *lc;
        struct node *rc;
};

node* creat();
void in_order(node *T);
int order_op(char op_r);
int main() {
        auto T = new node;
        T = creat();
        in_order(T);
        return 0;
}

node* creat() {
        char k;
        scanf("%c", &k);
        node* T;
        if (k == '#') {
                T = NULL;
        }
        else {
                T = new node;
                T->key = k;
                T->lc = creat();
                T->rc = creat();
        }
        return T;
}
void in_order(node *T) {
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