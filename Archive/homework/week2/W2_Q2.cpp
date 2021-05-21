#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char str[16]={'0','a','b','c','d','e','f','g','h','i','j'
        ,'k','l','m','n','o'};
unsigned int musk(unsigned len);
unsigned int power_2n(unsigned n);

int cmp(const void* a, const void* b)
{
        return strcmp((char *)a,(char *)b) ;
}

int main()
{
        unsigned n;
        scanf("%u",&n);   
        unsigned ans=0x0;
        unsigned all=power_2n(n);
        char out[all-1][17];
        memset(out,0,sizeof(out));
        printf("{}\n");
        for(unsigned i=1;i<=all-1;i++){
                ans=ans+0x1;
                unsigned int k=0;
                for(unsigned int j=1;j<=n;j++){
                        unsigned int M=musk(j);
                        if((ans&M)!=0x0){
                                out[i-1][k++]=str[j];
                        }
                }
                
        }
        qsort(out,all-1,sizeof(out[0]),cmp);
        for(unsigned i=0;i<all-1;i++){
                printf("{");
                unsigned len=strlen(out[i]);
                for(unsigned j=0;j<len;j++){
                        if(j!=len-1){
                                printf("%c,",out[i][j]);
                        }else{
                                printf("%c",out[i][len-1]);
                        }
                }
                printf("}\n");
                
        }
        system("pause");
        return 0;
}

unsigned int musk(unsigned int len)
{
        unsigned int musk=0x00000000000001<<(len-1);
        return musk;
}

unsigned int power_2n(unsigned n)
{
        int ans=1;
        for(unsigned i=1;i<=n;i++){
                ans*=2;
        }
        return ans;
}
