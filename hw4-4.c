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

    // 寻找最佳情侣组合
    for (int i = 0; i < n; i++) {
        int max = 0;
        int boy, girl;

        for (int j = 0; j < n; j++) {
            if (feelings[i][j] > max) {
                max = feelings[i][j];
                boy = i + 1;
                girl = j + 1;
            }
        }

        printf("boy %d pair with girl %d\n", boy, girl);
    }

    return 0;
}
