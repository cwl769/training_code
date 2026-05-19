#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {5, 4, 2, 1, 3, 3, 3};
    for(auto x:vec)
        printf("%d ", x);
    printf("\n");

    std::nth_element(vec.begin(), vec.begin()+3, vec.end());

    for(auto x:vec)
        printf("%d ", x);
    printf("\n");

    return 0;
}