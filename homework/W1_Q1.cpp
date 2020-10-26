#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

#define maxn 50010

int main()
{
        char str[maxn];
        int j=1;
        char c;
        while((c=getchar())!='\n'){
                str[j++]=c;
        }
        str[j]='\0';
        printf("%s\n",str+1);

        unsigned short next_table[maxn];
        next_table[0]=0;

        /*用于定位*/
        int cur=0;
        int last=0;

        /*存'='删掉的*/
        bool delete_all[maxn]={0};
        int delete_cur=0;

        /*用于'{'*/
        int tmp_index_cur=0;

        /*用于'-'*/
        int tmp_index_insert1=0;
        int tmp_index_insert2=0;
        int tmp_cur_insert=0;
        int cnt_insert=0;
        int length=strlen(str+1);
        
        for(int i=1;i<=length;i++){
                if(str[i]=='['){
                        cur=0;
                }
                else if(str[i]==']'){
                        cur=last;
                }
                else if(str[i]=='{'){
                        cur--;
                        //tmp_index_cur=cur+1;
                        tmp_index_cur=next_table[cur];

                }
                else if(str[i]=='}'){
                        //cur=tmp_index_cur;
                        cur=next_table[cur];
                 }
                /*{ 与 } 跟 [ 与 ] 类似，{}对于cur的移动是一个字符单位，[]是直接移到最首或者最后*/

                else if(str[i]=='-'){
                        cnt_insert++;
                        tmp_index_insert1=i;
                        if(cnt_insert>0&&cnt_insert%2==0){//遇到配对的停止替换符
                                int len=tmp_index_insert1-tmp_index_insert2-1;//替换多少元素
                                int index_last=cur;
                                for(int j=0;j<len;j++){
                                        if(next_table[index_last]!=0){
                                                index_last=next_table[index_last];
                                        }
                                }
                                next_table[cur]=next_table[index_last];
                                tmp_index_cur=next_table[cur];
                        }
                        tmp_index_insert2=tmp_index_insert1;
                }
                else if(str[i]=='='){
                        if(isalpha(str[cur])){
                                delete_all[cur]=true;
                        }
                        cur--;
                        // next_table[cur]=0;
                }
                else{
                        next_table[i]=next_table[cur];
                        next_table[cur]=i;
                        if(cur==last){
                                last=i;
                        }
                        cur=i;

                }
        }
        for(int i=next_table[0];i!=0;i=next_table[i]){
                if(delete_all[i]==false){
                         printf("%c",str[i]);
                }
        }
        system("pause");
        return 0;
}