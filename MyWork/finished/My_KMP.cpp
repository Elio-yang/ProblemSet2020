#include <iostream>
#include <cstring>
const int maxn=10000;
struct Match{
        char pat[maxn];
        char txt[maxn];
        int len_p;
        int len_t;
        int *next;
        int *fail;
        Match(const char *t, const char *p){
                strcpy(txt,t);
                strcpy(pat,p);
                len_p=strlen(p);
                len_t=strlen(t);
                build_fail();
                build_next();
        }

        void build_next(){
                next=new int[len_p];
                next[0]=-1;
                int t=next[0];
                int j=0;
                while (j<len_p-1){
                        //t<0 要放在前面
                        if (t<0||pat[j]==pat[t]){
                                t++;
                                j++;
                                next[j]=t;
                                //next[j]= (pat[j]!=pat[t])?t:next[t];
                        }else{
                                /*反复递推*/
                                t=next[t];
                        }
                }
        }

        void kmp(){
                int i=0;
                int j=0;
                while (i<len_t&&j<len_p){
                        //注意j<0 要放在前面
                        if (j<0||txt[i]==pat[j]){
                                i++;
                                j++;
                        }else{
                                j=next[j];
                        }
                }
                if (j==len_p){
                        int pos=i-j;
                        printf("matching at pos %d\n",pos);
                }else{
                        printf("failed!\n");
                }


                /*对于需要一直匹配的kmp算法
                 * while(i<len_t){
                 *      ......
                 *      if(j==m){
                 *              ans.push(i-j);
                 *              j=next[j-1];
                 *              i--;
                 *      }
                 * }
                 * */
        }

        void build_fail()
        {
                fail=new int[len_p];
                fail[0]=-1;
                for (int j = 1 ; j < len_p ; j++) {
                        int i=fail[j-1];
                        //！！记住
                        while (pat[j]!=pat[i+1]&&i>=0){
                                i=fail[i];
                        }
                        if (pat[j]==pat[i+1]){
                                fail[j]=i+1;
                        }else{
                                fail[j]=-1;
                        }
                }
        }

        void kmp_fail()
        {
                int i=0;
                int j=0;
                while (i<len_t&&j<len_p){
                        if (pat[j]==txt[i]){
                                i++;j++;
                        }
                        else if(j==0){
                                i++;
                        }
                        else{
                                j=fail[j-1]+1;
                        }
                }
                if (j==len_p){
                        printf("matching at pos %d\n",i-j);
                }else{
                        printf("failed!\n");
                }
        }
};

int main()
{
        char txt[maxn];
        char pat[maxn];
        scanf("%s",txt);
        scanf("%s",pat);
        Match match_pair(txt, pat);
        printf("txt : %s\n",match_pair.txt);
        printf("pat : %s\n",match_pair.pat);
        match_pair.kmp();
        printf("next table is:\n");
        for (int i = 0; i < match_pair.len_p; i++) {
                printf("%d ",match_pair.next[i]);
        }
        printf("\n");
        printf("fail table is: \n");
        for (int i = 0; i < match_pair.len_p; i++) {
                printf("%d ",match_pair.fail[i]);
        }

        return 0;
}