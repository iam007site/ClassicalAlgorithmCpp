#include  <iostream>
using namespace std;

int main1()
{
  int n,m;
  cin >> n >> m;
  int* num = new int[n];
  for(int i=0;i<n;i++)
  {
    cin >> num[i];
  }
  for (int i=0;i<m;i++)
  {
    int op,start,end;
    cin >> op >> start >> end;
    if(1 == op)
    {
      num[start-1] = end;
    }
    else if(2 == op)
    {
      int result = 0;
      for(int k =start-1;k<=end-1;k++)
      {
        result += num[k];
      }
      cout << result << endl;
    }
    else if(3 == op)
    {
      int max = num[start-1];
      for(int k=start-1;k<=end-1;k++)
      {
        max = max>num[k]?max:num[k];
      }
      cout << max << endl;
    }
  }

  return 0;
}
