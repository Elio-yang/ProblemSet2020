#include <cstdio>
#include <cstring>

const int max_t=1000;

int brute_force(const char *txt,const char *pat)
{
        size_t l_t=strlen(txt);
        int i=0;
        size_t l_p=strlen(pat);
        int j=0;
        while (i<l_t&&j<l_p){
                if (txt[i]==pat[j]){
                        i++;
                        j++;
                }else{
                        /*txt右移一个，pat从0开始*/
                        i=i-j+1;
                        j=0;
                }
        }
       if (j==l_p){return i-j;}
       else return -1;
}

int main()
{
        char txt[max_t];
        char pat[max_t];
        scanf("%s",txt);
        scanf("%s",pat);
        printf("txt : %s\n",txt);
        printf("pat : %s\n",pat);

        int pos=brute_force(txt,pat);
        if (pos!=-1){
                printf("matching at position %d\n",pos);
        }else{
                printf("failed!\n");
        }


        return 0;
}