#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <deque>
#include <set>
#include <map>

typedef long long int64;

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

char buf[4010];

bool cmp(char *a, char *b) {
    while(1) {
        if(*a < *b)return true;
        if(*a > *b)return false;
        ++a;
        ++b;
    }
}

bool equal(char *a, char *b) {
    for(;*a!='\0' && *b!='\0';) {
        if(*a != *b)return false;
    }
    if(*a != *b)return false;
    return true;
}

void solve(std::vector<char*>::iterator beg, std::vector<char*>::iterator end) {
    if(beg == end)return;
    char *mn = *beg;
    std::vector<char*>::iterator mnit = beg;
    for(auto it=beg+1;it!=end;++it) {
        if(strcmp(*it, mn) < 0){
            mn = *it;
            mnit = it;
        } else if(strcmp(*it, mn) == 0) {
            mnit = it;
        }
        
    }
    printf("%s", mn);
    solve(beg, mnit);
    for(auto it=mnit+1;it!=end;++it)
        printf("%s", *it);
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<char*> str(n);
        for(int i=0;i<n;++i) {
            scanf("%s", buf);
            int len = strlen(buf);
            str[i] = (char*)malloc(sizeof(char)*(len+1));
            strcpy(str[i], buf);
        }

        std::deque<char> q;

        for(int t=0;t<n;++t) {
            // printf("cur %s\n", str[t]);
            int len = strlen(str[t]);
            std::deque<char> front = q, back = q;
            for(int i=0;i<len;++i)
                back.push_back(str[t][i]);
            for(int i=len-1;i>=0;--i)
                front.push_front(str[t][i]);
            
            bool flag = false;
            for(int i=0;i<(int)front.size();++i) {
                if(front[i] < back[i]) {
                    q = front;
                    flag = true;
                    break;
                } else if(front[i] > back[i]) {
                    q = back;
                    flag = true;
                    break;
                }
            }
            if(!flag)q = front;

            // for(auto c:q)
            //     putchar(c);
            // printf("\n");
            // for(auto c:front)
            //     putchar(c);
            // printf("\n");
            // for(auto c:back)
            //     putchar(c);
            // printf("\n");
        }

        for(auto c:q)
            putchar(c);
        printf("\n");

        for(auto p:str)
            free(p);
    }

    return 0;
}