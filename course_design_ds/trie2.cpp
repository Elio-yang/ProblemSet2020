/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/3/17
 */

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;
#define not_appear (-1)
#define no_result  (-2)
#define query_ok   (0)


struct ansk {
        char word[21];
        int feq;
};

int pi = 0;
ansk num[11000];

int cmp(const void *a, const void *b)
{
        ansk *pa = ((ansk *) a);
        ansk *pb = ((ansk *) b);
        if (pa->feq != pb->feq) {
                return pb->feq - pa->feq;
        } else {
                return strcmp(pa->word, pb->word);
        }
}
class TrieNode {
public:
        int feq;
        TrieNode *alphabet[36];

        TrieNode()
        {
                memset(alphabet, NULL, sizeof(alphabet));
                feq = not_appear;
        }
};

class Trie {
public:
        TrieNode *root;

        Trie()
        {
                root = new TrieNode();
        }

        void insert(char *str, int f);
        int query(char *str);
        void dfs(TrieNode *node, string &ans);
};

void Trie::insert(char *str, int f)
{
        TrieNode *x = root;
        int index;
        for (; *str; str++) {
                if (isalpha(*str)) {
                        index = *str - 'a' + 10;
                } else {
                        index = *str - '0';
                }
                if (x->alphabet[index] == nullptr) {
                        x->alphabet[index] = new TrieNode();
                        x = x->alphabet[index];
                } else {
                        x = x->alphabet[index];
                }
        }
        x->feq = max(x->feq, f);
}

int Trie::query(char *str)
{
        TrieNode *x = root;
        int index;
        string prefix;
        for (; *str; str++) {
                if (isalpha(*str)) {
                        index = *str - 'a' + 10;
                } else {
                        index = *str - '0';
                }
                prefix.push_back(*str);
                if (x->alphabet[index] == nullptr) {
                        return no_result;
                } else {
                        x = x->alphabet[index];
                }
        }
        //prefix == this_word
        if (x->feq != not_appear) {
                int i;
                /* not only this word */
                for (i= 0; i < 36; i++) {
                        if (x->alphabet[i] != NULL) {
                                break;
                        }
                }
                if(i==36){
                        return no_result;
                }
        }

        for (int i = 0; i < 36; i++) {
                if (x->alphabet[i] == NULL) {
                        continue;
                } else {
                        if (0 <= i && i <= 9) {
                                prefix.push_back('0' + i);
                        } else {
                                prefix.push_back('a' + i - 10);
                        }
                        dfs(x->alphabet[i], prefix);
                        /* 回溯 */
                        prefix.pop_back();

                }
        }
        return query_ok;
}
void Trie::dfs(TrieNode *node, string &ans)
{
        //is a word
        if (node->feq != not_appear) {
                strcpy(num[pi].word, ans.c_str());
                num[pi].feq = node->feq;
                pi++;
        }
        for (int i = 0; i < 36; i++) {
                if (node->alphabet[i] == NULL) {
                        continue;
                }
                if (0 <= i && i <= 9) {
                        ans.push_back('0' + i);
                } else {
                        ans.push_back('a' + i - 10);
                }
                dfs(node->alphabet[i], ans);
                ans.pop_back();
        }
}
struct word{
        char w[25];
};

typedef struct memory{
        int flag;
        struct hash_table *next;
        char prefix[25];
        int cnt;
        struct word mm[0];
}Memory;

int main()
{
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        auto *tree = new Trie();
        char str[25];
        memset(str, 0, sizeof(str));
        //build trie
        for (int i = 0; i < n; i++) {
                int feq;
                scanf("%d %s", &feq, str);
                tree->insert(str, feq);
                memset(str, 0, sizeof(str));
        }

        Memory *list =(Memory*)malloc(sizeof(*list));
        list->flag=0;
        memset(list->prefix,0, sizeof(list->prefix));
        list->next= nullptr;
        //get query
        for (int i = 0; i < m; i++) {
                Memory *ptr=list;
                scanf("%s", str);
                int exit_f=0;
                //ptr is the last pointer
                while(ptr->next!= nullptr){
                        if(strcmp(str,ptr->prefix)==0){
                                exit_f=1;
                                break;
                        }
                        ptr=ptr->next;
                }
                if(strcmp(str,ptr->prefix)==0){
                        exit_f=1;
                }
                if(exit_f==1){
                        if(ptr->flag==0){
                                printf("no suggestion\n");
                        }
                        else{
                                for(int l=0;l<ptr->cnt;l++){
                                        printf("%s\n",ptr->mm[l].w);
                                }
                        }
                }
                else {
                        int flag = tree->query(str);
                        if (flag == no_result) {
                                Memory *node=(Memory*)malloc(sizeof(*list));
                                memset(node->prefix,0, sizeof(node->prefix));
                                node->flag=0;
                                strcpy(node->prefix,str);
                                node->next=ptr->next;
                                ptr->next=node;
                                printf("no suggestion\n");

                        } else {
                                ansk *ps = num;
                                qsort(ps, pi+1, sizeof(ps[0]), cmp);
                                Memory *node;
                                if(pi>=k-1){
                                        node=(Memory*)malloc(sizeof(*list)+ sizeof(struct word)*k);
                                        memset(node->prefix,0, sizeof(node->prefix));
                                        node->cnt=k;
                                        node->flag=1;
                                        strcpy(node->prefix,str);
                                        for(int l=0;l<k;l++){
                                                printf("%s\n", num[l].word);
                                                strcpy(node->mm[l].w, num[l].word);
                                        }
                                        node->next=ptr->next;
                                        ptr->next=node;
                                }
                                else{
                                        node=(Memory*)malloc(sizeof(*list)+ sizeof(struct word)*pi);
                                        memset(node->prefix,0, sizeof(node->prefix));
                                        node->cnt=pi;
                                        node->flag=1;
                                        strcpy(node->prefix,str);
                                        for(int l=0;l<pi;l++){
                                                printf("%s\n", num[l].word);
                                                strcpy(node->mm[l].w, num[l].word);
                                        }
                                        node->next=ptr->next;
                                        ptr->next=node;
                                }
                                memset(num, 0, sizeof(num));
                                pi = 0;
                        }
                }
                if (i != m - 1) { printf("\n"); }
        }
        return 0;
}