#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
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
                vector<int> C;
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

                for(auto i=A.begin();i!=A.end();++i){
                        set<int>::size_type size=B.size();
                        B.insert(*i);
                        if(size!=B.size()){
                                C.push_back(*i);
                        }
                }
                if(C.size()==0){
                        printf("NULL\n");
                        continue;
                }
                for(auto i:C){
                        printf("%d ",i);
                }
                printf("\n");
        }
        system("pause");
        return 0;
}