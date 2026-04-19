#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node * fa;
    int val;
} Node;

Node * alloced[1000010];
int tot = 0;

Node * newNode() {
    Node * ptr = (Node*)malloc(sizeof(Node));
    ptr->fa = NULL;
    ptr->val = -1;
    ++tot;
    alloced[tot] = ptr;
    return ptr;
}

char op[20];

Node * save[1000010];


int main() {
    int q;scanf("%d", &q);
    Node init = {
        .fa = NULL,
        .val = 0
    };
    Node * cur = &init;
    while(q--) {
        int x;
        scanf("%s", op);
        if(op[0] == 'F') {
            scanf("%d", &x);
            Node * new = newNode();
            new->fa = cur;
            new->val = x;
            cur = new;
        } else if(op[0] == 'B') {
            if(cur->val == 0) {
                
            } else {
                cur = cur->fa;
            }
        } else if(op[0] == 'S') {
            scanf("%d", &x);
            save[x] = cur;
        } else if(op[0] == 'L') {
            scanf("%d", &x);
            if(save[x] == NULL)
                cur = &init;
            else
                cur = save[x];
        }
        printf("%d\n", cur->val);
    }

    for(int i=1;i<=tot;++i)
        free(alloced[i]);

    return 0;
}