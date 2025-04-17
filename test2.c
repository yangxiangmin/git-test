#include <stdio.h>
#include <math.h>  // 需要包含math.h以使用对数函数
#include <errno.h> // 用于错误处理

// 自然对数（以e为底）
double ln(double x) {
    if (x <= 0) {
        errno = EDOM; // 定义域错误
        printf("错误：自然对数参数必须为正数\n");
        return -1.0; // 返回-1表示错误
    }
    return log(x); // 使用math.h中的log函数
}

// 常用对数（以10为底）
double log10_custom(double x) {
    if (x <= 0) {
        errno = EDOM; // 定义域错误
        printf("错误：对数参数必须为正数\n");
        return -1.0; // 返回-1表示错误
    }
    return log10(x); // 使用math.h中的log10函数
}

// 任意底数对数
double log_base(double x, double base) {
    if (x <= 0 || base <= 0 || base == 1) {
        errno = EDOM; // 定义域错误
        printf("错误：参数必须为正数且底数不能为1\n");
        return -1.0; // 返回-1表示错误
    }
    return log(x) / log(base); // 换底公式
}

// add modify yxm
// end of modify

// 二进制对数（以2为底）
double log2_custom(double x) {
    if (x <= 0) {
        errno = EDOM; // 定义域错误
        printf("错误：对数参数必须为正数\n");
        return -1.0; // 返回-1表示错误
    }
    return log2(x); // 使用math.h中的log2函数(C99标准)
}

int main() {
    double num, base;
    
    printf("请输入一个正数: ");
    scanf("%lf", &num);
    
    printf("请输入对数底数: ");
    scanf("%lf", &base);
    
    double result;
    
    // 自然对数
    result = ln(num);
    if (result >= 0) {
        printf("ln(%.2lf) = %.6lf\n", num, result);
    }
    
    // 常用对数
    result = log10_custom(num);
    if (result >= 0) {
        printf("log10(%.2lf) = %.6lf\n", num, result);
    }
    
    // 二进制对数
    result = log2_custom(num);
    if (result >= 0) {
        printf("log2(%.2lf) = %.6lf\n", num, result);
    }
    
    // 任意底数对数
    result = log_base(num, base);
    if (result >= 0) {
        printf("log%.2lf(%.2lf) = %.6lf\n", base, num, result);
    }
    
    return 0;
}