//
// Created by 87572 on 19/4/17.
//

#include "../include/BaseOnePart.h"

enum Color {
    RED, YELLOW, BLUE
} CC;


/**
 * K1:==========================================================
 *
 *   八进制 : o输出  0书写
 * 十六进制 : x输出  0x书写
 *  十进制  : d输出  书写
 */
void test_differ_bin() {

    int a = 9;
    int b = 07;
    int c = 0xD;

    printf("10 BIN out %d\n", a);
    printf("8  BIN out%o\n", b);
    printf("16 BIN out%x\n", c);

    int d = a * b;


    printf("%d\n", d);
}


/**
 * K2:==========================================================
 *   先++  先++后运算
 *   ++后  先运算后++
 */
void test_add() {

    int a = 10;
    printf("%d\n", a++);
    int b = 10;
    printf("%d\n", ++b);

}


/**
 * K3:==========================================================
 * float 3.14f 3.14F
 * double 3.14
 *
 * int  10
 * usigned int 10u  10U
 *
 * long 10l 10L
 * longlong 10ll 10LL
 *
 * unsigned long 10ul
 * unsigned long long 10ull
 *
 */
void test_num_type_write() {

    float a = 3.14f;
    double b = 3.14;
    int c = 10;
    long d = 10l;
    long long e = 10ll;


}

/**
 * K4:==========================================================
 * 符号位的溢出会导致正负发生变化
 * 无符号位的溢出会导致最大值发生变化
 */
void test_num_full() {

    char c = 0x7f;
    printf("%d\n", c);  //127
    c += 2;
    printf("%d\n", c);  //-127  符号位溢出

    unsigned char d = 0XFF;
    printf("%d\n", d);   //255
    d += 2;
    printf("%d\n", d);   //  1  最大值溢出

}


/**
 * K5:==========================================================
 *  隐式转化;自动转换,遵循一定的规则,由编译系统自动完成。
 *  强制转换:占用内存字节数少(值域小)的类型，向占用内存字节数多(值域大)的类型转换，以保证精度不降低。
 *  用 %d 输出 float 会打印0  输出类型错误导致的;输出的时候要用对应的类型.
 *
 */
void test_num_change() {
#if 1
    int a = 10;
    float f = 10.2f;
    printf("test_num_change  :  %d\n", a / 2);      //5
    printf("test_num_change  :  %d\n", a / 2.0);    //0
    printf("test_num_change  :  %d\n", 2.0);        //0
    printf("test_num_change  :  %lf\n", a / 2.0);   //5.000000
    printf("test_num_change  :  %d\n", (int) f);    //10
    printf("test_num_change  :  %d\n", 1.0f);       //0
    printf("test_num_change  :  %f\n", 1);          //0.000000
#else
    int a = 10;
    int b = 3;
    int c = (float)a / (float)b;
    printf("test_num_change %d\n", c);
#endif
}


/**
 * K6:==========================================================
 * 三目运算符
 */

void test_three_cal() {

    int a = 10;
    int b = 8;
    int c = a > b ? a : b;
    printf("%d\n", c);
}



/**
 * K7:==========================================================
 *  time.h 和random的使用
 *  srand对rand设置一个随机种子数,否则每次运行程序随机值都是相同的.
 *  j=(int)(n*rand()/RAND_MAX+1)，用来产生0到N之间的整数;
 */
int get_random_int(int n, int m) {
#if 0   //这种不大好用
    int j = (n * rand() / RAND_MAX + 1);
    return j;
#else   //还是这种好用
    return rand() % (m - n + 1) + n;

#endif
}

void test_time_random() {

    cout << "time" << time(0) << endl;           //输出当前时间 秒,返回值是longlong类型.
    srand((unsigned int) time(0));
    for (int i = 0; i < 10; ++i) {
//        cout<<rand()<<endl;
        cout << "get random:  " << get_random_int(0, 100) << endl;
    }

}





/**
 * K8:==========================================================
 * 常用系统宏指令:
 * _FILE_   : 宏所在的文件的 源文件名
 * _DATA_   : 代码编译的日期
 * _LINE_   : 宏所在的行号
 * _TIME_   : 代码编译的时间
 *
 */
void show_macroi(void) {

    cout << "_DATA_   " << __DATE__ << endl;
    cout << "_LINE_   " << __LINE__ << endl;
    cout << "_TIME_   " << __TIME__ << endl;
    cout << "_FILE_   " << __FILE__ << endl;

}





/**
 * K9:===========================================================
 * puts         //默认输出'\n'
 * putchar函数   //不输出'\n'
 */
void test_puts() {

    putchar('A');
    puts("HelloWorld!");
}

/**
 * K10:===========================================================
 * gets
 *
 * gets(str)与scanf(“%s”,str)的区别
 * gets(str)允许输入的字符串含有空格
 * scanf(“%s”,str)不允许含有空格
 * -----------------------------------------------------
 * getchar函数
 *  scanf()
 *  -------不能接受" ",默认识别为结束.
 *  -------不建议使用其他,都使用"  ",便于输入格式统一.
 *  -------有正则匹配规则;todo? 需要用的话就看看.
 */
void test_gets() {
    /* char c;
     c = getchar();
     cout<<"getChar"<<c<<endl;*/

    /* char arr1[100];
     scanf("%s",arr1);
     cout<<"scanf:  "<<arr1<<endl;//输出的是hello ,遇到空格和回车默认终止!*/


    /*  char arr1[2];   //越界会导致崩溃,可用正则规避!
      scanf("%s",arr1);
      cout<<"scanf:  "<<arr1<<endl;//输出的是hello ,遇到空格和回车默认终止!*/

    int a, b, c;
    scanf("%d  %d  %d", &a, &b, &c);  //建议使用空格隔断   减少错误概率!
    cout << "scanf:  " << a << b << c << endl;

}

/**
 * K11:======================================
 * union
 * 联合体所占的内存长度等于其最长成员的长度，也有叫做共用体；但是存在字节对齐的情况;并不是简单的最大值!
 * 同一内存段可以用来存放几种不同类型的成员，但每一瞬时只有一种起作用；
 * 共用体变量中起作用的成员是最后一次存放的成员，在存入一个新的成员后原有的成员的值会被覆盖；
 * 共用体变量的地址和它的各成员的地址都是同一地址。
 *
 */
void base_one_part_union() {

    cout << "base_one_part_union: " << sizeof(union Home) << endl;
    cout << "base_one_part_union: " << sizeof(Home) << endl;
    cout << "base_one_part_union: " << sizeof(enum Color) << endl;
    union Home home;
    home.address[0] = 'A';
    home.address[1] = 'B';
    home.address[2] = 'C';

}


/**
 * K12:======================================
 * bit calculate
 * 异或: 相同为0 不同为1
 * 已知：10011010：
 *      1.将位2打开         flag |  10011010
 *                           (10011010)
 *                          |(00000100)
 *                         =(10011110)
 *      2.将所有位打开      flag | ~flag
 *                          (10011010)
 *                         |(01100101)
 *                         =(11111111)
 *      3.关闭所有位       flag & ~flag
 *                       (10011010)
 *                      &(01100101)
 *                     =(00000000)
 *     4.转置位        flag ^ 0xff
 *
 *     5.交换变量      //a ^ b = temp;//a ^ temp = b;//b ^ temp = a
 *
 *     6. C中,0是fasle,其余的数字都是true. !1 !-1 都是fasle, !0 就是true
 *
 */
void bitCalculate() {

    unsigned char a = 1 << 1;
    unsigned char b = 0;
    cout << "&    :" << (a & b) << endl;
    cout << "|    :" << (a | b) << endl;

}


/**
 * K13:================================================
 * void *memset(void *s, int c, size_t n);
 *  功能：将s的内存区域的前n个字节以参数c填入
 *  参数：
 *      s：需要操作内存s的首地址
 *      c：填充的字符，c虽然参数为int，但必须是unsigned char , 范围为0~255
 *      n：指定需要设置的大小
 *  返回值：s的首地址
 *
 */
void base_one_memory_set() {
    int *p = static_cast<int *>(malloc(sizeof(int) * 10));
    memset(p, 0, 40);
    free(p);
};

/**
 * K14:================================================
 * void *memcpy(void *dest, const void *src, size_t n);
 * 功能：拷贝src所指的内存内容的前n个字节到dest所值的内存地址上。
 * 参数：
 *      dest：目的内存首地址
 *      src：源内存首地址，注意：dest和src所指的内存空间不可重叠
 *      n：需要拷贝的字节数
 * 返回值：dest的首地址
 */
void base_one_memory_copy() {

    struct MyPerson *person1 = static_cast<MyPerson *>(malloc(sizeof(struct MyPerson)));
    struct MyPerson *person2 = static_cast<MyPerson *>(malloc(sizeof(struct MyPerson)));

    strcpy(person1->name, "Lucy");
    person1->age = 20;

    memcpy(person2, person1, sizeof(struct MyPerson));

    cout << person2->name << "" << person2->age << endl;

    free(person1);
    person1 = NULL;
    free(person2);
    person2 = NULL;
};


/**
 * K15:================================================
 * int memcmp(const void *s1, const void *s2, size_t n);
 * 功能：比较s1和s2所指向内存区域的前n个字节
 * 参数：
 *      s1：内存首地址1
 *      s2：内存首地址2
 *      n：需比较的前n个字节
 *  返回值：
 *      相等：=0
 *      大于：>0
 *      小于：<0
 */
void base_one_memory_compare() {

    unsigned char arr1[10] = {1, 2, 3, 4, 5, 6};
    unsigned char arr2[10] = {1, 3, 2, 4, 5, 6};
    int result = memcmp(arr1, arr2, 6);
    cout<<"base_one_memory_compare  :"<<result<<endl;

};

/**
 * K16:========================================================
 * enum:默认从0开始.
 *
 */
 void test_enum(Color color){

     printf("%d\n",color);

 }
void base_one_memory_enum(){

     Color YELLOW=BLUE;
     test_enum(YELLOW);

}





