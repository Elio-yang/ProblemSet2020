#include <cstdio>
#define PI 3.1415927

int main()
{
        double r;
        while(scanf("%lf",&r)!=EOF){
                double V= 4.0/3 * PI *r*r*r;
                printf("%.3lf\n",V);
        }
        return 0;
}