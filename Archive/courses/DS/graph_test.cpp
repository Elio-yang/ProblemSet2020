
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

static int id = 0;

class vertex {
public:
        int weight_i;
        int data;
        int in_deg;
        int out_deg;
        bool status;

public:
        explicit vertex(int const &val,int w_i=0,int in_d=0,int out_d=0,bool st=false):
                 data(val), weight_i(w_i), in_deg(in_d), out_deg(out_d), status(st) { }
        bool operator==(vertex const& v) const {
                return this->data == v.data;
        }
};


class edge {
public:
        vertex v;
        vertex w;
        int w;
        bool type;
        edge(vertex &v_1,vertex &v_2,int const& w_e,bool st=false): v(v_1), w(v_2), w(w_e), type(st){ }

        int get_weight() const {
                return w;
        }
        vertex &get_either() {
                return v;
        }
        vertex &get_other(vertex v_i) {
                if (v_i == v) {
                        return w;
                }
                else if (v_i == w) {
                        return v;
                }
                else {
                        printf("vertex error!");
                }
        }
        void to_string() {
                printf("%d-%d:%d\n", v.data, w.data, w);
        }
};

template<typename Tv>
class Graph {
private:
        int v_num;
        int e_num;
public:
        vector<vector<edge>> V;//邻接表
        explicit Graph(istream& in) {
                int cnt_v,cnt_e;
                cin >> cnt_v>>cnt_e;
                v_num = cnt_v;
                e_num = cnt_e;
                for (int i = 0; i < e_num;i++ ) {
                        int data1,data2;
                        cin>>data1>>data2;
                        vertex v_i(data1);
                        vertex w_i(data2);
                        int weigh;
                        cin>>weigh;
                        v_i.weight_i+=weigh;
                        w_i.weight_i+=weigh;
                        edge e_i(v_i,w_i,weigh);
                        add_edge(e_i);
                }
        }
        void add_edge(edge e_i){
                vertex v_1=e_i.get_either();
                vertex v_2=e_i.get_other(v_1);
                V[v_1.data].push_back(e_i);
                V[v_2.data].push_back(e_i);
                e_num++;
        }
        void show_graph(){
                for(auto v_i:V){
                        for(auto j:v_i){
                                j.to_string();
                        }
                }
        }

};
