#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

struct sparse_matrix{
        int row;
        int col;
        int val;
};


int main()
{
        int m;
        int n;
        scanf("%d %d",&m,&n);
        struct sparse_matrix M_a[m+10];
        int max_row_a=0;
        int max_col_a=0;
        struct sparse_matrix M_b[n+10];
        int max_row_b=0;
        int max_col_b=0;
        for(int i=1;i<=m;i++){
                scanf("%d %d %d",&M_a[i].row,&M_a[i].col,&M_a[i].val);
                (M_a[i].row>max_row_a)?(max_row_a=M_a[i].row):(max_row_a=max_row_a);
                (M_a[i].col>max_col_a)?(max_col_a=M_a[i].col):(max_col_a=max_col_a);
        }
        for(int i=1;i<=n;i++){
                scanf("%d %d %d",&M_b[i].row,&M_b[i].col,&M_b[i].val);
                (M_b[i].row>max_row_b)?(max_row_b=M_b[i].row):(max_row_b=max_row_b);
                (M_b[i].col>max_col_b)?(max_col_b=M_b[i].col):(max_col_b=max_col_b);
        }

        int max_col=std::max(max_col_a,max_col_b);
        int max_row=std::max(max_row_a,max_row_b);
        
        struct sparse_matrix M[2000];
        int val_a,val_b;
        int cnt=1;
        int i,j;
        for( i=1;i<=m;i++){
                for( j=1;j<=n;j++){
                        if(M_a[i].row==M_b[j].row&&M_a[i].col==M_b[j].col){
                                int v=M_a[i].val-M_b[j].val;
                                if(v==0){
                                        continue;
                                }
                                M[cnt].val=v;
                                M[cnt].row=M_b[j].row;
                                M[cnt].col=M_b[j].col;
                                cnt++;
                        }
                }
        }
        for( i=1;i<=m;i++){
                for( j=1;j<=n;j++){
                        if(M_a[i].row==M_b[j].row&&M_a[i].col==M_b[j].col){
                               break;
                        }
                }
                if(j-1==n){
                        M[cnt].row=M_a[i].row;
                        M[cnt].col=M_a[i].col;
                        M[cnt].val=M_a[i].val;
                        cnt++;
                }
        }
        for(i=1;i<=n;i++){
                for(j=1;j<=m;j++){
                        if(M_b[i].row==M_a[j].row&&M_b[i].col==M_a[j].col){
                                break;
                        }
                }
                if(j-1==m){
                        M[cnt].row=M_b[i].row;
                        M[cnt].col=M_b[i].col;
                        M[cnt].val=-M_b[i].val;
                        cnt++;
                }
        }
        cnt-=1;
        for(int i=1;i<=cnt;i++){
                printf("%d %d %d\n",M[i].row,M[i].col,M[i].val);
        }

        system("pause");
        return 0;
}
