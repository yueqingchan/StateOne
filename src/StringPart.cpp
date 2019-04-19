//
// Created by 87572 on 19/4/17.
//


#include "../include/StringPart.h"

/**
 * K1:===============================================================
 * 字符串就是以'\0'结尾的字符数组; "HelloWorld" 自带'\0'的结尾.
 * 如果没有以'\0'结尾,则会一直寻找'\0'结尾为止!
 */
void desc_string(void) {

    char arr1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("arr1 ,%s\n", arr1);
    char arr2[] = {'h', 'e', 'l', 'l', 'o'};
    printf("arr2 ,%s\n", arr2);              //输出结果是不对的.

}

/**
 * K2:===============================================================
 *  char str1[] = "HelloWorld!";栈上的char[]
    char *str2 = "HelloWorld!";常量池的[],不能修改.这两个地址不同.
 */
void desc_const_string(void) {
    char str1[] = "HelloWorld!";
    char *str2 = "HelloWorld!";
    printf("stack--String--%d\n", str1);
    printf("const--String--%d\n", str2);
}


/**
 * K3:===============================================================
 * char str1[] = "Hello"; 默认自带'\0',长多一个.
 * strlen(char *)  //计算指定指定字符串s的长度，不包含字符串结束符‘\0’  遇到'\0'截断
 * 只要是" "结构的就是字符串,结尾肯定包含'\0',无论中间有无'\0'
 * 因为是针对字符串, 所有的规则都是'\0' 字符串结束!
 */
void desc_string_size() {
    char str1[] = "Hello";
    char str2[] = {'H', 'e', 'l', 'l', 'o'};
    char str3[] = "hello\0world";
    int str_length = strlen(str1);
    cout << "size_of_str:    " << sizeof(str1) << endl;         //6
    cout << "size_of_str:    " << sizeof(str2) << endl;         //5
    cout << "size_of_str:    " << sizeof(str3) << endl;         //12
    cout << "size_of_str:    " << str_length << endl;           //5
    cout << "size_of_str:    " << strlen(str2) << endl;         // 不确定的数值; 自动找到'\0'结束
    cout << "size_of_str:    " << strlen(str3) << endl;         //5

}


/**
 * K4:===============================================================
 * 成功：返回dest字符串的首地址
 * 失败：NULL
 *
 * 默认拷贝 strcopy ----char *strcpy(char *dest, const char *src);
 *  ------越界则会导致崩溃;我测试的是不会崩溃;
 * 有限拷贝 strncopy----char *strncpy(char *dest, const char *src, size_t n);
 *  ------有限拷贝不会将\0拷贝到目标字符串中
 */
void string_part_test_copy() {
    char dest[5] = {1};
    char dest2[30] = {1};
    char *src = "HelloWorld!";    //遇到'\0'结束.
    for (int i = 0; i < 30; ++i) {
        dest2[i]=65;
    }
    for (int i = 0; i < 15; ++i) {
        cout<<"string_part_test_copy()  :"<<dest2[i]<<endl;// Hello\0World!  \0后面的自动停止!
    }

#if 0
    strcpy(dest, src);
    char *p1 = strcpy(dest, src);
    if (p1!=NULL){
        printf(" string_part_test_copy():  %s", dest);//默认追加'\0'(不是很确定,也要看数组大小是否满足)
        printf(" string_part_test_copy(): end");
    } else{
        cout<<" string_part_test_copy():  fail"<<endl;
    }
#else
    char *p2 = strncpy(dest2, src, 15);             //copy的时候会把src,的字符全部置为'\0'.
    if (p2 != NULL) {
        printf(" string_part_test_copy():  %s", dest2);//默认追加'\0'(不是很确定,也要看数组大小是否满足)
        printf(" string_part_test_copy():  end\n");
        for (int i = 0; i < 15; ++i) {
            cout<<"string_part_test_copy()  :"<<dest2[i]<<endl;// Hello\0World!  \0后面的自动停止!
        }
    } else {
        cout << " string_part_test_copy():  fail" << endl;
    }
#endif
}


/**
 * K5:===============================================================
 * 成功：返回dest字符串的首地址  理论上都应该追加'\0',但是要看数组能否装得下.(越界也没崩溃!)
 * 失败：NULL
 * 默认追加:    char *strcat(char *dest, const char *src);
 * 有限追加:    char *strncat(char *dest, const char *src, size_t n);
 */
void string_part_test_cat() {

    char dest[20] = "HelloWorld!";     //字符串追加的时候,默认回去掉'\0'

//    char dest[100] = {'H','i'};
    char *src = "NiceU!";    //\0后面的自动停止!
#if 1
    char *p1 = strcat(dest, src);
    if (p1 != NULL) {
        cout << "string_part_test_cat:    " << dest << endl;
    } else {
        cout << "string_part_test_cat:   fail" << endl;
    }
#else

    char *p2 = strncat(dest, src, 5);
    if (p2 != NULL) {
        cout << "string_part_test_ncat:    " << dest << endl;
    } else {
        cout << "string_part_test_ncat:   fail" << endl;
    }

#endif
}


/**
 * K6:===============================================================
 * 相等：0     大于：>0   小于：<0
 * int strcmp(const char *s1, const char *s2);  比较s1和s2是否相同，比较的是字符ASCII码大小。
 */
void string_part_test_compare() {

    char *p1 = "hello1";
    char *p2 = "1hello";
    int num = strcmp(p1, p2);
    int num2 = strncmp(p1, p2, 1);
    cout << "void string_part_test_cmp    :   " << num << endl;//-1  不相同,就算字符一样也不一致!
    cout << "void string_part_test_cmp    :   " << num2 << endl;//-1  不相同,就算字符一样也不一致!
}


/**
 * K7:===============================================================
 *
 * 追加数字
 *
 * int sprintf(char *_CRT_SECURE_NO_WARNINGS, const char *format, ...);
 * 功能：根据参数format字符串来转换并格式化数据，然后将结果输出到str指定的空间中，直到出现字符串结束符 '\0'  为止。
 * 参数：
 *  str：字符串首地址
 *  format：字符串格式，用法和printf()一样
 * 返回值：
 *  成功：实际格式化的字符个数
 *  失败： - 1
 */
void string_part_test_sprintf() {
    char dest[20] = {0};
    char *src = "HelloWorld!";
    char test[20] = "HelloWorld!";
//    sprintf(test, "%s%d", src, 5);
    sprintf(test, "%s%d", test, 5);         //这样也可以!
    cout << test << endl;
}



/**
 * K8:===============================================================
 *
 * 主要用于格式化字符串,类似于正则的处理.
 *
 * int sscanf(const char *str, const char *format, ...);
 * 功能：从str指定的字符串读取数据，并根据参数format字符串来转换并格式化数据。
 * 参数：
 *      str：指定的字符串首地址
 *      format：字符串格式，用法和scanf()一样
 * 返回值：
 *      成功：参数数目，成功转换的值的个数
 *      失败： - 1
 *
 */
void string_part_test_sscanf(){
    char src[] = "a=10, b=20";
    int a;
    int b;
    sscanf(src, "a=%d,  b=%d", &a, &b);
    printf("a:%d, b:%d\n", a, b);
}



/**
 * K9:===============================================================
 *char *strchr(const char *s, int c);
 *
 * 功能：在字符串s中查找字母c出现的位置
 * 参数：
 *      s：字符串首地址
 *      c：匹配字母(字符)
 * 返回值：
 *      成功：返回第一次出现的c地址
 *      失败：NULL
 *
 */
void string_part_test_strchr(){
    char src[] = "ddda123abcd";
    char *p = strchr(src, 'a');
    printf("string_part_test_strchr: = %s\n", p);
}



/**
 * K10:===============================================================
 * char *strstr(const char *haystack, const char *needle);
 * 功能：在字符串haystack中查找字符串needle出现的位置
 * 参数：
 *      haystack：源字符串首地址
 *      needle：匹配字符串首地址
 * 返回值：
 *      成功：返回第一次出现的needle地址
 *      失败：NULL
 */
void string_part_test_strstr(){

    char src[] = "ddddabcd123abcd333abcd";
    char *p = strstr(src, "abcd");
    printf("string_part_test_strstr = %s\n", p);

}

/**
 * K11:===============================================================
 * char *strtok(char *str, const char *delim);
 * 功能：来将字符串分割成一个个片段。当strtok()在参数s的字符串中发现参数delim中包含的分割字符时,
 *      则会将该字符改为\0 字符，当连续出现多个时只替换第一个为\0。
 *      在第一次调用时：strtok()必需给予参数s字符串
 *      往后的调用则将参数s设置成NULL，每次调用成功则返回指向被分割出片段的指针
 * 参数：
 *      str：指向欲分割的字符串
 *      delim：为分割字符串中包含的所有字符
 * 返回值：
 *      成功：分割后字符串首地址
 *      失败：NULL
 */
void string_part_test_strtok(){

    char a[100] = "abc**defg*hijk*lmn*opq";
    printf("string_part_test_strtok:  %p\n", a);
    char *s = strtok(a, "*");//将"*"分割的子串取出
    printf("string_part_test_strtok dest======:  %s\n", a);
    printf("string_part_test_strtok dest======:  %p\n", s);
    while (s != NULL)
    {
        printf("string_part_test_strtok:  %s\n", s);
        s = strtok(NULL, "*");
        printf("string_part_test_strtok:  %p\n", s);
    }
    printf("string_part_test_strtok dest======:  %s\n", a);
    for (int i = 0; i < 20; ++i) {

        printf("string_part_test_strtok dest======:  %c\n", a[i]);
    }

}


/**
 * K12:===============================================================
 * int atoi(const char *nptr);
 * 功能：
 *      atoi()会扫描nptr字符串，跳过前面的空格字符，直到遇到数字或正负号才开始做转换，而遇到非数字或字符串结束符('\0')才结束转换，并将结果返回返回值。
 *      atof()：把一个小数形式的字符串转化为一个浮点数。
 *      atol()：将一个字符串转化为long类型
 * 参数：
 *      nptr：待转换的字符串
 * 返回值：
 *      成功转换后整数   失败: 0  0.000000
 *
 */
void string_part_test_stratoNum(){

    char str1[] = "-10";
    int num1 = atoi(str1);
    printf("num1 = %d\n", num1);

    char str2[] = "0.123";
    double num2 = atof(str2);
    printf("num2 = %lf\n", num2);

}


/**
 * K13:===============================================================
 *
 */


/**
 * K14:===============================================================
 *
 */


/**
 * K15:===============================================================
 *
 */



/**
 * K16:===============================================================
 *
 */



