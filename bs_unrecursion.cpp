#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>

using namespace std;
stack<int> i_left;
stack<int> i_right;

int main()
{
        int N = 6;
        int arr[N] = {3, 9, 21, 15, 18, 19};

        /*存最大值与最小值*/
        int max_v = arr[0];
        int min_v = arr[0];

        /*记录数组元素指标*/
        int t_l, t_r;
        int index_mid;

        /*初始化*/
        i_left.push(0);
        i_right.push(N - 1);

        while (!i_left.empty())
        {       /*循环结束的条件是：任意栈为空*/
                t_l = i_left.top();
                t_r = i_right.top();
                if (t_l != t_r && t_r - t_l != 1)
                {
                        index_mid = (t_l + t_r) / 2;
                        /*出栈*/
                        i_left.pop();
                        i_right.pop();
                        /*入栈(t_l,mid)*/
                        i_left.push(t_l);
                        i_right.push(index_mid);
                        /*入栈(mid+1,t_r)*/
                        i_left.push(index_mid + 1);
                        i_right.push(t_r);
                }
                else if (t_r - t_l == 1)
                {
                        /*相邻元素*/
                        i_left.pop();
                        i_right.pop();
                        max_v = max(max(max_v, arr[t_l]), arr[t_r]);
                        min_v = min(min(min_v, arr[t_l]), arr[t_r]);
                }
                else if (t_l == t_r)
                {
                        /*唯一元素*/
                        i_left.pop();
                        i_right.pop();
                        max_v = max(max_v, arr[t_l]);
                        min_v = min(min_v, arr[t_l]);
                }
        }

        cout<<"max : "<<max_v<<endl;
        cout<<"min : "<<min_v<<endl;

        system("pause");
        return 0;
}