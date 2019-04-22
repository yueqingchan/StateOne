//
// Created by 87572 on 19/4/11.
//

#ifndef STATEONE_TESTCOMPILE_H
#define STATEONE_TESTCOMPILE_H

#include <stdio.h>

static int g_test=10;//静态变量不能加extern声明,extern是全局修饰,static是当前文件修饰!

//int g_test2=20;   不能在.h文件中声明 全局变量,一旦.h问价被include,会多次重定义.

//.h文件不参与编译  .h只放声明.声明可以多次.
//.h中

struct TestPerson{


} ;

void testCompile();

/**
 * .h中实现的方法也是可以生效的.
 */
void testCompileImInH(){

    printf("void testCompileImInH()");

};

#endif //STATEONE_TESTCOMPILE_H
