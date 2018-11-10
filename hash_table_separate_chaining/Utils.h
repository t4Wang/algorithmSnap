/* 一些系统工具 */
#ifndef UTILS_H
#define UTILS_H

// 声明定义NULL 避免重名改叫NUL
extern const void *NUL;

// 错误函数
void Error(char *);
void FatalError(char *);

#endif // UTILS_H