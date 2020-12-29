//
// Created by ELIO on 2020/12/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student //结构体定义5分
{
        int number;
        char name[20];
        int grades[3];
        float total;
        struct Student *next;
};

struct Student *create_list() //建立链表有哨兵结点
{
        struct Student *head, *p, *tail;
        head = (struct Student *) malloc(sizeof(struct Student)); //哨兵结点
        tail = head;
        tail->next = NULL;
        FILE *f;
        if ((f = fopen(R"(C:\Users\ELIO\Desktop\ProblemSet2020-2021\grade.txt)", "r")) == NULL) //文件定义、打开、关闭等相关10分
                return 0;
        while (!feof(f)) //文件处理5分
        {
                p = (struct Student *) malloc(sizeof(struct Student));
                fscanf(f, "%d", &p->number);
                fscanf(f, "%s", p->name);
                fscanf(f, "%d", &p->grades[0]);
                fscanf(f, "%d", &p->grades[1]);
                fscanf(f, "%d", &p->grades[2]);
                p->total=0.2*p->grades[0]+0.2*p->grades[1]+0.6*p->grades[2];
                p->next = NULL;
                tail->next = p;
                tail = p;
        }
        fclose(f);
        return head;
}
void sort_select(struct Student *head) //带有哨兵结点的链表排序
{
        struct Student* p_start=head->next;
        struct Student* tmp;
        struct Student* cur=head->next;

        while (cur!=nullptr){

                struct Student* p_min=cur;

                float  max_grade=-1.0;
                //find the max node
                while (p_min!= nullptr){
                        if(p_min->total>max_grade){
                                max_grade=p_min->total;
                                tmp=p_min;
                        }
                        p_min=p_min->next;
                }

                //swap cur and tmp
                int tmp_cur_num=cur->number;
                int tmp_cur_g0=cur->grades[0];
                int tmp_cur_g1=cur->grades[1];
                int tmp_cur_g2=cur->grades[2];
                char *tmp_cur_name=cur->name;
                float tmp_cur_total=cur->total;

                strcpy(cur->name,tmp->name);
                cur->number=tmp->number;
                cur->grades[0]=tmp->grades[0];
                cur->grades[1]=tmp->grades[1];
                cur->grades[2]=tmp->grades[2];
                cur->total=tmp->total;

                tmp->number=tmp_cur_num;
                strcpy(tmp->name,tmp_cur_name);
                tmp->grades[0]=tmp_cur_g0;
                tmp->grades[1]=tmp_cur_g1;
                tmp->grades[2]=tmp_cur_g2;
                tmp->total=tmp_cur_total;

                cur=cur->next;
        }
        FILE *fp=fopen(R"(C:\Users\ELIO\Desktop\ProblemSet2020-2021\sort.txt)","w");

        while (p_start!= nullptr){
                fprintf(fp,"%d ",p_start->number);
                fprintf(fp,"%s ",p_start->name);
                fprintf(fp,"%d %d %d\n",p_start->grades[0],p_start->grades[1],p_start->grades[2]);
                p_start=p_start->next;
        }

}

int main()
{
        struct Student* head=create_list();
        sort_select(head);
        return 0;
}