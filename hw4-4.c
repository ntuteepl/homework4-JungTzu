#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int feelings[10][10];

    // 读取好感度矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &feelings[i][j]);
        }
    }

    int boys_matched[10] = {0};
    int girls_matched[10] = {0};

    // 寻找最佳情侣组合
    for (int i = 0; i < n; i++) {
        int max = -1;
        int boy, girl;

        for (int j = 0; j < n; j++) {
            if (!girls_matched[j] && feelings[i][j] > max) {
                max = feelings[i][j];
                boy = i + 1;
                girl = j + 1;
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
