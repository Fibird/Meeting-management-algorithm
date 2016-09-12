#include <iostream>
#include <cstdlib>
#define N 11
using namespace std;

struct meeting
{
    int s;
    int e;
    int id;
};

int cmp(const void *a, const void *b)
{
    if ((*(meeting *)a).e != (*(meeting *)b).e)
        return (*(meeting *)a).e > (*(meeting *)b).e ? 1 : -1;
    else
        return (*(meeting *)a).s > (*(meeting *)b).s ? 1 : -1;
}

int main()
{
    meeting Meeting[N];
    int temp = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> Meeting[i].s >> Meeting[i].e;
        Meeting[i].id = i + 1;
    }

    qsort(Meeting, N, sizeof(Meeting[0]), cmp);

    cout << Meeting[0].id << endl;

    while (temp < N)
    {
        for (int j = temp + 1; j < N; j++)
        {
            if (Meeting[j].s > Meeting[temp].e)
            {
                cout << Meeting[j].id << endl;
                temp = j;
                break;
            }
        }
    }

    return 0;
}
