#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <algorithm>
#include <vector>

typedef long long int64;
typedef unsigned long long uint64;

struct Query {
    int x, id, xx;
};
bool query_cmp(Query a, Query b) {
    return a.x < b.x;
}
std::vector<Query> query;
std::vector<int> disc;

struct Node {
    Node *fa, *son[2];
    int64 val, var;
    int64 tag;
    std::vector<int> *id;
};
Node * root;
Node*maketree(Node*fa, int l, int r) {
    if(l==r) {
        Node * node = new Node;
        node->fa = fa;
        node->val = node->var = disc[l];
        node->tag = 0;
        node->id = new std::vector<int>;
        auto begin = std::lower_bound(query.begin(), query.end(), query_cmp);
        auto end = std::upper_bound(query.begin(), query.end(), query_cmp);
        for(auto it=begin;it!=end;++it) {
            node->id->push_back(it->id);
        }
        return node;
    }
    int mid = ((l+r)>>1);
    Node * node = new Node;
    node->fa = fa;
    node->tag = 0;
    node->son[0] = maketree(node, l, mid);
    node->son[1] = maketree(node, mid+1, r);
    node->val = node->son[0]->val;
    node->var = node->son[1]->var;
}

void delete0(Node * p)

struct present {
    int p, a, b;
};

int main() {
    int n;scanf("%d", &n);
    std::vector<present> pres(n);
    for(int i=0;i<n;++i)
        scanf("%d%d%d", &pres[i].p, &pres[i].a, &pres[i].b);
    int q;scanf("%d", &q);
    query.resize(q);
    for(int i=0;i<q;++i) {
        scanf("%d", &query[i].x);
        query[i].id = i;
    }
    // std::vector<int> discrete;
    // for(int i=0;i<q;++i)
    //     discrete.push_back(query[i].x);
    std::sort(query.begin(), query.end(), query_cmp);
    // std::sort(discrete.begin(), discrete.end());
    // std::unique(discrete.begin(), discrete.end());
    // for(auto it=discrete.begin();it!=discrete.end();++it) {
        for(int cnt=1,itq=0;itq<query.size();++itq) {
            if(itq==0||query[itq].x==query[itq-1].x){

            } else {
                ++cnt;
            }
            query[itq].xx = cnt;
            disc[cnt] = query[itq].x;
        }
    // }
    

    return 0;
}