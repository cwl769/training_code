#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cstdint>
#include <algorithm>
#include <deque>
#include <queue>


int main() {
    int T;scanf("%d", &T);
    for(;T;--T) {
        std::deque<char> deque;
        std::queue<char> queue;
        int na, nb;
        scanf("%d", &na);
        for(int i=1;i<=na;++i) {
            char c = getchar();
            while(c<'a'||c>'z')c = getchar();
            deque.push_back(c);
        }
        scanf("%d", &nb);
        for(int i=1;i<=nb;++i) {
            char c = getchar();
            while(c<'a'||c>'z')c = getchar();
            queue.push(c);
        }
        for(int i=1;i<=nb;++i) {
            char c = getchar();
            while(c!='D'&&c!='V')c = getchar();
            if(c == 'D') {
                deque.push_back(queue.front());
            } else {
                deque.push_front(queue.front());
            }
            queue.pop();
        }
        for(auto it=deque.begin();it!=deque.end();++it) {
            putchar(*it);
        }
        putchar('\n');
    }


    return 0;
}