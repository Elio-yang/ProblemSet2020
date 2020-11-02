#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
        double v;
        while(scanf("%lf",&v)!=EOF){
                double a_v=(v<0.0)?(-v):v;
                printf("%.2lf\n",a_v);
        }
        return 0;
}