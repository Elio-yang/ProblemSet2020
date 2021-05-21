/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/3/10
 */

#include "regex_def.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
        string str = "boo@gmail.com  boqian@hotmail.com bo_qian@163.com";
        regex e("([[:w:]]+)@([[:w:]]+)\\.com");
        sregex_token_iterator pos(str.cbegin(), str.cend(), e, 1);// 表示第一个分组，再换成0、2、-1感受一下
        sregex_token_iterator end;

        for(; pos!=end; ++pos)
        {
                cout << "Matched: " << pos->str() << endl;
                cout << endl;
        }
        return 0;
}