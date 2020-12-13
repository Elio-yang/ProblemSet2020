#include <cstdio>
#include <cstdlib>
using namespace std;
struct data{
        int u;
        int v;
        int w;
};
int cmp(const void *a,const void *b)
{
        return (((data*)a)->u != ((data*)b)->u)?(((data*)a)->u - ((data*)b)->u):(((data*)a)->v - ((data*)b)->v);
}

int main(){

        FILE *fp=fopen(R"(C:\Users\ELIO\Desktop\ProblemSet2020-2021\P1629_1.txt)","r");
        data DataSet[10000];
        int i=0;
        while (!feof(fp)) {
                fscanf(fp, "%d%d%d", &DataSet[i].u, &DataSet[i].v, &DataSet[i].w);
                i++;
        }
        qsort(DataSet+1,i-1,sizeof(DataSet[0]),cmp);
        fclose(fp);
        FILE *F=fopen(R"(C:\Users\ELIO\Desktop\ProblemSet2020-2021\test_data.txt)","w");
        for (int j = 0; j < i-1; j++) {
                fprintf(F,"%d %d %d\n",DataSet[j].u,DataSet[j].v,DataSet[j].w);
        }
        return 0;
}