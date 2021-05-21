#include <stdio.h>
#include <stdlib.h>

struct Mark //结构体定义5分
{
        int number;
        char name[20];
        int talkMark;
        int reportMark;
        int testMark;
        struct Mark *next;
};

int infoOutput(struct Mark *head)
{
        FILE *fp;
        if ((fp = fopen("2018ExpChange.txt", "w")) == NULL) //文件相关操作10分
                return -1;
        struct Mark *tempNode = head;
        while (tempNode != NULL) //链表操作10分
        {
                if (tempNode->testMark >= 85) {
                        tempNode->talkMark = 100;
                        tempNode->reportMark = 100;
                        fprintf(fp, "%d ", tempNode->number);
                        fprintf(fp, "%s ", tempNode->name);
                        fprintf(fp, "%d ", tempNode->talkMark);
                        fprintf(fp, "%d ", tempNode->reportMark);
                        fprintf(fp, "%d\n", tempNode->testMark);
                }
                tempNode = tempNode->next;
        }
        fclose(fp);
        return 0;
}

int orderOutput(struct Mark *head) //参考答案未排序，仅输出，也可先排序再输出
{
        struct Mark *tempNode = head;
        int n = 0;
        //计算一共有多少个学生
        while (tempNode != NULL) //统计个数5分
        {
                n++;
                tempNode = tempNode->next;
        }
        int count = 0;
        float preMark = 100;
        struct Mark *printNode;
        while (count < n) //循环5分
        {
                printNode = NULL;
                tempNode = head;
                //查找链表中比之前打印的分数低的学生中分数最高的学生
                while (tempNode != NULL) //查找下一个分数5分
                {
                        if (ExpMark(tempNode) < preMark &&
                            (printNode == NULL || ExpMark(printNode) < ExpMark(tempNode)))
                //利用了求实验成绩的子函数，需自行定义
                                printNode = tempNode;
                        tempNode = tempNode->next;
                }
                tempNode = head;
                //检查链表中所有此分数的学生，全部打印出来，5分
                FILE *fp = NULL;
                fp = fopen("2018Exp.txt", "a+");
                while (tempNode != NULL) {
                        if (ExpMark(tempNode) == ExpMark(printNode)) {
                                fprintf(fp, "%d ", tempNode->number);
                                fprintf(fp, "%s ", tempNode->name);
                                fprintf(fp, "%d ", tempNode->talkMark);
                                fprintf(fp, "%d ", tempNode->reportMark);
                                fprintf(fp, "%d\n", tempNode->testMark);
                                count++;
                        }
                        tempNode = tempNode->next;
                }
                fclose(fp);
                preMark = ExpMark(printNode);
        }
        return 0;
}