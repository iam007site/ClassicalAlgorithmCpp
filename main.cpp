#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stack>
#include <MyString.h>
#include "src/Q9706.cpp"
#include "src/WellGame.cpp"
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

void println(char* data)
{
    cout << data << endl;
}

// 实现字符串的拷贝
char* mystrcpy(const char* src, char* dest)
{
    if (NULL == src || NULL == dest)
    {
        return NULL;
    }
    if (src == dest)
    {
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
class MyString1
{
public:
    MyString1(const char* pdata)
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

    MyString1(const MyString1 &ref)
    {
        data = new char[strlen(ref.data) + 1];
        strcpy(data, ref.data);
    }
    ~MyString1()
    {
        if (NULL != data)
        {
            delete [] data;
            data = NULL;
        }
    }
    const MyString1 & operator =(const MyString1 &ref)
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
    MyString1 mystring("12345");
    MyString1 mystring2(mystring);
    MyString1 mystring3 = mystring;
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
    for (int i = len-1; i>= 0 ; --i,pow *= 10)
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

struct LNode
{
    LNode* next;
    int value;
};

// 删除单链表中值为value的节点，输入链表带有一个无效的头节点head
void deleteLNode(LNode* head, int value)
{
    LNode* newHead = new LNode;
    newHead->value = 0;
    newHead->next = head;

    LNode* pre = newHead;
    LNode* next = newHead->next;
    while(NULL != next)
    {
        if(value == next->value)
        {
            pre->next = next->next;
            delete next;
            next = pre->next;
        }
        else
        {
            pre = next;
            next = next->next;
        }
    }
}

// 在链表的index位置插入值value
void insertLNode(LNode *head, int index, int value)
{
    LNode *iter = head;
    for (int i=0; i<index && NULL != iter; i++)
    {
        ;
    }
    if (NULL != iter)
    {
        LNode* node = new LNode;
        node->value = value;
        node->next = iter->next;
        iter->next = node;
    }
}

// 反转单链表
LNode* reverLNode(LNode* head)
{
    LNode* newHead = new LNode;
    newHead->value = 0;
    newHead->next = NULL;

    LNode* iter = newHead;
    LNode* temp = NULL;
    while(NULL != head)
    {
        temp = head;
        head = head->next;
        temp->next = newHead->next;
        newHead->next = temp;
    }
    return newHead;
}

void test_reverLNode()
{
    LNode* head = new LNode;
    head->value = 0;
    head->next = 0;
    LNode* iter = head;
    for(int i=1; i<6; i++)
    {
        LNode* node = new LNode;
        node->value = i;
        node->next = NULL;
        iter->next = node;
        iter = iter->next;
    }

    LNode* start = head;
    while(start != NULL)
    {
        cout << start->value << endl;
        start = start->next;
    }

    head = reverLNode(head);
    while(head != NULL)
    {
        cout << head->value << endl;
        head = head->next;
    }
}

// 斐波那契数列
int fibonacci1(int n)
{
    if(n < 0)
    {
        return -1;
    }
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibonacci1(n-1) + fibonacci1(n-2);
}

int fibonacci2(int n)
{
    if(n < 0)
    {
        return -1;
    }
    if (n == 0 || n == 1)
    {
        return n;
    }
    int n2 = 0;
    int n1 = 1;
    int result = 0;
    for (int i=2; i<=n; i++)
    {
        result = n1 + n2;
        n2 = n1;
        n1 = result;
    }
    return result;
}

void test_fibonacci()
{
    for (int i=0; i<11; i++)
    {
        cout << fibonacci1(i) << endl;
    }

    for (int i=0; i<11; i++)
    {
        cout << fibonacci2(i) << endl;
    }
}

// 产生[min,max]之间的一个随机整数
int randomInt(int min,int max)
{
    if(min > max)
    {
        min = min^max;
        max = max^min;
        min = min^max;
    }
    return rand() % (max - min + 1) + min;
}

void test_randomInt()
{
    for(int i=0; i<10; i++)
    {
        cout << randomInt(i*10,100) << endl;
    }
}

// 是否是素数
bool isPrime(int n)
{
    for (int i= 2; i<=(int)sqrt(n); i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

// 打印[2, n]的素数
void printPrime(int n)
{
    for (int i=2; i<=n; i++)
    {
        if(isPrime(i))
        {
            cout << i << endl;
        }
    }
}

void test_PrintPrime()
{
    printPrime(100);
}

// 用栈来实现队列的FIFO
int queuePop(stack<int> &stacka)
{
    stack<int> stackb;
    while(!stacka.empty())
    {
        stackb.push(stacka.top());
        stacka.pop();
    }
    const int head = stackb.top();
    stackb.pop();
    while(!stackb.empty())
    {
        stacka.push(stackb.top());
        stackb.pop();
    }
    return head;
}

void test_queuePop()
{
    stack<int> stack1;
    for (int i=0; i<10; i++)
    {
        stack1.push(i);
    }
    while(!stack1.empty())
    {
        cout<< queuePop(stack1) << endl;
    }
}
// 解决地址重叠的memoryCopy,功能跟memoryMove()一样了
void* myMemoryCopy(void* dest, const void* src,size_t count)
{
    if (NULL == dest || NULL == src || count <= 0)
    {
        return NULL;
    }
    char* destIter = (char*)dest;
    const char* srcIter = (char*)src;
    if (srcIter>destIter || destIter+count<srcIter)
    {
        // 没有重叠影响，从前往后拷贝
        while(count--)
        {
            *destIter++ = *srcIter++;
        }
    }
    else
    {
        // 有重叠，从后往前拷贝
        destIter += count -1;
        srcIter += count - 1;
        while(count--)
        {
            *destIter-- = *srcIter--;
        }
    }
    return dest;
}

void test_myMemoryCopy()
{
    char* src = "1qaz@WSX";
    char dest[strlen(src)] = "22222222";
    myMemoryCopy(dest, src, strlen(src));
    println(dest);
}

void* myMemeorySet(void* buffer, int c, size_t count)
{
    if (NULL == buffer ||count < 0)
    {
        return NULL;
    }
    char* bufferIter = (char*)buffer;
    while(count--)
    {
        *bufferIter++ = (char)c;
    }
    return buffer;
}

void test_MyMemorySet()
{
    char buffer[] = "1qaz@WSX";
    println((char*)memset(buffer,'+', 5));
    println((char*)myMemeorySet(buffer,'-', 5));
}

void test_MyStringClass()
{
    MyString str1;
    MyString str2("2222222");
    cout << str2 << endl;

    str1 = str2;
    cout << str1 <<endl;

    cout << str1 + str2 << endl;
}


int main()
{
    cout << "http://blog.csdn.net/f_r_e_e_x/article/details/50770907" << endl;
    srand((unsigned int)time(NULL));
    // test_mystrcpy();
    // test_mystrcat();
    // test_MyString();
    // test_myswap();
    // test_myatoi();
    // test_myStringRevers();
    // test_myToUpper();
    // test_MyBinarySearch();
    // test_reverLNode();
    // test_fibonacci();
    // test_randomInt();
    // test_PrintPrime();
    // test_queuePop();
    // test_myMemoryCopy();
    // test_MyMemorySet();
    // test_MyStringClass();
    // Q9706::test();
    // WellGame::run();

    int i = 0;
    int j = (i += i > 0);
    //i += i > 0 ? i++ : i--;
    cout << i << j <<  endl;
    system("pause");
    return 0;
}


