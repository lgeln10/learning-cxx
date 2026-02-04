#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？
// 1. 函数外的 static：限制该函数仅在本文件（编译单元）内可见，不被外界乱用。
// 2. 函数内的 static：静态局部变量，仅在第一次调用时初始化，且在程序运行期间一直存活。
static int func(int param) {
    static int static_ = param;
    // std::cout << "static_ = " << static_ << std::endl;
    return static_++;
}

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    // 第一次调用：static_ 初始化为 5，返回 5 后自增为 6
    ASSERT(func(5) == 5, "static variable value incorrect");
    // 第二次调用：static_ 已经是 6，忽略 param=4 的初始化，返回 6 后自增为 7
    ASSERT(func(4) == 6, "static variable value incorrect");
    // 第三次调用：返回 7 后自增为 8
    ASSERT(func(3) == 7, "static variable value incorrect");
    // 第四次调用：返回 8 后自增为 9
    ASSERT(func(2) == 8, "static variable value incorrect");
    // 第五次调用：返回 9 后自增为 10
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}