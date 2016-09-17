#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

class Q9706
{
public:
    static void test()
    {
        int lines;
        char ch;
        vector<int> out;
        cin >> lines;
        getchar();
        while(lines-- > 0)
        {
            int number[4] = {0};
            while((ch = getchar()) != '\n')
            {
                if(ch == '9')
                {
                    number[0]++;
                }
                if(ch == '7' && number[0]>number[1])
                {
                    number[1]++;
                }
                if(ch == '0' && number[1]>number[2])
                {
                    number[2]++;
                }
                if(ch == '6' && number[2]>number[3])
                {
                    number[3]++;
                }
            }
            out.push_back(number[3]);
        }

        for (vector<int>::const_iterator iter = out.begin();iter != out.end();iter++)
        {
            cout << *iter << endl;
        }
    }
};
