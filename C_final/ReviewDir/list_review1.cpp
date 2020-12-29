//
// Created by ELIO on 2020/12/29.
//

/*
假定每个学生的《程序设计基础》成绩信息包括：学号、姓名、MOOC成绩、实验成绩、期中成绩、期末成绩6项。要求：
1）定义存储成绩信息的单向链表的结点类型；
2）假定所有学生的成绩信息均存储在D盘根目录下的2017scores.txt中，
  《程序设计基础》总成绩=MOOC成绩*20%+实验成绩*20%+期中成绩*20%+期末成绩*40%，
   四个单项成绩和总成绩均介于[0, 100]之间（实际情况下的计算方式可能略有不同）。
   编写函数，从该文件中读出所有信息，创建一个用于管理学生成绩信息的单向链表，
   并在创建过程中随时保证该单向链表的结点顺序满足：按《程序设计基础》总成绩从高到低的顺序。
注：必须包含且仅包含与该题相关的头文件。

 假定MOOC成绩、实验成绩和总成绩的及格分数线均设定为60分。如果MOOC成绩或实验成绩之一为不及格，则总成绩默认为不及格
 （实际情况下的计算方式可能略有不同）。编写函数，在第四题构建的单向链表中，删除总成绩不及格的学生。

 注：必须包含且仅包含与该题相关的头文件。
*/
#include <stdio.h>
#include <stdlib.h>
struct student{
        int id;
        char name[10];
        int grades[4];
        double total;
        struct student*next;
};

struct student* list_creat()
{
        FILE *fp=fopen(R"(C:\Users\ELIO\Desktop\ProblemSet2020-2021\data1.txt)","r");
        if (fp==NULL){
                printf("FILE OPEN FAILURE!\n");
                exit(0);
        }

        struct student* head=(struct student*)malloc(sizeof(struct student));
        head->next= nullptr;


        while (!feof(fp)){

                struct student* new_stu=(struct student*)malloc(sizeof(struct student));
                fscanf(fp,"%d",&new_stu->id);
                fscanf(fp,"%s",new_stu->name);
                fscanf(fp,"%d %d %d %d\n",&new_stu->grades[0],&new_stu->grades[1],&new_stu->grades[2],&new_stu->grades[3]);
                double total=0.2*new_stu->grades[0]+0.2*new_stu->grades[1]+0.2*new_stu->grades[2]+0.4*new_stu->grades[3];
                new_stu->total=total;

                struct student* pos=head;
                while (pos->next!= nullptr&&pos->next->total>new_stu->total)
                {
                        pos=pos->next;
                }
                /*
                 * 跳出的条件：
                 * pos->next == nullptr
                 * pos->next->total <= new_stu->total
                 * */
                new_stu->next=pos->next;
                pos->next=new_stu;
        }
        return head;
}

void del(struct student* head)
{
        struct student* p_start=head->next;
        struct student* p_tmp=head;
        while (p_tmp->next!=NULL){
                if (p_tmp->next->total<60||p_tmp->next->grades[0]<60||p_tmp->next->grades[1]<60||p_tmp->next->grades[2]<60||p_tmp->next->grades[3]<60){
                        p_tmp->next=p_tmp->next->next;
                }else{
                        p_tmp=p_tmp->next;
                }
        }
        FILE *fp=fopen(R"(C:\Users\ELIO\Desktop\ProblemSet2020-2021\data1_out.txt)","w");
        while (p_start!= nullptr){
                fprintf(fp,"%d ",p_start->id);
                fprintf(fp,"%s ",p_start->name);
                fprintf(fp,"%d %d %d %d %lf\n",p_start->grades[0],p_start->grades[1],p_start->grades[2],p_start->grades[3],p_start->total);
                p_start=p_start->next;
        }
        fclose(fp);
}
int main()
{
        struct student* head=list_creat();
        del(head);
        return 0;

}




