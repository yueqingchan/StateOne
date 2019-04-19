//
// Created by 87572 on 19/4/11.
//

#ifndef STATEONE_TESTCOMPILE_H
#define STATEONE_TESTCOMPILE_H

#include <iostream>

using namespace std;

//.h文件不参与编译,所以找不到实现  .h只放声明.声明可以多次.
void testCompile() {
    cout << "testComplie" << endl;
}

#endif //STATEONE_TESTCOMPILE_H
