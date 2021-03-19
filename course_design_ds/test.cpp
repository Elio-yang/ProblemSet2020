#include <iostream>
using namespace std;

unsigned int gethash(char *str)
{
        unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
        unsigned int hash = 0;

        while (*str)
        {
                hash = hash * seed + (*str++);
        }

        return (hash & 0x7FFFFFFF);
}

int main()
{
        char *str="zzzzzzzzzzzzzzzzzzzz";
        uint32_t ans= gethash(str);
        printf("%d",ans);
}