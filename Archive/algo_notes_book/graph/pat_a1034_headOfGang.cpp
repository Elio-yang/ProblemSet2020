#include <string>
#include <map>
#include <iostream>

using namespace std;

constexpr int cri_num_max=2010;
constexpr unsigned int no_edge=0xffffffff;

map<int,string >id_to_name;
map<string,int> name_to_id;
map<string,int> head_to_cnt;

int G[cri_num_max][cri_num_max]={0};//time between 2 person
int w_i[cri_num_max]={0};//time of each person
int n;
int k_value;
int person_num=0;
bool vis[cri_num_max]={false};

void dfs(int v_i,int &head,int &member_cnt,int &total_recd)
{
        member_cnt++;
        vis[v_i]=true;
        if(w_i[v_i]>w_i[head]){head=v_i;}
        for (int i=0;i<person_num;i++){//for each person
                if(G[v_i][i]>0){//there is connection
                        total_recd+=G[v_i][i];//update total time
                        G[v_i][i]=G[i][v_i]=0;//delete this edge
                        if(!vis[i]){//if haven't been visited
                                dfs(i,head,member_cnt,total_recd);
                        }
                }
        }
}
void dfs_graph()
{
        for(int i=0;i<person_num;i++){
                if(!vis[i]){
                        int head=i;
                        int member_cnt=0;
                        int total_recd=0;
                        dfs(i, head, member_cnt, total_recd);
                        if(member_cnt>2&&total_recd>k_value){
                                head_to_cnt[id_to_name[head]]=member_cnt;
                        }
                }
        }
}
int get_id(string name)
{
       if(name_to_id.find(name)!=name_to_id.end()){
               return name_to_id[name];
       }else{
               name_to_id[name]=
       }
}
