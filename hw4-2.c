#include <stdio.h>

#define NUM_ACCOUNTS 6

int main() {
    int accounts[NUM_ACCOUNTS][3] = {
        {123, 456, 9000},
        {456, 789, 5000},
        {789, 888, 6000},
        {336, 558, 10000},
        {775, 666, 12000},
        {566, 221, 7000}
    };

    int testCases;
    printf("输入测试案例数量: ");
    scanf("%d", &testCases);

    while (testCases--) {
        int acc, pass;
        printf("输入帐号和密码: ");
        scanf("%d %d", &acc, &pass);

        int found = 0;
        for (int i = 0; i < NUM_ACCOUNTS; i++) {
            if (accounts[i][0] == acc && accounts[i][1] == pass) {
                printf("帐号 %d 的余额为: %d\n", acc, accounts[i][2]);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("error\n");
        }
    }

    return 0;
}
