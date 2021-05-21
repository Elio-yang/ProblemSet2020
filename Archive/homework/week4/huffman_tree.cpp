#include <cstdio>
#include <cstdlib>
#include <cstring>
#define char_set_max_len 26
#define max_cnt 5010
struct H_tree_node {
        int cnt;
        char key;
        H_tree_node *lc;
        H_tree_node *rc;
};//huffman tree node
struct H_root {
        H_tree_node *_root;
};//point to root of huffman tree
struct list_node {
        H_tree_node *pH;
        int cnt;
        list_node *next;
};//list node
struct l_root {
        int len;
        list_node * p_l;
};//list root
struct record {
        int cnt;
        char key;
        char *recode;
        record *next;
};//recoding node
struct record_root {
        record *p_beg;
        record *p_end;
};//recoding node root
struct data {
        char key;
        int cnt;

        int pos;
};
data order [27] = {0};
int _index=0;
inline void init_list(l_root*& list) {
        list = new l_root;
        list->len = 0;
        list->p_l = nullptr;
}
inline void add_q_node(l_root*& list, H_tree_node *h_node, int cnt) {
        list_node *node = nullptr;
        if (list->len == 0) {
                node = new list_node;
                list->p_l = node;
                node->cnt = cnt;
                node->next = nullptr;
                node->pH = h_node;
                list->len++;
        }
        else if (cnt < list->p_l->cnt) {
                node = new list_node;
                node->next = list->p_l;
                list->p_l = node;
                node->cnt = cnt;
                node->pH = h_node;
                list->len++;
        }
        else {
                list_node *tmp = list->p_l;//first node
                node = new list_node;
                node->cnt = cnt;
                node->pH = h_node;
                list->len++;
                //from second node
                for (; tmp->next != nullptr; tmp = tmp->next) {
                        if (cnt >= tmp->cnt&&cnt < tmp->next->cnt) {
                                break;
                        }
                }
                node->next = tmp->next;
                tmp->next = node;
        }
}
inline H_tree_node *get_h_tree_node(l_root *h_l) {/*get node from queue*/
        H_tree_node *h_node = nullptr;
        if (h_l->len > 0) {
                h_node = h_l->p_l->pH;
                h_l->p_l = h_l->p_l->next;
                h_l->len--;
        }
        else {
                printf("can't get node!\n");
        }
        return h_node;
}
inline H_root *build_H_Tree(l_root*& h_l) {
        int cnt = 0;
        H_tree_node *lc, *rc;
        while (h_l->len > 1) {
                cnt = h_l->p_l->cnt + h_l->p_l->next->cnt;
                /*sum of frequency of two node*/
                lc = get_h_tree_node(h_l);
                rc = get_h_tree_node(h_l);
                /*choose 2 node*/
                auto h_node = new H_tree_node;
                h_node->lc = lc;
                h_node->rc = rc;
                add_q_node(h_l, h_node, cnt);
                /*put into a right position*/
        }
        auto h_root = new H_root;
        h_root->_root = get_h_tree_node(h_l);
        return h_root;
}
inline H_root *build_huffman_tree(char *str) {
        unsigned int cnt_array [26] = {0};
        unsigned int len = strlen(str);
        auto str_cpy = new char [len+1];
        strcpy(str_cpy, str);
        while (*str != '\0') {
                cnt_array [*str - 'a']++;
                str++;
        }/*char set is a~z,count the frequency*/
        l_root *h_l;
        init_list(h_l);
        int j = 0;
        for (int i = 0; i < len; i++) {
                if (cnt_array [str_cpy [i] - 'a']) {
                        auto h_node = new H_tree_node;
                        h_node->key = str_cpy [i];
                        h_node->cnt = cnt_array [str_cpy [i] - 'a'];
                        order [j].key = str_cpy [i];
                        order [j].cnt = cnt_array [str_cpy [i] - 'a'];
                        order [j].pos = i;
                        j++;
                        _index++;
                        h_node->lc = nullptr;
                        h_node->rc = nullptr;
                        add_q_node(h_l, h_node, cnt_array [str_cpy [i] - 'a']);
                        cnt_array [str_cpy [i] - 'a'] = 0;
                }
        }
        H_root *h_t;
        h_t = build_H_Tree(h_l);
        return h_t;
}
inline void re_code_txt(record_root *&recd, H_tree_node *root, char *re_code_table, int k) {
        if (root->lc == nullptr&&root->rc == nullptr) {
                re_code_table [k] = '\0';
                auto recd_node = new record;
                recd_node->recode = new char [26 + 4];
                strcpy(recd_node->recode, re_code_table);//recode has been copied
                if (strlen(recd_node->recode) == 0) {
                        recd_node->recode[0] = '0';
                        recd_node->recode [1] = '\0';
                }
                recd_node->next = nullptr;
                recd_node->key = root->key;
                recd_node->cnt = root->cnt;
                if (recd->p_beg == nullptr) {
                        recd->p_beg = recd_node;
                        recd->p_end = recd_node;
                }
                else {
                        recd->p_end->next = recd_node;
                        recd->p_end = recd_node;
                }
        }
        if (root->lc) {
                re_code_table [k] = '0';
                re_code_txt(recd, root->lc, re_code_table, k + 1);
        }
        if (root->rc) {
                re_code_table [k] = '1';
                re_code_txt(recd, root->rc, re_code_table, k + 1);
        }
}
inline record_root *build_record(H_root *h_t) {
        auto recd = new record_root;
        recd->p_beg = nullptr;
        recd->p_end = nullptr;
        char re_code_table [char_set_max_len];
        int k = 0;
        re_code_txt(recd, h_t->_root, re_code_table, k);
        return recd;
}
int mycmy(const void *a, const void *b) {
        int v1 = ((data*)a)->cnt;
        int v2 = ((data*)b)->cnt;
        int p1 = ((data*)a)->pos;
        int p2 = ((data*)b)->pos;
        if (v1 != v2) {
                return v1 - v2;
        }
        else {
                return p1 - p2;
        }
}
inline void verify(char *str,H_tree_node *root) {
        char *ans = new char [char_set_max_len];
        H_tree_node *x = root;
        unsigned int len = strlen(str);
        int index = 0;
        bool flag = true;
        if (x->lc== nullptr&&x->rc==nullptr) {
                if (atoi(str) != 0) {
                        printf("INVALID\n");
                }
                else {
                        for (int i = 0; i < len; i++) {
                                printf("%c",x->key);
                        }
                        printf("\n");
                }
                return;
        }
        for (unsigned int i = 0; i < len; i++) {
                x = (str [i] - '0') ? x->rc : x->lc;
                if (x!=nullptr&&x->lc == nullptr&&x->rc == nullptr) {
                        ans [index++] = x->key;
                        x = root;
                }
        }
        if (x != root) {
                printf("INVALID\n");
                delete [] ans;
        }
        else {
                ans [index] = '\0';
                printf("%s\n", ans);
        }
}
int main() {
        H_root *h_t;
        record_root *recd;
        char txt [max_cnt] = {0};
        scanf("%s", txt);
        unsigned len = strlen(txt);
        unsigned bits = 0;
        char pat_a [char_set_max_len];
        char pat_b [char_set_max_len];
        scanf("%s", pat_a);
        scanf("%s", pat_b);
        h_t = build_huffman_tree(txt);
        recd = build_record(h_t);
        char output [30] [30];
        memset(output, 0, sizeof(output));
        record *recd_node = recd->p_beg;
        char *code = recd_node->recode;
        while (recd_node != nullptr) {
                bits += ((recd_node->cnt)*strlen(code));
                strcpy(output [recd_node->key - 'a'], code);
                recd_node = recd_node->next;
                if (recd_node) {
                        code = recd_node->recode;
                }
        }
        qsort(order, _index, sizeof(data), mycmy);
        int flag = bits & 0x7;
        printf("%d %d\n", len,flag?((bits>>3)+1):(bits>>3));
        for (int i = 0; i < 26; i++) {
                if (order [i].key) {
                        printf("%c:", order [i].key);
                        printf("%s\n", output [order [i].key - 'a']);
                }
        }
        verify(pat_a,h_t->_root);
        verify(pat_b,h_t->_root);
        return 0;
}