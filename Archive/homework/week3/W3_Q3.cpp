#include <cstdlib>
#include <iostream>
struct vertex{
        int key;
        struct vertex *lc;
        struct vertex *rc;
};
using namespace std;
struct vertex* creat();
void path_rec(struct vertex *node, int *path, int len);


int ans[100][100];
int len_id[100];
int id=0;


int main()
{
        struct vertex* T;
        T=creat();
        int path[110]={0};
        path_rec(T, path, 0);
        int max=INT32_MIN;
        int id_m=0;
        for(int i=0;i<id;i++){
                int result=0;
                for(int j=0;j<100;j++){
                        result+=ans[i][j];
                }
                if(result>max){
                        max=result;
                        id_m=i;
                }
        }

        cout<<max<<endl;
        for(int i=0;i<len_id[id_m];i++){
                cout<<ans[id_m][i]<<" ";
        }
        cout<<endl;
        return 0;
}

struct vertex* creat()
{
        int k;
        scanf("%d",&k);
        struct vertex* T;

        if(k==0){
                T= NULL;
        }else{
                T=(struct vertex*)malloc(sizeof(struct vertex));
                T->key=k;
                T->lc=creat();
                T->rc=creat();
        }
        return T;
}



void path_rec(struct vertex *node, int *path, int len)
{
        if (node == NULL) return;
        path[len] = node->key;
        len++;

        if (node->lc == NULL && node->rc == NULL)
        {
                for(int i=0;i<len;i++){
                        ans[id][i]=path[i];
                }
                len_id[id]=len;
                id++;
        } else {
                path_rec(node->lc, path, len);
                path_rec(node->rc, path, len);
        }
}
