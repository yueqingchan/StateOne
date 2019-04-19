//
// Created by 87572 on 19/4/9.
//
#include <iostream>
#include "../include/advanceOne.h"
int a;              //不做赋值操作.全局区默认是0,栈区是随机值.
static int b=20;


/*
 * K1::===========================================================================
 * 声明和定义区别
 * extern 只是申明,并不会分配空间. 赋值操作才回分配空间.
 * 声明变量不需要建立存储空间，如：extern int a;
 * 定义变量需要建立存储空间，如：int b;
 * int a;//不做赋值操作.全局区默认是0,栈区是随机值.
 *
 * */
void testExtern() {
    cout << a << endl;          //打印:  0
}


/**
 * K2:==============================================================================
 * 1. void不能直接定义变量，因为编译器不知道分配多少内存给变量 ;
 * 2.  当定义一个变量，编译器必须要知道分配多少内存
    struct Person
    {
	    char name[64];
	    int age;
	    struct Person p;//此时是递归,未能形成闭包; 但是可以用指针.struct Person *person;
    };
 */
void testTypedef() {
    MYINT b;
    cout << b << endl;          //栈区的变量一定要初始化,理论上是随机值. 这里打印的是 0
    MYPERSON myperson = {"LiLei", 18};
    cout << myperson.name << "--" << myperson.age << endl;
}


/**
 * K3:================================================================================
 * 注意申明的时候细节  name 和age  不是同一个类型!!只有C++有typeId,C语言中没有.
 */
void testDeclareVariable() {
    char *name, age;
    cout << typeid(name).name() << endl; //Pc  字符指针
    cout << typeid(age).name() << endl;  //c    字符.
}


/**
 * K4:=================================================================================
 * void *  是所有指针的父类;  无需强转,主要用于C的封装, 可以用于判断是否是指针类型.
 */
void testVoidPointer() {
    int num = 10;
    int *q = &num;
    void *p = q;
    cout << typeid(p).name() << endl;// Pv
}


/**
 * K5:==================================================================================
 *  1. sizeof(基本类型).是正常返回实际的数据; 字节. unsigned int !!
 *  2. sizeof(struct)  会涉及到字节对齐 ,并不是简单的大小叠加. (和编译器有关系)
 *  3.sizeof(数组) 如果是形参,则会退化成指针.因为数组本质就是首元素的指针. arr[]  只是为了便于理解.
 */
void acceptArray(int arr[]) {   //建议不要直接写成 int *arr,写成 int arr[] 便于阅读.
    cout << sizeof(arr) << endl;

}

void testSizeof() {
    int arr[10];
    cout << sizeof(arr) << endl;   //sizeof(int) *10
    acceptArray(arr);           // sizeof(int)
    int *p_num=arr;             //数组就是首元素的指针

}


/*
 * K6:=====================================================================================
 * unsigned int  与 signed int 计算, 都会转换成无符号位.肯定大于0

 * */
void testUnsignedCal() {
    unsigned int a = 10;
    int b = a;           //可以在这里转换下就完事了.
    cout << b - 20 << endl;
}

void testUnsignPlus() {
    unsigned char a = 0;
    signed char b = -5;
    cout << a - b << endl;        //计算结果,还没搞懂为啥,先不管了!todo
    testUnsignedCal();
}

/**
 * K7:============================================================================
 * 修改数据,间接赋值,需要对对象取指针,才能修改,否则只是修改的形参本身.
 *
 * @param p
 */
void modifyInt(int *numP) {
    *numP = 10;
}

void testModify() {
    int num = 20;
    modifyInt(&num);
    cout << num << endl;
}

/**
 * K8:===============================================================================
 * 堆区内存申请.
 *功能：将s的内存区域的前n个字节以参数c填入参数：
	s：需要操作内存s的首地址
	c：填充的字符，c虽然参数为int，但必须是unsigned char , 范围为0~255
	n：指定需要设置的大小
    返回值：s的首地址
 *
 * 在内存的动态存储区(堆区)中分配一块长度为size字节的连续区域，用来存放类型说明符指定的类型。分配的内存空间内容不确定，一般使用memset初始化。
 *
 */
void testMallocPointer() {
    int *p = (int *) malloc(sizeof(int) * 10);
    //important!  一定要判断是否为NULL,可能申请不足.
    if (NULL == p) {
        return;
    }
    memset(p, 0, sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        *(p + i) = i;
        //p[i]=i;为什么会报错?  todo
    }
    for (int j = 0; j < 10; ++j) {
        cout << p[j] << endl;
    }
    //一定要释放! 释放NULL是不会出错误的,但是多次释放同一地址肯定会出错误!
    if (p!=NULL){
        free(p);
        p=NULL;
    }
}

/**
 * K9:==================================================================================
 * char *="helloWorld!";  指向的是字符串常量池,千万不要修改这个指针.
 * char arr []="helloWorld!";  指向的是栈或者堆!
 *
 */
void testConst(){

    char * arrConst="helloWorld!";
    char arr []="helloWorld!";
    printf("%X\n",arrConst);//这两个地址是不一样的!
    printf("%X\n",arr);

}


/**
 *K10:=================================================================================
 *
 * extern int a;    //只是声明
   int g_a;         //声明+定义
    const  int g_b=20;//常量区 不能修改
    {
        const int a=20;//栈区  可以间接修改
    }
 *  常量区包含: 1.字符串常量  2.const变量
 */



/**
 * K11:==================================================================================
 *都是空指针,但是只是内容指向的地址是NULL,指针变量并不是指向NULL
 *
 */
void testNullptr(){

    int *p= NULL;
    int *q= NULL;

    printf("%d\n",&p);//6487576
    printf("%d\n",&q);//6487568

}



/**
 * K12:==================================================================================
 *
 */














































