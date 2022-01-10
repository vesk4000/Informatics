#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "brperm.h"

char s[(int)5e5 + 10];

int main() {
    assert(scanf("%s", s) == 1);
    init(strlen(s), s);

    int x, y;
    while (scanf("%d%d", &x, &y) == 2) {
        printf("%d\n", query(x, y));
    }

    return 0;
}
