//
// Created by ELIO on 2020/12/30.
//

#include <stdio.h>
#include <stdlib.h>

struct student{
        int id;
        char name[10];
        int grades[5];
        struct student* next;
};

struct student* creat_list()
{
        struct student* head=(struct student*)malloc(sizeof(struct student));
        head->next= nullptr;

        for (int i = 0; i < 12; i++) {
                struct student* new_stu=(struct student*)malloc(sizeof(struct student));
                scanf("%d %s",&new_stu->id,new_stu->name);
                scanf("%d %d %d %d",&new_stu->grades[0],&new_stu->grades[1],&new_stu->grades[2],&new_stu->grades[3]);
                new_stu->grades[4]=new_stu->grades[0]+new_stu->grades[1]+new_stu->grades[2]+new_stu->grades[3];

                struct student* pos=head;
                while (pos->next!= NULL&&pos->next->id<new_stu->id)
                {
                        pos=pos->next;
                }
                new_stu->next=pos->next;
                pos->next=new_stu;
        }
        struct student* p_start=head->next;
        FILE *fp=fopen(R"(C:\Users\ELIO\Desktop\ProblemSet2020-2021\data2.txt)","w");
        while (p_start!= nullptr){
                fprintf(fp,"%d %s %d %d %d %d\n",p_start->id,p_start->name,
                        p_start->grades[0],p_start->grades[1],p_start->grades[2],p_start->grades[3]);
                p_start=p_start->next;
        }
        return head;
}

void del(struct student*head)
{
        struct student* p_tmp=head;
        while (p_tmp->next!= nullptr){
                if (p_tmp->next->grades[0]<45||
                        p_tmp->next->grades[1]<45||
                        p_tmp->next->grades[2]<68||
                        p_tmp->next->grades[3]<68||
                        p_tmp->next->grades[4]<320){
                        p_tmp->next=p_tmp->next->next;
                }else{
                        p_tmp=p_tmp->next;
                }
        }
        struct student*p_start=head->next;
        FILE *fp=fopen(R"(C:\Users\ELIO\Desktop\ProblemSet2020-2021\data2_out.txt)","w");
        while (p_start!= nullptr){
                fprintf(fp,"%d %s %d %d %d %d\n",p_start->id,p_start->name,
                        p_start->grades[0],p_start->grades[1],p_start->grades[2],p_start->grades[3]);
                p_start=p_start->next;
        }
        fclose(fp);
}

int main()
{
        struct student* head=creat_list();
        del(head);
        return 0;

}

