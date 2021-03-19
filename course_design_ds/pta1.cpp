/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/3/17
 */


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


using namespace std;

struct word {
        int f;
        char w[32];
        word *next;
};
//0-9 a-z
word *list[36];
char str[25];
int n, m, k;

void build_list(word *&p_list, char *str, int f)
{
        word *this_word = (word *) malloc(sizeof(*this_word));
        this_word->f = f;
        strcpy(this_word->w, str);
        this_word->next = NULL;
        if (!p_list) {
                p_list = this_word;
                return;
        }
        word *ptr = p_list;
        word *prev;
        while (ptr != nullptr) {
                if (strcmp(ptr->w, this_word->w) == 0) {
                        ptr->f = max(ptr->f, this_word->f);
                        return;
                }
                if (ptr->f > this_word->f) {
                        prev = ptr;
                        ptr = ptr->next;
                } else if (ptr->f == this_word->f) {
                        if (strcmp(ptr->w, this_word->w) < 0) {
                                prev = ptr;
                                ptr = ptr->next;
                        } else {
                                break;
                        }
                } else if (ptr->f < this_word->f) {
                        break;
                }
        }
        if (!ptr) {
                prev->next = this_word;
        } else {
                this_word->next = ptr;
                prev->next = this_word;
        }
}

void query(word *list_word)
{
        int cnt = 0;
        while (list_word != nullptr && cnt != k) {
                bool is_prefix = true;
                int len =strlen(str);
                for (int j = 0; j < len; j++) {
                        if (str[j] != list_word->w[j]) {
                                //not prefix
                                is_prefix = false;
                        }
                }
                if (is_prefix == true && strlen(str) != strlen(list_word->w)) {
                        printf("%s\n", list_word->w);
                        cnt++;
                }
                list_word = list_word->next;
        }
        if (cnt == 0) { printf("no suggestion\n"); }
}
int main()
{
        scanf("%d %d %d", &n, &m, &k);
        memset(str, 0, sizeof(str));
        //build
        for (int i = 0; i < n; i++) {
                int feq;
                scanf("%d %s", &feq, str);
                if ('0' <= *str && *str <= '9') {
                        build_list(list[*str - '0'], str, feq);
                } else {
                        build_list(list[*str - 'a' + 10], str, feq);
                }
        }
        //get query
        for (int i = 0; i < m; i++) {
                scanf("%s", str);
                word *list_word;
                if ('0' <= *str && *str <= '9') {
                        list_word = list[*str - '0'];
                } else {
                        list_word = list[*str - 'a' + 10];
                }
                query(list_word);
                if (i != m - 1) { printf("\n"); }
        }
        return 0;
}