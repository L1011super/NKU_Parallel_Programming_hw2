#include <iostream>
#include <chrono>

const int n = 131072;
int arr[n];

// 循环展开函数
long long unrolled_loop(const int arr[], int step) {
    long long sum_result = 0;
    int i = 0;
    while (i <= n - step) {
        long long temp = 0;
        for (int j = 0; j < step; ++j) {
            temp += arr[i + j];
        }
        sum_result += temp;
        i += step;
    }
    // 处理剩余元素
    for (; i < n; ++i) {
        sum_result += arr[i];
    }
    return sum_result;
}

int main() {
    // 生成数组
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }

    // 定义步长
    int step_sizes[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};

    for (int step : step_sizes) {
        auto start = std::chrono::high_resolution_clock::now();
        // 执行 1000 次
        for (int i = 0; i < 1000; ++i) {
            unrolled_loop(arr, step);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout  << elapsed.count() << std::endl;
    }

    return 0;
}
