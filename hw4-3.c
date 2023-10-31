#include <stdio.h>

int main() {
    int schedule[50][2]; // 假设最多50个订单，每行存储开始和结束时间

    int n = 0; // n个订单
    int driverCount = 0; // 司机计数器
    int drivers[50][50]; // 司机时间表，每行存储司机的开始和结束时间

    // 读取输入
    while (scanf("%d %d", &schedule[n][0], &schedule[n][1]) != EOF) {
        n++;
    }

    // 遍历订单，查看是否有重叠的时间
    for (int i = 0; i < n; i++) {
        int found = 0; // 当前订单是否可以由现有司机处理

        for (int j = 0; j < driverCount; j++) {
            // 检查是否有空闲司机
            if (schedule[i][0] >= drivers[j][1]) {
                drivers[j][1] = schedule[i][1]; // 更新司机的结束时间
                found = 1;
                break;
            }
        }

        // 如果没有现有司机可以处理当前订单，新增一个司机
        if (!found) {
            drivers[driverCount][0] = schedule[i][0];
            drivers[driverCount][1] = schedule[i][1];
            driverCount++;
        }
    }

    printf("%d\n", driverCount);

    // 显示每个司机的时间表
    for (int i = 0; i < driverCount; i++) {
        printf("Driver %d's schedule is %d %d\n", i + 1, drivers[i][0], drivers[i][1]);
    }

    return 0;
}
