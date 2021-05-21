//
// Created by ELIO on 2020/12/27.
//

#include <stdio.h>
#include <string.h>
#define max 20
long long hash(char *str)
{
        long long value=0;
        int len=strlen(str);
        for (int i = 0; i < len; i++) {
                value=(value<<5)+ *str++;
        }
        return value%163227661;
}

int main()
{
        char str1[max];
        char str2[max];
        char str3[max];
        char str4[max];
        char str5[max];
        char str6[max];
        scanf("%s",str1);
        scanf("%s",str2);
        scanf("%s",str3);
        scanf("%s",str4);
        scanf("%s",str5);
        scanf("%s",str6);
        long long val1=hash(str1);
        long long val2=hash(str2);
        long long val3=hash(str3);
        long long val4=hash(str4);
        long long val5=hash(str5);
        long long val6=hash(str6);
        int freq=0;
        if (val6==val1){freq++;}
        if (val6==val2){freq++;}
        if (val6==val3){freq++;}
        if (val6==val4){freq++;}
        if (val6==val5){freq++;}

       printf("%d",freq);




       return 0;
}