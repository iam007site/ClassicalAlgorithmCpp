#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

void println(char* data)
{
    cout << data << endl;
}

// 实现字符串的拷贝
char* mystrcpy(const char* src, char* dest)
{
    if (NULL == src || NULL == dest) {
        return NULL;
    }
    if (src == dest) {
        return dest;
    }
    char* iter = dest;
    while((*iter++ == *src++) != '\0')
    return dest;
}

void test_mystrcpy()
{
    const char* src = "123456";
    char* dest = "654321";
    mystrcpy(src, dest);
    cout << src << endl;
    cout << dest << endl;
}

// 实现字符串拼接
char* mystrcat(char* dest, const char* add)
{
    if (NULL == dest || NULL == add)
    {
        return NULL;
    }
    char* iter  = dest;
    while (*iter != '\0')
    {
        iter++;
    }
    while((*iter++ = *add++) != '\0')
    {
        ;
    }
    return dest;
}

void test_mystrcat()
{
    char d[20]="original-";
    char *s=" add";
    mystrcat(d, s);
    cout << d << endl;
}

// 实现string的四个方法，包括构造函数、拷贝构造函数、析构函数、复制操作符
class MyString{
public:
    MyString(const char* pdata)
    {
        if (NULL == pdata)
        {
            data = new char[1];
            data[0] = '\0';
        }
        else
        {
            data = new char[strlen(pdata) + 1];
            strcpy(data, pdata);
        }
    }

    MyString(const MyString &ref)
    {
        data = new char[strlen(ref.data) + 1];
        strcpy(data, ref.data);
    }
    ~MyString()
    {
        if (NULL != data)
        {
            delete [] data;
            data = NULL;
        }
    }
    const MyString & operator =(const MyString &ref)
    {
        if(this == &ref)
        {
            return *this;
        }
        delete [] data;
        data = new char[strlen(ref.data) + 1];
        strcpy(data, ref.data);
        return *this;
    }

    char* getData()
    {
        return data;
    }

private:
    char* data;
};

void test_MyString()
{
    MyString mystring("12345");
    MyString mystring2(mystring);
    MyString mystring3 = mystring;
    cout << mystring.getData() << mystring2.getData() << mystring3.getData() << endl;
}

// 原地交换两个数
void myswap(int &a, int &b)
{
    if(a != b)
    {
        a = a^b;
        b = b^a;
        a = a^b;
    }
}

void test_myswap()
{
    int a = 100,b=200;
    cout << a << b << endl;
    myswap(a,b);
    cout << a << b << endl;
}

// 字符串转数字
int myatoi(const char* data)
{
    if(NULL == data)
    {
        return -1;
    }
    int len = strlen(data);
    int result = 0;
    int pow = 1;
    for (int i = len-1;i>= 0 ;--i,pow *= 10)
    {
        result += (data[i] - '0')*pow;
    }
    return result;
}

void test_myatoi()
{
    cout << myatoi("12345") << endl;
}

// 字符串反转
char* myStringRevers(char* data)
{
    if (NULL == data)
    {
        return NULL;
    }
    char* begin = data;
    char* end = data;
    while(*end != '\0')
    {
        end++;
    }
    end--;
    char temp;
    while (begin < end)
    {
        temp = *begin;
        *begin = *end;
        *end = temp;
        ++begin;
        --end;
    }
    return data;
}

void test_myStringRevers()
{
    char original[] = "12345678";
    cout << original << endl;
    cout << myStringRevers(original) << endl;
}

// 字符串转为大小字符
char* myToUpper(char* data)
{
    if (NULL == data)
    {
        return NULL;
    }
    char* iter = data;
    while(*iter != '\0')
    {
        if ('a' <= *iter && *iter <= 'z')
        {
            *iter -= 'a' - 'A';
        }
        iter++;

    }
    return data;
}

void test_myToUpper()
{
    char data[] = "1qaz@WSX";
    println(data);
    println(myToUpper(data));
}

// 二分查找已排序的数组，找不到返回-1
int myBinarySearch(int* data, int total, int value)
{
    if (NULL != data)
    {
        int end = total - 1;
        int start = 0;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if (data[mid] == value)
            {
                return mid;
            }
            else if (data[mid] > value)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return -1;
}

void test_MyBinarySearch()
{
    int data[] = {1,2,3,4,5,6,7,8};
    cout << myBinarySearch(data, 8, 5);
}

int main()
{
    cout << "http://blog.csdn.net/f_r_e_e_x/article/details/50770907" << endl;

    // test_mystrcpy();
    // test_mystrcat();
    // test_MyString();
    // test_myswap();
    // test_myatoi();
    // test_myStringRevers();
    // test_myToUpper();
    // test_MyBinarySearch();
    system("pause");
    return 0;
}


