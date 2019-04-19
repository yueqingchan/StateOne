//
// Created by 87572 on 19/4/9.
//

#ifndef STATEONE_PART1_H
#define STATEONE_PART1_H
using namespace std;

#include <string.h>

extern int a;//只是声明
//int g_a;//声明+定义
const  int g_b=20;//常量区 不能修改


typedef int MYINT;


typedef struct Person {
    char name[100];
    int age;

} MYPERSON;


void testExtern();

void testTypedef();

void testDeclareVariable();

void testVoidPointer();

void testSizeof();

void  testUnsignPlus();

void testModify();

void testMallocPointer();

void testConst();

void testNullptr();


#endif //STATEONE_PART1_H
