#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <queue>
#include <map>

using namespace std;
queue<int> Q;
map<int,int> Map_V_p;

int main()
{
        /*T组数据*/
        int T;
        scanf("%d",&T);
        for(int i=0;i<T;i++){
                int n;
                scanf("%d",&n);
                int flag=1;
                int max_v=INT_MIN+1;
                int min_v=INT_MAX-1;
                for(int i=0;i<n;i++){
                        char ops[8];
                        scanf("%s",ops);
                        switch(ops[0]){ 
                                case 'E':{
                                        /*入队一个元素*/
                                        int ele;
                                        scanf("%d",&ele);
                                        Q.push(ele);
                                        if(!Map_V_p.count(ele)){
                                                Map_V_p[ele]=0;
                                        }
                                        Map_V_p[ele]++;
                                        if(ele>max_v){max_v=ele;};
                                        if(ele<min_v){min_v=ele;};
                                        break;
                                }
                                case 'D':{
                                        /*出队一个元素*/
                                        int ele=Q.front();
                                        Q.pop();

                                        int tmp=flag*ele;
                                        if(tmp==max_v||tmp==min_v){
                                                Map_V_p[tmp]--;
                                                if(Map_V_p[tmp]==0){
                                                        Map_V_p.erase(tmp);
                                                }
                                        }
                                        else if(Map_V_p.count(ele)){
                                                Map_V_p[ele]--;
                                                if (Map_V_p[ele] == 0) {
                                                        Map_V_p.erase(ele);
                                                }
                                        }
                                        break;
                                }
                                case 'R':{
                                        /*bug fix??*/
                                        /*still not fix : function on reverse 2020/10/27 */
                                        /*取反每一个元素*/

                                        flag=-1;
                                        int v1=Map_V_p[max_v];
                                        int v2=Map_V_p[min_v];
                                        if(Map_V_p.count(-max_v)){
                                                int v3=Map_V_p[-max_v];
                                                Map_V_p[max_v]=v3;
                                                Map_V_p[-max_v]=v1;

                                        }else{
                                                Map_V_p.erase(max_v);
                                                Map_V_p[-max_v]=v1;
                                        }

                                        if(Map_V_p.count(-min_v)){
                                                int v4=Map_V_p[-min_v];
                                                Map_V_p[min_v]=v4;
                                                Map_V_p[-min_v]=v2;
                                        }else{
                                                Map_V_p.erase(min_v);
                                                Map_V_p[-min_v]=v2;
                                        }
                                        int tmp=max_v;
                                        max_v=-min_v;
                                        min_v=-tmp;

                                        break;
                                }
                                case 'M':{
                                        if(!Map_V_p.count(max_v)||!Map_V_p.count(min_v)){
                                                max_v=INT_MIN;
                                                min_v=INT_MAX;
                                                for(auto iter=Map_V_p.begin();iter!=Map_V_p.end();++iter){
                                                        if(max_v<iter->first){
                                                                max_v=iter->first;
                                                        }
                                                        if(min_v>iter->first){
                                                                min_v=iter->first;
                                                        }
                                                }
                                        }

                                        printf("%d\n",max_v);

                                        break;
                                }
                        }
                }
                printf("\n");
        }
        system("pause");
        return 0;
}



