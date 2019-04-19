//
// Created by 87572 on 19/4/17.
//

#ifndef STATEONE_BASEONEPART_H
#define STATEONE_BASEONEPART_H

/**
 * "" 表示系统先在file1.c所在的当前目录找file1.h，如果找不到，再按系统指定的目录检索。
 * < > 表示系统直接按系统指定的目录检索。
 * 注意：
 *      1. #include <>常用于包含库函数的头文件；
 *      2. #include ""常用于包含自定义的头文件；
 *      3. 理论上#include可以包含任意格式的文件(.c .h等) ，但一般用于头文件的包含；
 *
 */

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

//  #define发生在预处理，typedef发生在编译阶段
/*typedef struct Person {
    int age;
    char name[20];

} MY_PERSON;*/

union Home {
    int num;
    char address[10];
};
struct MyPerson {
    int age;
    char name[10];

};

//const int g_num_1;定义的时候const必须赋值
extern const int g_num_2;//这样则不会报错,因为只是声明一个变量.

using namespace std;

void test_differ_bin();

void test_add();

void test_num_type_write();

void test_num_full();

void test_three_cal();

void test_num_change();

void test_time_random();

void show_macroi(void);

void test_puts();

void test_gets();

void base_one_part_union();

void bitCalculate();

void base_one_memory_set();

void base_one_memory_copy();

void base_one_memory_compare();

void base_one_memory_enum();


#endif //STATEONE_BASEONEPART_H
