#include<stdio.h>
int Arr[110][110];//最大迷宫为30*30
int Rownum=0,Colnum=0;//行列数
int Beginrow,Begincol,Endrow,Endcol;//终点坐标
int state=0;//迷宫走通与否状态
int canplace(int row,int col)//判断当前点能否走通
{
    if(row>=0 &&col>=0 &&row<Rownum &&col<Colnum &&Arr[row][col]==0)//为越界且可走通
        return 1;
    return 0;
}
void search(int row,int col)
{
    if(row==Endrow && col==Endcol)//是目标终点    
    {    state=1;  return ;   }
    
    int r,c,num;
        num=Arr[row][col];
        r=row-1; c=col; //上
    if(canplace(r,c))  { Arr[r][c]=num+1; search(r,c); }
    r=row; c=col+1;//右 
    if(canplace(r,c))  { Arr[r][c]=num+1; search(r,c); }
    r=row+1;  c=col;//下
    if(canplace(r,c))  { Arr[r][c]=num+1; search(r,c); }
    r=row;    c=col-1;//左
    if(canplace(r,c))  { Arr[r][c]=num+1; search(r,c); }
}
int main()
{ 
    int i,j;
    scanf("%d %d",&Rownum,&Colnum);//输入迷宫行列数  
    for(i=0;i<Rownum;i++)
        for(j=0;j<Colnum;j++){
           scanf("%d",&Arr[i][j]);
           if(Arr[i][j]==3){
                   Beginrow=i;
                   Begincol=j;
                   Arr[i][j]=0;
           }
           if(Arr[i][j]==4){
                   Endrow=i;
                   Endcol=j;
                   Arr[i][j]=0;
           }
        }
    Arr[Beginrow][Begincol]=1;
    search(Beginrow,Begincol);
    int step_num=step_num=Arr[Endrow][Endcol]-1;
    if(state==1)
        printf("%d\n",step_num);
    else
        printf("No\n");    
    return 0;
}