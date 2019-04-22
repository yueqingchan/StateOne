#include <iostream>
#include <assert.h>
#include "include/advanceOne.h"
//.h文件不参与编译,.h中实现的方法,相当于白实现.
//只有.c才是编译单元
//#include "testCompile.cpp" //这样相当于这里面也重新定义了方法.

//#include "include/BaseOnePart.h"
#include "include/StringPart.h"
#include "include/BaseOnePart.h"
#include "include/ExerciseOne.h"
#include "include/FilePartOne.h"
#include "include/ArrayPart.h"
#include "testAbout/testCompile3.h"
//#include "testAbout/testCompile.h"

void testCompileImInH();

//static int g_test = 20;  //自定义变量.h 文件是会参与编译的?

using namespace std;

void string_part();

void base_one_part();

void exercise_one_part();

void file_part();

void array_part();

int main() {

//    testCompile();

//    assert(1);                          //false 的话 直接abort!!

//    cout<<"assert  here"<<endl;

//    perror(" perror  execption ");

//    fprintf(stderr, "divied num  0 ... ");

//    file_part();
//    base_one_part();
//    string_part();
//    exercise_one_part();
//    array_part();
//    cout<<g_test<<endl;
    testCompileImInH3();
    return 0;
}


void string_part() {

    string_part_test_copy();
//     string_part_test_cat();
//    string_part_test_compare();
//    string_part_test_sprintf();
//    string_part_test_sscanf();
//    string_part_test_strchr();
//    string_part_test_strstr();
//    string_part_test_strtok();
//    string_part_test_stratoNum();

}

void base_one_part() {
//    test_gets();
//    base_one_part_union();
//    bitCalculate();
//    base_one_memory_set();
//    base_one_memory_copy();
//    base_one_memory_compare();
    base_one_memory_enum();
}

void exercise_one_part() {

    exercise_one_test_struct();

}

void file_part() {

//    file_part_one_open_fle();
//    file_part_one_put_c();
//    file_part_one_get_c();
//    file_part_one_put_s();
//    file_part_one_get_s();

//    file_part_one_write();
//    file_part_one_read();

//    file_part_one_big_file();

//    file_part_one_seek_file();

    file_part_one_seek_big();

}


void array_part() {

    init_arrary();

}