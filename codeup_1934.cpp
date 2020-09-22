#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        int x;
        int index=-1;
        cin>>n;
        int key[n];
        for(int i=0;i<n;i++){
                cin>>key[i];
        }
        cin>>x;
        for(int i=0;i<n;i++){
                if(x==key[i]){
                        index=i;
                        break;
                }
        }
        cout<<index<<endl;
        return 0;
}