#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[200000];

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    qsort(arr, n, sizeof(long long), cmp);

    int count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i-1]) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}