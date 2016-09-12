#include <iostream>
#include <cstdlib>
#define N 11
using namespace std;

typedef struct
{
    int s;
    int e;
    int id;
}meeting;

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

    for (int i = 0; i < N; i++)
    {
        cin >> Meeting[i].s >> Meeting[i].e;
        Meeting[i].id = i + 1;
    }

    qsort(Meeting, N, sizeof(Meeting[0]), cmp);

    cout << 1 << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (Meeting[j].s > Meeting[i].s)
            {
                cout << Meeting[j].id << endl;
                i = j;
                break;
            }
        }
    }

    return 0;
}
