#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

#define debug(...) fprintf(stderr, __VA_ARGS__)

template<typename T>
void readInt(T& x) {
    static bool f;
    x = 0;f = false;
    char c = getchar();
    for(;c<'0' || c>'9';c=getchar())if(c=='-')f=!f;
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * 10 + c - '0';
    }
    if(f)x = -x;
}
template<typename T, typename ...Args>
void readInt(T& x, Args&... args) {
    readInt(x);
    readInt(args...);
}

struct Node {
    bool type;//0<-->operator, 1<-->value;
    union Data {
        double val;
        char op;
    } data;
    Node *son[2];
};

void print(Node *ptr) {
    if(ptr == NULL)return;
    if(ptr->son[0] || ptr->son[1])printf("(");
    print(ptr->son[0]);
    if(ptr->type) {
        printf("%.2lf", ptr->data.val);
    } else {
        printf("%c", ptr->data.op);
    }
    print(ptr->son[1]);
    if(ptr->son[0] || ptr->son[1])printf(")");
}

int get_level(char op) {
    if(op == '*' || op == '/')
        return 2;
    if(op == '+' || op == '-')
        return 1;
    return -1;
}

bool is_space(char c) {
    return c == ' ' || c == '\n' || c == '\r';
}

bool is_digit(char c) {
    return '0' <= c && c <= '9';
}

double cal(char op, double a, double b) {
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    
    default:
        break;
    }
    return 0.0;
}

void erase_space(char *str) {
    char *tmp = (char*)malloc(strlen(str)+1);
    strcpy(tmp, str);
    char *dest = str;
    for(char *p=tmp;*p!='\0';++p) {
        if(!is_space(*p)) {
            *dest = *p;
            ++dest;
        }
    }
    *dest = '\0';
    free(tmp);
}

int get_anc(int x, std::vector<int> &fa) {
    if(fa[x] == x)return x;
    return fa[x] = get_anc(fa[x], fa);
}

void update(int size, std::vector<Node*>&seq, std::vector<int>&fa, int level) {
    for(int i=0;i<size;++i) {
        if(i&1) {
            if(get_level(seq[i]->data.op) == level) {
                int anc0 = get_anc(i-1, fa);
                int anc1 = get_anc(i+1, fa);
                seq[i]->son[0] = seq[anc0];
                seq[i]->son[1] = seq[anc1];
                fa[anc0] = i;
                fa[anc1] = i;
            }
        }
    }
}

double cal_free(Node *ptr) {
    if(ptr->type) {
        double ans = ptr->data.val;
        free(ptr);
        return ans;
    } else {
        double ans0 = cal_free(ptr->son[0]);
        double ans1 = cal_free(ptr->son[1]);
        double ans = cal(ptr->data.op, ans0, ans1);
        free(ptr);
        return ans;
    }
}

Node *parser(char *begin, char *end) {
    bool all_number = true;
    int val = 0;
    for(char *p=begin;p!=end;++p) {
        if(is_digit(*p))
            val = val * 10 + (*p - '0');
        else {
            all_number = false;
            break;
        }
    }
    if(all_number) {
        Node *cur = new Node;
        cur->type = 1;
        cur->data.val = val;
        cur->son[0] = cur->son[1] = NULL;
        return cur;
    }
    std::vector<Node*> seq;
    std::stack<char*> stack;
    val = 0;
    for(char *p=begin;p!=end;++p) {
        if(!is_digit(*p))
            val = 0;
        
        if(*p == '(') {
            stack.push(p);
        } else if(*p == ')') {
            if(stack.size() == 1u) {
                seq.push_back(parser(stack.top()+1, p));
            }
            stack.pop();
        } else {
            if(stack.size())continue;
            if(*p == '+' || *p == '-') {
                Node *cur = new Node;
                cur->type = 0;
                cur->data.op = *p;
                cur->son[0] = cur->son[1] = NULL;
                seq.push_back(cur);
            } else if(*p == '*' || *p == '/') {
                Node *cur = new Node;
                cur->type = 0;
                cur->data.op = *p;
                cur->son[0] = cur->son[1] = NULL;
                seq.push_back(cur);
            } else {
                val = val * 10 + (*p - '0');
                if(p+1==end || !is_digit(*(p+1))) {
                    Node *cur = new Node;
                    cur->type = 1;
                    cur->data.val = val;
                    cur->son[0] = cur->son[1] = NULL;
                    seq.push_back(cur);
                }
            }
        }
    }
    int size = seq.size();
    std::vector<int> fa(size);
    for(int i=0;i<size;++i) {
        fa[i] = i;
    }
    update(size, seq, fa, 2);
    update(size, seq, fa, 1);
    Node *ans = seq[get_anc(0, fa)];
    return ans;
}

char str[100010];

void solve() {
    fgets(str, 100010, stdin);
    erase_space(str);
    char *end = str;
    while(*end!='=')++end;
    Node *tree = parser(str, end);
    printf("%.2lf\n", cal_free(tree));
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}