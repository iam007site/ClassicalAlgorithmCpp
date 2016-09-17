#include <iostream>
#define SBOUNDARY 2000
#define BOARDSIZE 3
#define SUCCESSSTATUS 8
using namespace std;

class WellGame
{
public:
    static void run()
    {
        // 记录3行3列及两个对角线的和的情况
        int status[SUCCESSSTATUS];

        // 每一个输入都单独进行处理，且后续没有对棋盘进行遍历，因此只需要使用一个[3][
        int input[SBOUNDARY][BOARDSIZE][BOARDSIZE];
        int result[SBOUNDARY];

        int s;
        char ch;
        int xCount=0;
        int oCount=0;

        cin >> s;
        // 对输入进行统计，以判定棋盘状态
        for (int index=0; index<s; index++)
        {
            xCount = 0;
            oCount = 0;
            for(int i=0; i<SUCCESSSTATUS; i++)
            {
                status[i] = 0;
            }

            for(int i=0; i<BOARDSIZE; i++)
            {
                for(int j=0; j<BOARDSIZE; j++)
                {
                    cin >> ch;
                    if(ch == 'X')
                    {
                        input[index][i][j] = 1;
                        xCount++;
                    }
                    else if (ch == 'O')
                    {
                        input[index][i][j] = 4;
                        oCount++;
                    }
                    else if(ch == '_')
                    {
                        input[index][i][j] = 0;
                    }

                    if (i==0)
                    {
                        status[0] += input[index][i][j];
                    }
                    else if(i == 1)
                    {
                        status[1] += input[index][i][j];
                    }
                    else if(i ==2)
                    {
                        status[2] += input[index][i][j];
                    }

                    if(j == 0)
                    {
                        status[3] += input[index][i][j];
                    }
                    else if(j == 1)
                    {
                        status[4] += input[index][i][j];
                    }
                    else if(j == 2)
                    {
                        status[5] += input[index][i][j];
                    }

                    if(i == j)
                    {
                        status[6] += input[index][i][j];
                    }
                    else if(i+j == 2)
                    {
                        status[7] += input[index][i][j];
                    }
                }
            }

             // 对当前输入的棋局进行判断
            if (xCount < oCount)
            {
                // 非法状态
                result[index] = -1;
            }
            else
            {
                int i = 0;
                for (; i<SUCCESSSTATUS; i++)
                {
                    if(status[i] == 3)
                    {
                        // x胜；使用3标记为x获胜--代表存在3个连续的1
                        result[index] = 3;
                        break;
                    }
                    else if(status[i] == 12)
                    {
                        // o胜；使用12标记o获胜--代表存在3个连续的4
                        result[index] = 12;
                        break;
                    }
                    else if(status[i] == 2 && xCount == oCount)
                    {
                        // 出现两个连续的x且下一步该x走
                        // next x胜
                        result[index] = 4;
                        break;
                    }
                    else if(status[index] == 8 && xCount==oCount+1)
                    {
                        // 出现两个连续的o且下一步该o走
                        // next o胜
                        result[index] = 13;
                        break;
                    }
                }

                if(i == 8 && xCount+oCount == 9)
                {
                    // 如果未出现上述胜负情况，那么判断是否平局
                    // 棋盘下满，平局;平局不能将值设为result[]的初始默认值0
                    result[index] == 1;
                }
            }

        }

        for(int i=0; i<s; i++)
        {
            if(result[i] == -1)
            {
                cout<<"Invalid"<<endl;
            }
            else if(result[i] == 3)
            {
                cout<<"X win"<<endl;
            }
            else if(result[i] == 12)
            {
                cout<<"O win"<<endl;
            }
            else if(result[i] == 4 || result[i] == 13)
            {
                cout<<"Next win"<<endl;
            }
            else if(result[i] == 1)
            {
                cout<<"Draw"<<endl;
            }
            else
            {
                cout<<"Next cannot win"<<endl;
            }
        }

    }
};
