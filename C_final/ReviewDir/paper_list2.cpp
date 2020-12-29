//
// Created by ELIO on 2020/12/29.
//
#include <stdio.h>
#include <stdlib.h>


struct stu {
        int number;//存储学号
        char name[20];//存储名字
        int score[5];//存储成绩
        struct stu *next;//后继指针
};

struct stu *create(void)
{
        int i;
        struct stu *p = NULL, *p0, *head = NULL;
        //p0查找插入位置，head是单表头指针和，p用于申请新结点
        p0 = (struct stu *) malloc(sizeof(struct stu));
        p0->next = NULL;//哨兵结点
        head = p0;
        //链表创建过程
        for (i = 0; i < 30; i++) {
                p = (struct stu *) malloc(sizeof(struct stu));//创建新结点
                scanf("%d%s", &(p->number), &(p->name));//录入学生信息
                scanf("%d%d%d%d", &(p->score[0]), &(p->score[1]), &(p->score[2]), &(p->score[3]));
                p->score[4] = p->score[0] + p->score[1] + p->score[2] + p->score[3];
                // 寻找插入位置、插入 5分
                while (p0->next != NULL && p0->next->number < p->number)
                        p0 = p0->next;//根据学号由低到高的顺序寻找插入位置
                if (p0->next == NULL) {
                        p0->next = p;
                        p->next = NULL;
                } else {
                        p->next = p0->next;
                        p0->next = p;
                }//插入
                p0 = head;//p0置top,为下一次从头寻找插入位置做准备
        }
        p = head;
        head = head->next;//修正表头指针
        free(p); //释放哨兵结点
        return head;
}

void del(struct stu *s)
{
        struct stu *p, *q, *head = NULL;
        if (s == NULL)
                return; //若链表为空，则返回为空的头指针
        p = s;
        //删除不符合条件的第一个节点，直到将head更新为链表中第一个符合条件的节点
        while (p->score[0] < 45 || p->score[1] < 45 || p->score[2] < 68 || p->score[3] < 68 || p->score[4] < 320)
                p = p->next;
        head = p;
        //删除整个链表中不符合条件的节点
        while (p->next != NULL)
                if (p->next->score[0] < 45 || p->next->score[1] < 45 || p->next->score[2] < 68 ||
                    p->next->score[3] < 68 || p->next->score[4] < 320)
                        p->next = p->next->next;
                else
                        p = p->next;
        //打开文件，并将及格的节点输出到文件
        FILE *fp = fopen("D:\\2017scores.txt", "w");
        if (fp == NULL) {
                printf("打开文件失败!\n");
                exit(1);
        }
        q = head;
        while (q != NULL) {
                fprintf(fp, "%d %s %d %d %d %d %d \n", s->number, p->name,
                        p->score[0], p->score[1], p->score[2], p->score[3], p->score[4]);
                q = q->next;
        }
        fclose(fp);
}