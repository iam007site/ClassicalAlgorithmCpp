#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

class GameKNN
{
public:
    static void readTrainData(vector< vector<double> >& trainData,
                              vector<char> & trainLable,
                              int L,int M)
    {
        for (int i=0; i<M; i++)
        {
            vector<double> lineData;
            double tmp;
            for(int j=0; j<L; j++)
            {
                cin >> tmp;
                lineData.push_back(tmp);
            }
            trainData.push_back(lineData);

            char lable;
            cin >> lable;
            trainLable.push_back(lable);
        }

    }

    static void readTestData(vector<vector <double> >& testData,
                             int L,int N)
    {
        for(int i=0;i<N;i++)
        {
            vector<double> lineData;
            double tmp;
            for(int j=0;j<L;j++)
            {
                cin >> tmp;
                lineData.push_back(tmp);
            }
            testData.push_back(lineData);
        }
    }
    static void run()
    {
        int K,L,M,N;
        vector< vector<double> > trainData;
        vector< vector<double> > testData;
        vector<char> trainLable;
        vector<char> testLable;

        cin >> K >> L >> M >> N;
        readTrainData(trainData,trainLable, L,M);
        readTestData(testData,L,N);
    }
};
