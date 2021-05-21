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

        bool operator<(const ansk &b) const
        {
                if (this->feq != b.feq) {
                        return b.feq > this->feq;
                } else {
                        return strcmp(this->word, b.word) > 0;
                }
        }

        bool operator<=(const ansk &b) const
        {
                return (*this < b) || (strcmp(word, b.word) == 0 && feq == b.feq);
        }

        bool operator>(const ansk &b) const
        {
                return !(*this < b);
        }

        ansk &operator=(const ansk &b)
        {
                this->feq = b.feq;
                strcpy(this->word, b.word);
                return *this;
        }

};

inline unsigned int gethash(char *str)
{
        unsigned int b = 378551;
        unsigned int a = 63689;
        unsigned int hash = 0;

        while (*str)
        {
                hash = hash * a + (*str++);
                a *= b;
        }

        return (hash & 0x7FFFFFFF)%(701177);
}


int pi = 0;
ansk num[2010];


typedef struct hash_node {
        int cnt;
        char prefix[25];
        char* ans[10];
        hash_node *next;
} hnode;

hnode *memory[701177] = {NULL};

void swap(void *v1, void *v2, int size)
{
        char buffer[size];
        memcpy(buffer, v1, size);
        memcpy(v1, v2, size);
        memcpy(v2, buffer, size);
}

void _qsort(void *v, int size, int left, int right,
            int (*comp)(void *, void *))
{
        void *vt, *v3;
        int i, last, mid = (left + right) / 2;
        if (left >= right)
                return;
        // casting void* to char* so that operations
        void *vl = (char *) (v + (left * size));
        void *vr = (char *) (v + (mid * size));
        swap(vl, vr, size);
        last = left;
        for (i = left + 1; i <= right; i++) {
                vt = (char *) (v + (i * size));
                if ((*comp)(vl, vt) > 0) {
                        ++last;
                        v3 = (char *) (v + (last * size));
                        swap(vt, v3, size);
                }
        }
        v3 = (char *) (v + (last * size));
        swap(vl, v3, size);
        _qsort(v, size, left, last - 1, comp);
        _qsort(v, size, last + 1, right, comp);
}

void Qsort(void *_base, std::size_t _nmemb, std::size_t _size, int (*_cmp)(void *, void *))
{
        _qsort(_base, _size, 0, _nmemb - 1, _cmp);
}

int cmp(void *a, void *b)
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
                for (i = 0; i < 36; i++) {
                        if (x->alphabet[i] != NULL) {
                                break;
                        }
                }
                if (i == 36) {
                        return no_result;
                }
        }

        for (int i = 0; i < 36; i++) {
                if (x->alphabet[i] == NULL) {
                        continue;
                } else {
                        if (10 <= i && i <= 35) {
                                prefix.push_back('a' + i - 10);
                        } else {
                                prefix.push_back('0' + i);
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
                if (10 <= i && i <= 35) {
                        ans.push_back('a' + i - 10);
                } else {
                        ans.push_back('0' + i);
                }
                dfs(node->alphabet[i], ans);
                ans.pop_back();
        }
}

void Sort(int N, int K)
{
        if (N > K) {
                Qsort(num, N + 1, sizeof(num[0]), cmp);

        } else {
                for (int i = 0; i < N; i++) {
                        for (int j = 1; j < N - i; j++)
                                if (num[j - 1] < num[j]) {
                                        auto temp = num[j - 1];
                                        num[j - 1] = num[j];
                                        num[j] = temp;
                                }
                }
        }
}

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
        //get query
        for (int i = 0; i < m; i++) {
                scanf("%s", str);
                uint32_t Hash = gethash(str);
                //无记忆或者hash冲突
                if (memory[Hash] == NULL || strcmp(memory[Hash]->prefix, str) != 0) {
                        hnode *tmp;
                        if(memory[Hash]==NULL){
                                memory[Hash] = (hnode *) malloc(sizeof(hnode));
                                tmp=memory[Hash];
                        }else{
                                tmp=memory[Hash];
                                while (tmp->next!= NULL){
                                        tmp=tmp->next;
                                }
                                auto *new_node=(hnode *) malloc(sizeof(hnode));
                                tmp->next=new_node;
                                tmp=new_node;
                        }

                        int flag = tree->query(str);

                        if (flag == no_result) {
                                printf("no suggestion\n");
                                tmp->cnt = 0;
                                strcpy(tmp->prefix,str);
                                tmp->next= nullptr;
                        } else {
                                Sort(pi, k);
                                if (pi > k) {
                                        //count
                                        tmp->cnt = k;
                                        strcpy(tmp->prefix,str);
                                        for (int j = 0; j < k; j++) {
                                                tmp->ans[j]=(char *)malloc(sizeof(char)*22);
                                                strcpy(tmp->ans[j],num[j].word);
                                                printf("%s\n", num[j].word);
                                        }
                                        tmp->next = nullptr;
                                } else {
                                        tmp->cnt = pi;
                                        strcpy(tmp->prefix,str);
                                        for (int j = 0; j < pi; j++) {
                                                tmp->ans[j]=(char *)malloc(sizeof(char)*22);
                                                strcpy(tmp->ans[j],num[j].word);
                                                printf("%s\n", num[j].word);
                                        }
                                        tmp->next = nullptr;
                                }
                                memset(num, 0, sizeof(num));
                                pi = 0;
                        }
                } else {
                        //memorized
                        hnode *tmp=memory[Hash];
                        while (tmp!= nullptr){
                                if(strcmp(tmp->prefix,str)==0){
                                        break;
                                }
                                tmp=tmp->next;
                        }
                        int cnt = tmp->cnt;
                        if (cnt == 0) {
                                printf("no suggestion\n");
                        }
                        for (int j = 0; j < cnt; j++) {
                                printf("%s\n", tmp->ans[j]);
                        }
                }
                if (i != m - 1) { printf("\n"); }
        }
        return 0;
}