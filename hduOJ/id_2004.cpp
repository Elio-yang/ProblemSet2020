#include <cstdio>
int main()
{

        int g;
        while(scanf("%d",&g)!=EOF){
            
                if(90<=g&&g<=100){
                        printf("A\n");
                }
                else if(80<=g&&g<=89){
                        printf("B\n");
                }
                else if(70<=g&&g<=79){
                        printf("C\n");
                }
                else if(60<=g&&g<=69){
                        printf("D\n");
                }
                else if(0<=g&&g<=59){
                        printf("E\n");
                }
                else{
                        printf("Score is error!\n");
                }
        }
        return 0;
}