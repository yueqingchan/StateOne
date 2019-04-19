//
// Created by 87572 on 19/4/17.
//
#include "../include/FilePartOne.h"

struct Room {

    int num;
    char address[100];

};

/**
 * K1:====================================================================
 *  FILE * fopen(const char * filename, const char * mode);
 *  功能：打开文件
 *  参数：
 *      filename：需要打开的文件名，根据需要加上路径
 *      mode：打开文件的模式设置
 *  返回值：
 *      成功：文件指针
 *      失败：NULL
 *  r或rb	以只读方式打开一个文本文件（不创建文件，若文件不存在则报错）
 *  w或wb	以写方式打开文件(如果文件存在则清空文件，文件不存在则创建一个文件)
 *  a或ab	以追加方式打开文件，在末尾添加内容，若文件不存在则创建文
 *  r+或rb+	以可读、可写的方式打开文件(不创建新文件)
 *  w+或wb+	以可读、可写的方式打开文件(如果文件存在则清空文件，文件不存在则创建一个文件)
 *  a+或ab+	以添加方式打开文件，打开文件并在末尾更改文件,若文件不存在则创建文件
 *  ---------------------------------------------------------------------------------
 *  b是二进制模式的意思，b只是在Windows有效，在Linux用r和rb的结果是一样的
 *  Unix和Linux下所有的文本文件行都是\n结尾，而Windows所有的文本文件行都是\r\n结尾
 *  在Windows平台下，以“文本”方式打开文件，不加b：
 *  当读取文件的时候，系统会将所有的 "\r\n" 转换成 "\n"
 *  当写入文件的时候，系统会将 "\n" 转换成 "\r\n" 写入
 *  以"二进制"方式打开文件，则读\写都不会进行这样的转换
 *  在Unix/Linux平台下，“文本”与“二进制”模式没有区别，"\r\n" 作为两个字符原样输入输出
 *  ----------------------------------------------------------------------------------
 *  文件打开失败:    1.达到上限   2.路径错误  3.没有权限
 *  关闭文件:       成功：0失败：-1
 *
 */

char *file_path = "../a.txt";
char *file_path2 = "../block.txt";
char *big_file_path = "E:/src.PDF";

void file_part_one_open_fle() {

    FILE *file = fopen(file_path, "w");
    if (file != NULL) {
        cout << "open file success!" << endl;
    }
    if (file_path != NULL) {
        int num = fclose(file);
        cout << "close file  result    :" << num << endl;

    }
}


/**
 * K2:====================================================================
 * 文件结尾;
 * #define EOF     (-1)
 *
 * int feof(FILE * stream);
 * 功能：检测是否读取到了文件结尾。判断的是最后一次“读操作的内容”，不是当前位置内容(上一个内容)。
 * 参数：
 *      stream：文件指针
 * 返回值：
 *      非0值：已经到文件结尾
 *      0：没有到文件结尾
 * =========================================================================
 * *****当读取最后一个字符的时候,此时feof 并不是结尾,而是 再次读取一次的时候,才到结尾!
 *
 */
void file_part_one_end_fle() {
    /**
     *
     * EOF      判断文本
     * feof()   判断二进制
     * *********************************getC和read******************************************
     ******当读取最后一个字符的时候,此时feof 并不是结尾,而是 再次读取一次的时候,才到结尾!
     * --------------------------------------------------------------------------------------
     * fgets 读到最后一行,不需要在此执行fgets,此时feof就是!0的数据.
     *
     */

}


/**
 * K3:====================================================================
 * int fputc(int ch, FILE * stream);
 * 功能：将ch转换为unsigned char后写入stream指定的文件中
 * 参数：
 *      ch：需要写入文件的字符
 *      stream：文件指针
 * 返回值：
 *      成功：成功写入文件的字符
 *      失败：返回-1
 *
 */
void file_part_one_put_c() {

    FILE *file = fopen(file_path, "w");

    fputc('H', file);
    fputc('E', file);
    fputc('L', file);
    fputc('L', file);
    fputc('O', file);
    fclose(file);
}


/**
 * K4:====================================================================
 *int fgetc(FILE * stream);
 * 功能：从stream指定的文件中读取一个字符
 * 参数：
 *      stream：文件指针
 * 返回值：
 *      成功：返回读取到的字符
 *      失败：-1
 *
 */
void file_part_one_get_c() {

    FILE *file = fopen(file_path, "r");
    if (file != NULL) {
        cout << "open success!" << endl;
    } else {
        cout << "open fail!" << endl;
        return;
    }
    char ch = NULL;

#if 0

    int num=0;

    while (num<10) {
        ch = fgetc(file);
        cout << "file_part_one_get_c    :" << ch << endl;
        num++;
    }
/*
    while ((ch = fgetc(file)) != EOF) {     //文本用这个最保险  EOF =-1
        cout << "file_part_one_get_c    :" << ch << endl;
    }
*/

#else
    int num = feof(file);                   //二进制判断用这个
    cout << "num  Outer  :" << num << endl;
    while (!num)     //文件没有结束，则执行循环
    {
        ch = static_cast<char>(fgetc(file));
        printf("%d", ch);
        printf("%c\n", ch);
        num = feof(file);
        cout << "num  Inner :" << num << endl;
    }

#endif
    fclose(file);

}


/**
 * K5:====================================================================
 *int fputs(const char * str, FILE * stream);
 * 功能：将str所指定的字符串写入到stream指定的文件中，字符串结束符 '\0'  不写入文件。
 * 参数：
 *      str：字符串
 *      stream：文件指针
 * 返回值：
 *      成功：0
 *      失败：-1
 *
 */
void file_part_one_put_s() {
    FILE *file = fopen(file_path, "w");
    if (file != NULL) {
        cout << "open success!" << endl;
    } else {
        cout << "open fail!" << endl;
        return;
    }

    int result = fputs("Hello,nice to meet U!", file);
    fputs("Welcome to here!", file);

    cout << "result" << result << endl;

    fclose(file);

}


/**
 * K6:====================================================================
 *  char * fgets(char * str, int size, FILE * stream);
 *  功能：从stream指定的文件内读入字符，保存到str所指定的内存空间，直到出现换行字符、
 *  读到文件结尾或是已读了size - 1个字符为止，最后会自动加上字符 '\0' 作为字符串结束。
 *
 *  参数：
 *        str：字符串
 *        size：指定最大读取字符串的长度（size - 1）
 *        stream：文件指针
 *  返回值：
 *        成功：成功读取的字符串
 *        读到文件尾或出错： NULL
 *        fgets 读到最后一行,不需要在此执行fgets,此时feof就是!0的数据.
 *
 */
void file_part_one_get_s() {

    FILE *file = fopen(file_path, "r");
    if (file != NULL) {
        cout << "open success!" << endl;
    } else {
        cout << "open fail!" << endl;
        return;
    }

    char arr[100];
    char *num = NULL;
    cout << "arr---start----:" << feof(file) << endl;
    num = fgets(arr, 100, file);
    cout << "arr----1---:" << feof(file) << endl;
    printf("%p\n", num);
    num = fgets(arr, 100, file);
    cout << "arr----2---" << feof(file) << endl;
    printf("%p\n", num);
    num = fgets(arr, 100, file);
    cout << "arr----3---" << feof(file) << endl;
    printf("%p\n", num);
    /*while (!feof(file)){
        char * p=fgets(arr, 100, file);
        if (p==NULL){
            cout<<"p==NULL"<<endl;
            return;
        }

        printf("p    : %p\n",p);
        cout << "arr content    :" << arr << endl;
    }*/
    fclose(file);
}


/**
 * K7:====================================================================
 *  size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
 *  功能：以数据块的方式给文件写入内容
 *  参数：
 *      ptr：准备写入文件数据的地址
 *      size： size_t 为 unsigned int类型，此参数指定写入文件内容的块数据大小
 *      nmemb：写入文件的块数，写入文件数据总大小为：size * nmemb
 *  stream：已经打开的文件指针
 * 返回值：
 *      成功：实际成功写入文件数据的块数目，此值和nmemb相等
 *      失败：0
 *
 */
void file_part_one_write() {

    FILE *file = fopen(file_path2, "wb");
    if (file != NULL) {
        cout << "open success!" << endl;
    } else {
        cout << "open fail!" << endl;
        return;
    }
    Room *rooms = static_cast<Room *>(malloc(sizeof(struct Room) * 3));
    for (int i = 0; i < 3; ++i) {
        rooms[i].num = i;
        sprintf(rooms[i].address, "%s %d", "roomNum: ", i);
    }

    for (int i = 0; i < 3; ++i) {
        cout << "Address  :" << rooms[i].address << "Num  :" << rooms[i].num << endl;
    }

    int result = fwrite(rooms, sizeof(struct Room), 3, file);
    cout << "fwrite   num :" << result << endl;
    fclose(file);

}


/**
 * K8:====================================================================
 *  size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
 *  功能：以数据块的方式从文件中读取内容
 *  参数：
 *      ptr：存放读取出来数据的内存空间
 *      size： size_t 为 unsigned int类型，此参数指定读取文件内容的块数据大小
 *      nmemb：读取文件的块数，读取文件数据总大小为：size * nmemb
 *      stream：已经打开的文件指针
 *  返回值：
 *      成功：实际成功读取到内容的块数，如果此值比nmemb小，但大于0，说明读到文件的结尾。
 *      失败：0
 *
 */
void file_part_one_read() {
    FILE *file = fopen(file_path2, "rb");
    if (file != NULL) {
        cout << "open success!" << endl;
    } else {
        cout << "open fail!" << endl;
        return;
    }
#if 0

    Room *rooms = static_cast<Room *>(malloc(sizeof(struct Room) * 3));
    int result = fread(rooms, sizeof(struct Room), 3, file);
    cout << "result" << result << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Address  :" << rooms[i].address << "Num  :" << rooms[i].num << endl;
    }

#else
    while (!feof(file)) {
        Room rooms[3];
        int size = fread(rooms, sizeof(struct Room), 3, file);
        if (size == 0) {
            cout << "the end of  file!" << endl;
            return;
        }
        for (int i = 0; i < 3; ++i) {
            cout << "---Address  :" << rooms[i].address << "Num  :" << rooms[i].num << endl;
        }
    }


#endif
    fclose(file);

}

/**
 * K9:====================================================================
 *  大文件复制
 */
void file_part_one_big_file() {

    FILE *file_src = fopen(big_file_path, "rb");     //7,375,866 字节

    char *dest_space = "E:/dest.PDF";

    FILE *file_dest = fopen(dest_space, "wb");

    if (file_src != NULL && file_dest != NULL) {
        cout << "open pdf success!" << endl;
    } else {
        cout << "open pdf fail!" << endl;
    }

    char *arr = static_cast<char *>(malloc(sizeof(char) * 1024));

    memset(arr, 0, 1024);

    cout << "open result:" << !feof(file_src) << endl;

    while (!feof(file_src)) {

        size_t block_src = fread(arr, sizeof(char), 1024, file_src);

        if (block_src == 0) {

            cout << "block  num ==    0" << endl;
            break;
        }

        size_t block_dest = fwrite(arr, sizeof(char), block_src, file_dest);

        cout << "read file Num    :" << block_src << endl;

        cout << "write file Num    :" << block_dest << endl;

//        fflush(file_dest);

        cout << "open result inner:" << !feof(file_src) << endl;
    }

    fclose(file_dest);
    fclose(file_src);
}


/**
 * K10:====================================================================
 *int fseek(FILE *stream, long offset, int whence);
 * 功能：移动文件流（文件光标）的读写位置。
 *      写的时候格式必须是w,a不可以,否则会只在后面追加!!
 * 参数：
 *      stream：已经打开的文件指针
 *      offset：根据whence来移动的位移数（偏移量），可以是正数，也可以负数，如果正数，则相对于whence往右移动，
 *      如果是负数，则相对于whence往左移动。如果向前移动的字节数超过了文件开头则出错返回，如果向后移动的字节数超过了文件末尾，再次写入时将增大文件尺寸。
 *      whence：其取值如下：
 *          SEEK_SET：从文件开头移动offset个字节
 *          SEEK_CUR：从当前位置移动offset个字节
 *          SEEK_END：从文件末尾移动offset个字节
 *     返回值：
 *     成功：0
 *     失败：-1
 */
/**
 * K11:====================================================================
 *long ftell(FILE *stream);
 * 功能：获取文件流（文件光标）的读写位置。
 * 参数：
 *      stream：已经打开的文件指针
 * 返回值：
 *      成功：当前文件流（文件光标）的读写位置
 *      失败：-1
 *==========================================================================
 * void rewind(FILE *stream);
 * 功能：把文件流（文件光标）的读写位置移动到文件开头。
 * 参数：
 *      stream：已经打开的文件指针
 * 返回值：
 *      无返回值
 */
void file_part_one_seek_file() {

    FILE *file = fopen(file_path, "r");

    if (file != NULL) {
        cout << "open success!" << endl;
    } else {
        cout << "open fail!" << endl;
        return;
    }
    /**
     * 如果向前移动的字节数超过了文件开头则出错返回;
     * 如果向后移动的字节数超过了文件末尾，再次写入时将增大文件尺寸。
     */
    int result1 = fseek(file, 5, SEEK_SET);
    cout << result1 << "||" << fgetc(file) << endl;     //0  44

    int result2 = fseek(file, -5, SEEK_SET);
    cout << result2 << "||" << fgetc(file) << endl;     //-1  -1

    //一旦向前出错,那么就直接rewind吧! 不然的话 前进不了了.
    int result3 = fseek(file, 2, SEEK_CUR);
    cout << result3 << "||" << fgetc(file) << " fTell    :" << ftell(file) << endl;     //0  -1

    rewind(file);

    int result5 = fseek(file, 0, SEEK_CUR);
    cout << result5 << "||" << fgetc(file) << " fTell    :" << ftell(file) << endl;     //0  -1


    int result4 = fseek(file, 5, SEEK_END);
    cout << result4 << "||" << fgetc(file) << endl;     //0    -1

    fclose(file);

}


void file_part_one_seek_big() {

    char *path="../create.txt";
    FILE *file = fopen(path, "w");

    if (file != NULL) {
        cout << "open success!" << endl;
    } else {
        cout << "open fail!" << endl;
        return;
    }

    int num = fseek(file, 1024*1024*1024, SEEK_SET);//制造大文件,类似于randomAccessfile,可以多个线程写入!

    cout << num << endl;

    int result = fputc('K', file);

    fseek(file,-5,SEEK_CUR);

    fputc('H', file);

    cout << result << endl;

    fclose(file);

}


/**
 * K12:=============================================================
 * int remove(const char *pathname);
 * 功能：删除文件
 * 参数：
 *      pathname：文件名
 * 返回值：
 *      成功：0
 *      失败：-1
 *
 * ===================================================================
 *
 * #include <stdio.h>
 * int rename(const char *oldpath, const char *newpath);
 * 功能：把oldpath的文件名改为newpath
 * 参数：
 *      oldpath：旧文件名
 *      newpath：新文件名
 * 返回值：
 * 成功：0
 * 失败： - 1
 *
 */





