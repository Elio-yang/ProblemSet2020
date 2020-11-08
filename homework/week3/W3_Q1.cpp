//
// Created by ELIO on 2020/11/8.
//
#include <iostream>
#include <cstdlib>

using namespace std;

#define pNode(T) BiNode<T>*
#define stature(p) ((p)?(p)->height:-1)

#define is_root(x) ((!(x).parent))
#define is_l_child(x) (!is_root(x) && (&(x)==(x).parent->lc))


template<typename T>
class BiNode{
        T val;
        int height;
        pNode(T) lc;
        pNode(T) rc;
        pNode(T) parent;

        BiNode(): parent(NULL), lc(NULL), rc(NULL), height(0){}
        explicit BiNode(T e,pNode(T) p,pNode(T) lc=NULL,pNode(T) rc=NULL,int h=0):
                val(e), height(h), lc(NULL), rc(NULL), parent(p){ }

        pNode(T) insertLC(T const &e);
        pNode(T) insertRC(T const &e);
        template<typename VST>void travPre(VST&);
        bool operator== (BiNode const& bn) {return this->val==bn.val;}
};

template<typename T>
template<typename VST>
void BiNode<T>::travPre(VST &visit)
{
        trav_pre_i(this,visit);
}

template<typename T>
pNode(T) BiNode<T>::insertLC(const T &e)
{
        return lc=new BiNode<T>(e, this);
}

template<typename T>
pNode(T) BiNode<T>::insertRC(const T &e)
{
        return rc=new BiNode<T>(e,this);
}


template<typename T>
class BiTree{
protected:
        int _size;
        pNode(T) _root;
        virtual int updateH(pNode(T) x);
        void update_above(pNode(T) x);

public:
        BiTree():_size(0),_root(NULL){}
        ~BiTree(){if(_size>0) remove(_root);}
        int size() const {return _size;};

        pNode(T) insert_root(pNode(T)x,T const &e);
        pNode(T) insert_lc(pNode(T)x,T const &e);
        pNode(T) insert_rc(pNode(T)x,T const &e);

        template<typename VST>
        void trav_pre(VST & visit){
                if(_root){_root->travPre(visit);}
        }


        int remove(pNode(T) x);
};

template<typename T>
int BiTree<T>::updateH(BiNode<T> *x)
{
        return x->height = 1 + max(stature(x->lc), stature(x->rc));
}
template <typename T>
void BiTree<T>::update_above(BiNode<T> *x)
{
        while (x){
                updateH(x);
                x=x->parent;
        }
}
template<typename T,typename VST>
void trav_pre_i(pNode(T) x,VST& visit)
{
        if(!x) return;
        visit(x->val);
        trav_pre_i(x->lc,visit);
        trav_pre_i(x->rc,visit);
}

template<typename T>
pNode(T) BiTree<T>::insert_root(BiNode<T> *x, const T &e)
{
        _size=1;
        return _root=new BiNode<T>(e);
}

template<typename T>
pNode(T) BiTree<T>::insert_lc(BiNode<T>* x, const T &e)
{
        ++_size;
        x->insertLC(e);
        update_above(x);
        return x->lc;
}

template<typename T>
pNode(T) BiTree<T>::insert_rc(BiNode<T> *x, const T &e)
{
        ++_size;
        x->insertRC(e);
        update_above(x);
        return x->rc;
}

template<typename T>
int BiTree<T>::remove(BiNode<T> *x)
{

}
int main(int argc , char *argv[])
{


        return 0;
}

