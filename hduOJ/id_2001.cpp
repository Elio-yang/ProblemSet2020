#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;


int main()
{
        double x1,y1,x2,y2;
        while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF){
                double l1=abs(x2-x1)/1.0;
                double l2=abs(y2-y1)/1.0;
                double dis=sqrt(l1*l1+l2*l2);
                printf("%.2lf\n",dis);
        }
        return 0;
}