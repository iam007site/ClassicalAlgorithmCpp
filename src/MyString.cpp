#include "MyString.h"

MyString::MyString():cdata(NULL),clength(0)
{
    //ctor
}

MyString::MyString(const MyString& str)
{
    if (NULL != str.cdata)
    {
        clength = str.clength;
        cdata = new char[clength + 1];
        strcpy(cdata, str.cdata);
    }

}

MyString::MyString(const char* data)
{
    if (NULL != data)
    {
        clength = strlen(data);
        cdata = new char[clength + 1];
        strcpy(cdata, data);
    }

}

MyString::MyString(const size_t count, const char ch)
{
    if (NULL != ch)
    {
        clength = count;
        cdata = new char[clength + 1];
        for (size_t i = 0; i<clength; i++)
        {
            cdata[i] = ch;
        }
        cdata[clength] = '\0';
    }

}

MyString::~MyString()
{
    delete[] cdata;
}

size_t MyString::length()
{
    return clength;
}

bool MyString::isEmpty()
{
    return clength==0;
}

const char* MyString::c_str()
{
    return cdata;
}

ostream& operator <<(ostream& out, const MyString& str)
{
    if(NULL != str.cdata)
    {
        out << str.cdata;
    }
    return out;
}

istream& operator >>(istream& in, MyString& str)
{
    char temp[100];
    if(in >> temp)
    {
        delete[] str.cdata;
        str.clength = strlen(temp);
        str.cdata = new char[str.clength + 1];
        strcpy(str.cdata, temp);
    }
    return in;
}

MyString operator +(const MyString& one, const MyString& another)
{
    MyString result;
    result.clength = one.clength + another.clength;
    result.cdata = new char[result.clength + 1];
    strcpy(result.cdata, one.cdata);
    strcat(result.cdata, another.cdata);
    return result;
}

// compare operations
bool operator ==(const MyString& one, const MyString& anothor)
{
    return strcmp(one.cdata,anothor.cdata)==0;
}

bool operator !=(const MyString& one, const MyString& another)
{
    return strcmp(one.cdata,another.cdata) != 0;
}

bool operator <(const MyString& one, const MyString& another)
{
    return strcmp(one.cdata,another.cdata) < 0;
}

bool operator <=(const MyString& one, const MyString& another)
{
    return strcmp(one.cdata,another.cdata) <= 0;
}

bool operator >(const MyString& one, const MyString& another)
{
    return strcmp(one.cdata,another.cdata) > 0;
}

bool operator >=(const MyString& one, const MyString& another)
{
    return strcmp(one.cdata,another.cdata) >= 0;
}

char& MyString::operator[](const size_t index)
{
    if(index <0 || index >= clength)
    {
        throw "indexOutOfRange";
    }
    return cdata[index];
}

const char& MyString::operator[](const size_t index) const
{
    if(index <0 || index >= clength)
    {
        throw "indexOutOfRange";
    }
    return cdata[index];
}

MyString& MyString::operator=(const MyString& other)
{
    if(this == &other)
    {
        return *this;
    }

    if(clength < other.clength)
    {
        delete[] cdata;
        cdata = new char[other.clength + 1];
    }
    clength = other.clength;
    strcpy(cdata, other.cdata);
}

MyString& MyString::operator+=(const MyString& other)
{
    if(NULL == other)
    {
        return *this;
    }
    if (this == &other)
    {
        MyString copy(*this);
        return *this += copy;
    }
    clength += other.clength;
    char* oldData = cdata;
    cdata = new char[clength+1];
    strcpy(cdata, oldData);
    strcat(cdata, other.cdata);
    delete[] oldData;
    return *this;
}


// 成员操作函数
MyString MyString::substr(size_t pos, const size_t n)
{
    if(pos + n >= clength)
    {
        throw "IndexOutOfRange";
    }
    MyString result;
    result.clength = n;
    result.cdata = new char[result.clength + 1];
    for(size_t i = 0;i<n;i++)
    {
        result.cdata[i] = cdata[pos + i];
    }
    result.cdata[result.clength] = '\0';
    return result;
}

MyString& MyString::append(const MyString& other)
{
    *this += other;
    return *this;
}

MyString& MyString::insert(size_t pos, const MyString& other)
{
    if(pos<0 || pos>=clength)
    {
        throw "IndexOutOfRange";
    }

    char* oldData = cdata;
    clength += other.clength;
    cdata = new char[clength + 1];
    for (int i=0;i<pos;i++)
    {
        *(cdata + i) = *(oldData + i);
    }
    for (size_t i=pos;i<other.clength+pos;i++)
    {
        *(cdata+i) = *(other.cdata + i - pos);
    }
    for (size_t i=other.clength+pos;i<clength;i++)
    {
        *(cdata+i) = *(oldData + i - other.clength);
    }
    *(cdata+clength) = '\0';
    return *this;
}







