#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int feelings[10][10];

    // 讀取好感度矩陣
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &feelings[i][j]);
        }
    }

    int boys_matched[10] = {0};
    int girls_matched[10] = {0};

    // 尋找最佳情侶組合
    for (int k = 0; k < n; k++) {
        int max = -1;
        int boy, girl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!boys_matched[i] && !girls_matched[j] && feelings[i][j] > max) {
                    max = feelings[i][j];
                    boy = i + 1;
                    girl = j + 1;
                }
            }
        }

        if (max != -1) {
            boys_matched[boy - 1] = 1;
            girls_matched[girl - 1] = 1;
            printf("boy %d pair with girl %d\n", boy, girl);
        }
    }

    return 0;
}
