#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
        int m,n;
        while(~scanf("%d %d",&m,&n)){
                if(m==0&&n==0){
                        continue;
                }
                set<int> A;
                set<int> B;
                set<int> C;
                for(int i=0;i<m;i++){
                        int ele;
                        scanf("%d",&ele);
                        A.insert(ele);
                }
                for(int i=0;i<n;i++){
                        int ele;
                        scanf("%d",&ele);
                       A.erase(ele);
                }
                if(A.empty()){
                        printf("NULL\n");
                        continue;
                }
                for(auto i=A.begin();i!=A.end();++i){
                        printf("%d ",*i);
                }
                printf("\n");
        }
        system("pause");
        return 0;
}