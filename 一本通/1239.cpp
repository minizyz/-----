#include <bits/stdc++.h>
#define N 100001 // 定义数组最大大小为100001
using namespace std;
int a[N]; // 创建全局数组

// 快速选择算法，用于找到数组中第k大的元素范围
void find(int st, int ed, int k) {
    if (ed - st + 1 == k) return; // 如果区间长度等于k，说明已找到，无需进一步处理

    int i = st, j = ed, key = a[st]; // 以区间的第一个元素为基准值
    while (i < j) {
        while (i < j && a[j] >= key) j--; // 从右向左找第一个小于基准值的元素
        a[i] = a[j]; // 将找到的小值移动到左边
        while (i < j && a[i] <= key) i++; // 从左向右找第一个大于基准值的元素
        a[j] = a[i]; // 将找到的大值移动到右边
    }
    a[j] = key; // 将基准值放到正确的位置

    if (ed - i + 1 == k)
        return; // 如果右侧元素正好是k个，说明这些就是所需的元素
    else if (ed - i + 1 > k)
        find(i + 1, ed, k); // 如果右侧元素多于k个，继续在右侧找
    else
        find(st, i - 1, k - (ed - i + 1)); // 如果右侧元素不足k个，还需要从左侧找更多
}

int main() {
    int n, k;
    cin >> n; // 输入数组的大小
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // 读入数组元素
    }
    cin >> k; // 输入k值
    find(0, n-1, k); // 调用快速选择函数
    sort(a + n - k, a + n); // 对找到的k个元素进行排序
    for (int i = n - 1; i >= n - k; i--) {
        printf("%d\n", a[i]); // 输出结果，从大到小
    }
    return 0;
}