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


