/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/8
 */

/*
 编写程序，从键盘读入形如X + Y=的表达式计算结果，
 其中X和Y都是合法且长度不超过64位的十六进制非负整数，结果
 中所有字符均大写且无多余的零。

 样例1：输入 1234+1234=输出0X2468
 样例2：输入 0000+12A= 输出0X12A
 样例3：输入 12ff+1= 输出 0X1300

 */


/*Hex Big Integer addition */
#include <cstdio>
#include <cstring>
#include <cctype>
#include <malloc.h>

#define length 70
#define max_l 150

/*
 * replaced by strrev() from string.h
 * */
char *str_rev(char *str)
{
        int len = strlen(str);
        char *new_str = (char *) malloc(sizeof(char) * (len + 20));
        int j = 0;
        for (int i = len - 1; i >= 0; i--) {
                new_str[j++] = str[i];
        }
        new_str[j] = '\0';
        return new_str;
}

int main()
{
        char BI_A[length];
        char BI_B[length];
        char out_char[length + 5];
        char in_char[max_l];
        memset(out_char, 0, sizeof(out_char));
        memset(BI_A, 0, sizeof(BI_A));
        memset(BI_B, 0, sizeof(BI_B));

        scanf("%s", in_char);
        size_t len = strlen(in_char);

        int pos_plus = 0;
        int i;
        for (i = 0; i < len; i++) {
                if (in_char[i] == '+') {
                        pos_plus = i;
                        break;
                } else if (isdigit(in_char[i])) {
                        BI_A[i] = in_char[i];
                } else if (isalpha(in_char[i])) {
                        BI_A[i] = toupper(in_char[i]);
                }
        }

        int j = 0;
        int k;
        for (k = pos_plus + 1; k < len; k++) {
                if (isdigit(in_char[k])) {
                        BI_B[j++] = in_char[k];
                } else if (isalpha(in_char[k])) {
                        BI_B[j++] = toupper(in_char[k]);
                }
        }

        strcpy(BI_A, str_rev(BI_A));
        strcpy(BI_B, str_rev(BI_B));

        int len1 = strlen(BI_A);
        int len2 = strlen(BI_B);
        int max_len = (len1 > len2) ? len1 : len2;
        int carry_in = 0;
        int tmpa = 0;
        int tmpb = 0;

        int l;
        for (l = 0; l <= max_len; l++) {
                if (l == max_len) {
                        if (carry_in != 0) {
                                out_char[l] = carry_in + '0';
                        } else {
                                l--;
                                break;
                        }
                }

                if (isdigit(BI_A[l])) {
                        tmpa = BI_A[l] - '0';
                } else if (isupper(BI_A[l])) {
                        tmpa = BI_A[l] - 'A' + 10;
                }

                if (isdigit(BI_B[l])) {
                        tmpb = BI_B[l] - '0';
                } else if (isupper(BI_B[l])) {
                        tmpb = BI_B[l] - 'A' + 10;
                }


                int ans = tmpa + tmpb + carry_in;
                carry_in = ans / 16;

                int cur_num = ans - 16 * carry_in;
                if (cur_num >= 10) {
                        out_char[l] = 'A' + cur_num - 10;
                } else {
                        out_char[l] = '0' + cur_num;
                }
                tmpa = 0;
                tmpb = 0;
        }
        int m;
        for (m = l; m >= 0; m--) {
                if (out_char[m] != '0') {
                        break;
                } else {
                        out_char[m] = '\0';
                }
        }
        strcpy(out_char, str_rev(out_char));
        printf("0X%s", out_char);
        return 0;
}