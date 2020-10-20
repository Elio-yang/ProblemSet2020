#include <bits/stdc++.h>
using namespace std;
int main()
{
        vector<string> ans;
        string s;
        while(cin>>s){
                ans.push_back(s);
        }
        int len=ans.size();
        for(int i=len-1;i>=0;i--){
                cout<<ans[i];
                if(i>0){
                        cout<<" ";
                }
        }
/*===============================================*/
        int cnt=0;
        char str[90][90];
        while(scanf("%s",str[cnt])!=EOF){
                cnt++;
        }
        for(int i=cnt-1;i>=0;i--){
                printf("%s",str[i]);
                if(i>0){
                        printf(" ");
                }
        }
        return 0;
}