#include <cstdio>
#include <cstdlib>

#define MAXVEX 100    //最大顶点数
#define INFINITY 65535    //用0表示∞

#define OK 1
#define ERROR 0


typedef int Status;

typedef char VertexType;    //顶点类型，字符型A,B,C,D...
typedef int EdgeType;    //边上权值类型10,15,...

//邻接矩阵结构
typedef struct
{
        VertexType vertexs[MAXVEX];    //顶点表
        EdgeType G_matrix[MAXVEX][MAXVEX];    //邻接矩阵，可看作边表
        int numVertexes, numEdges;    //图中当前的顶点数和边数
}MGraph;
typedef struct edge //边表结点
{
        int adj_vex;
        int w;
        struct edge* next;
}edge;

typedef struct VertexNode    //顶点表结点
{
        int in;
        VertexType data;
        edge* first_edge;
}AdjList[MAXVEX];


//邻接表结构
typedef struct Adj
{
        AdjList adj_list;
        int numVertexes, numEdges;    //图中当前的顶点数和边数
}AdjGraphList;

int *etv, *ltv;    //事件最早发生时间和最晚发生时间数组
int *stack2;    //用于存储拓扑序列的栈
int top2;        //用于stack2的指针，后面求关键路径时需要

//创建邻接矩阵
void CreateMGraph(MGraph* G);
//显示邻接矩阵
void showGraph(MGraph G);
//邻接矩阵转邻接表
void Matrix_AdjList(MGraph G, AdjGraphList* AG);
//拓扑排序
Status TopologicalSort(AdjGraphList AG);
//获取求ete，lte和关键活动
void CriticalPath(AdjGraphList AG);
//显示事件的最早和最晚发生时间
void ShowVertexTime(int n);

int main()
{
        MGraph MG;
        AdjGraphList AG;
        CreateMGraph(&MG);
        showGraph(MG);
        Matrix_AdjList(MG, &AG);
        CriticalPath(AG);
        ShowVertexTime(AG.numVertexes);
        return 0;
}

//生成邻接矩阵
void CreateMGraph(MGraph* G)
{
        int i, j, k, w;
        G->numVertexes = 9;
        G->numEdges = 11;
        //读入顶点信息
        G->vertexs[0] = 'A';
        G->vertexs[1] = 'B';
        G->vertexs[2] = 'C';
        G->vertexs[3] = 'D';
        G->vertexs[4] = 'E';
        G->vertexs[5] = 'F';
        G->vertexs[6] = 'G';
        G->vertexs[7] = 'H';
        G->vertexs[8] = 'I';

        //getchar();    //可以获取回车符
        for (i = 0; i < G->numVertexes; i++)
                for (j = 0; j < G->numVertexes; j++)
                        G->G_matrix[i][j] = INFINITY;    //邻接矩阵初始化

        //创建了有向邻接矩阵
        G->G_matrix[0][1] = 6;
        G->G_matrix[0][2] = 4;
        G->G_matrix[0][3] = 5;
        G->G_matrix[1][4] = 1;
        G->G_matrix[2][4] = 1;
        G->G_matrix[3][5] = 2;
        G->G_matrix[4][6] = 7;
        G->G_matrix[4][7] = 5;
        G->G_matrix[5][7] = 4;
        G->G_matrix[6][8] = 2;
        G->G_matrix[7][8] = 4;
}


//显示邻接矩阵
void showGraph(MGraph G)
{
        for (int i = 0; i < G.numVertexes; i++)
        {
                for (int j = 0; j < G.numVertexes; j++)
                {
                        if (G.G_matrix[i][j] != INFINITY)
                                printf("%5d", G.G_matrix[i][j]);
                        else
                                printf("    0");
                }
                printf("\n");
        }
}

void Matrix_AdjList(MGraph G, AdjGraphList* AG)
{
        int i, j;
        edge* edge;
        AG->numEdges = G.numEdges;
        AG->numVertexes = G.numVertexes;

        for (i = 0; i < G.numVertexes; i++)
        {
                AG->adj_list[i].data = G.vertexs[i];
                AG->adj_list[i].in = 0;
                AG->adj_list[i].first_edge = nullptr;
        }

        for (i = 0; i < G.numVertexes; i++)
        {
                for (j = 0; j < G.numVertexes; j++)
                {
                        if (G.G_matrix[i][j] != INFINITY)
                        {
                                edge = (struct edge*)malloc(sizeof(edge));
                                edge->adj_vex = j;
                                edge->w = G.G_matrix[i][j];
                                edge->next = AG->adj_list[i].first_edge;
                                AG->adj_list[i].first_edge = edge;
                                AG->adj_list[j].in++;
                        }
                }
        }
}

Status TopologicalSort(AdjGraphList AG)
{
        edge* e;
        int i, k, get_top;
        int count = 0;    //用于统计输出顶点个数

        int top = -1;    //这是我们要创建的栈的指针
        int *stack = (int*)malloc(sizeof(int)*AG.numVertexes);    //这是我们创建的临时栈

        //最开始将所有入度为0的顶点入栈
        for (i = 0; i < AG.numVertexes; i++)
                if (AG.adj_list[i].in==0)
                        stack[++top] = i;
        //初始化全局数组stack2,etv,ltv
        top2 = -1;
        etv = (int *)malloc(AG.numVertexes*sizeof(int));
        for (i = 0; i < AG.numVertexes; i++)
                etv[i] = 0;    //初始化为0
        stack2 = (int *)malloc(sizeof(int)*AG.numVertexes);
        //下面进入主循环，直到栈中无数据结束
        while (top != -1)
        {
                //出栈数据
                get_top = stack[top--];    //出栈
                count++;

                stack2[++top2] = get_top;    //将弹出的栈顶序号压入拓扑序列的栈中

                //对他出栈数据的所有邻接点的入度减一
                for (e = AG.adj_list[get_top].first_edge; e; e = e->next)
                {
                        k = e->adj_vex;
                        if (!(--AG.adj_list[k].in))
                                stack[++top] = k;

                        if ((etv[get_top] + e->w) > etv[k])    //求各个顶点事件最早发生时间
                                etv[k] = etv[get_top] + e->w;
                }
        }
        //进行判断，若是count小于顶点数，则有环
        if (count < AG.numVertexes)
                return ERROR;
        return OK;
}

void CriticalPath(AdjGraphList AG)
{
        edge* e;
        int i, j, k, get_top;
        int ete, lte;    //声明获得最早发生时间和最迟发生时间变量

        TopologicalSort(AG);    //求得拓扑序列，获得etv数组和stack2数组

        ltv = (int *)malloc(sizeof(int)*AG.numVertexes);    //事件最晚发生时间数组

        for (i = 0; i < AG.numVertexes; i++)
                ltv[i] = etv[AG.numVertexes - 1];    //全部初始化为倒序第一个

        while (top2!=-1)
        {
                get_top = stack2[top2--];    //倒序获取每个顶点,从终点开始，由于终点都没有邻接点，所以我们不会修改数据，始终保持etv[n-1],公式情况一
                //根据求ltv的公式，我们开始补全ltv数组
                for (e = AG.adj_list[get_top].first_edge; e; e=e->next)    //这个for循环针对的是非终点，有出度边，情况二
                {
                        k = e->adj_vex;    //k是他的下一个邻接点的下标，我们会修改他，按照情况二
                        if (ltv[k] - e->w < ltv[get_top])    //求各个顶点事件的最晚发生时间
                                ltv[get_top] = ltv[k] - e->w;
                }
        }

        for (i = 0; i < AG.numVertexes;i++)    //i代表顶点下标
        {
                for (e = AG.adj_list[i].first_edge; e; e=e->next)
                {
                        k = e->adj_vex;    //获取邻接点
                        ete = etv[i];    //ete是由顶点i发起的活动,这是其活动最早开始时间
                        lte = ltv[k] - e->w;    //获取其中某一个邻接点的活动最迟发生时间,我们针对一个顶点会对其所有邻接点进行获取判断
                        //我们获取的是活动，是弧，弧的尾由i结点，头由k决定
                        if (ete==lte)
                                printf("<%c,%c> length:%d, ", AG.adj_list[i].data, AG.adj_list[k].data, e->w);
                }
        }
        printf("\n");
}

void ShowVertexTime(int n)
{
        int i;
        printf("Vex  ");
        for (i = 0; i < n; i++)
        {
                printf("v%d   ", i);
        }
        printf("\netv  ");
        for (i = 0; i < n; i++)
        {
                printf("%2d   ", etv[i]);
        }
        printf("\nltv  ");
        for (i = 0; i < n; i++)
        {
                printf("%2d   ", ltv[i]);
        }
}