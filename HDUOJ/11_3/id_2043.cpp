#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

set<char> special={'~','!','@','#','$','%','^'};
#define isCap(c) ('A'<=c&&c<='Z')
#define isSmal(c) ('a'<=c&&c<='z')
#define isNum(c) ('0'<=c&&c<='9')

int main()
{
        int m;
        scanf("%d",&m);
        while(m--){
                int f1=0;
                int f2=0;
                int f3=0;
                int f4=0;
                char str[55];
                scanf("%s",str);
                int len=strlen(str);
                if(!(8<=len&&len<=16)){
                      printf("NO\n");
                }else{
                        char *pos=str;
                        while(*pos!='\0'){
                                if(special.count(*pos)){
                                        f1=1;
                                }
                                if(isCap(*pos)){
                                        f2=1;
                                }
                                if(isSmal(*pos)){
                                        f3=1;
                                }
                                if(isNum(*pos)){
                                        f4=1;
                                }
                                pos++;
                        }
                        if(f1+f2+f3+f4>=3){
                                printf("YES\n");
                        }else{
                                printf("NO\n");
                        }
                }
        }

        return 0;
}
