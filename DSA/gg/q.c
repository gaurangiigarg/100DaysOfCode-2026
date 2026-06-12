#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minDistance(char* word1, char* word2) {
    int n = strlen(word1);
    int m = strlen(word2);

    int *prev = (int *)malloc((m + 1) * sizeof(int));
    int *curr = (int *)malloc((m + 1) * sizeof(int));

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++) {
        curr[0] = i;

        for (int j = 1; j <= m; j++) {

            if (word1[i - 1] == word2[j - 1]) {
                curr[j] = prev[j - 1];
            } else {
                curr[j] = 1 + min(
                    prev[j],
                    min(curr[j - 1], prev[j - 1])
                );
            }
        }

        int *temp = prev;
        prev = curr;
        curr = temp;
    }

    int ans = prev[m];

    free(prev);
    free(curr);

    return ans;
}
