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
                        B.insert(ele);
                }
                set_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.begin()));
                if(C.size()==0){
                        printf("NULL\n");
                        continue;

                }
                set<int>::iterator it;
                for(it=C.begin();it!=C.end();++it){
                        printf("%d ",*it);
                }
                printf("\n");
        }
        system("pause");
        return 0;
}