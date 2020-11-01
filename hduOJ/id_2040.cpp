#include <cstdio>

int main()
{
        int n;
        scanf("%d",&n);
        while(n--){
                if(!(n>=0&&n<=600000)){
                        continue;
                }
                int num1,num2;
                int ans1=0;
                int ans2=0;
                scanf("%d %d",&num1,&num2);
                for(int i=1;i<num1;i++){
                        if(num1%i==0){
                                ans1+=i;
                        }
                }
                for(int i=1;i<num2;i++){
                        if(num2%i==0){
                                ans2+=i;
                        }
                }
                if((ans1==num2)&&(ans2==num1)){
                        printf("YES\n");
                }else{
                        printf("NO\n");
                }
        }
        return 0;
}