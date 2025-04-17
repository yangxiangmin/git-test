#include <stdio.h>
#include <math.h>  // 需要包含math.h以使用sqrt()函数

// 平方函数
double square(double x) {
    return x * x;
}

// 开平方函数
double square_root(double x) {
    if (x < 0) {
        printf("错误：不能对负数开平方\n");
        return -1.0; // 返回-1表示错误
    }
    return sqrt(x); // 使用math.h中的sqrt函数
}

// 立方函数（附加功能）
double cube(double x) {
    return x * x * x;
}

// 立方根函数（附加功能）
double cube_root(double x) {
    // 使用math.h中的cbrt函数（C99标准）
    // 如果编译器不支持cbrt，可以用pow(x, 1.0/3.0)代替
    return cbrt(x);
}

int main() {
    double num;
    
    printf("请输入一个数字: ");
    scanf("%lf", &num);
    
    printf("%.2lf的平方: %.2lf\n", num, square(num));
    printf("%.2lf的立方: %.2lf\n", num, cube(num));
    
    double root = square_root(num);
    if (root >= 0) { // 检查是否有效
        printf("%.2lf的平方根: %.2lf\n", num, root);
    }
    
    printf("%.2lf的立方根: %.2lf\n", num, cube_root(num));
    
    return 0;
}