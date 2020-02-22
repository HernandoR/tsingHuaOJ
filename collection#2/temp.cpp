#include <cstring>
#include <iostream>
//#include <vector>
using namespace std;

/*
2020.2.20
混编data选取最小值，在小值并行时选取小值错误。
应当使用男女配对的方法，保留图和位置。
*/
int **data; //data store
int **datacopy;
int row = 0;
typedef struct edge
{
    int people;
    int time;
    int task;
} edge;

void readData2(edge *edgeData)
{

    memset(edgeData, 0, row * row * sizeof(edge));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            edgeData[i * row + j].people = i;
            scanf("%d", &(edgeData[i * row + j].time));
            edgeData[i * row + j].task = j;
        }
    }
}

void QuickSort_LowFront(edge a[], int numsize)
{
    int i = 0, j = numsize - 1;
    edge val = a[0];
    if (numsize > 1)
    {
        while (i < j)
        {
            for (; i < j; j--)
                if (a[j].time < val.time)
                {
                    a[i++] = a[j];
                    break;
                }
            for (; i < j; i++)
                if (a[i].time > val.time)
                {
                    a[j--] = a[i];
                    break;
                }
        }
        a[i] = val;
        QuickSort_LowFront(a, i);
        QuickSort_LowFront(a + i + 1, numsize - i - 1);
    }
}

int arrange(edge edgeData[][], int row)
{
    int *PeopleDoneList = new int[row];
    int *TaskDoneList = new int[row];
    memset(PeopleDoneList, 0, row * sizeof(int));
    memset(TaskDoneList, 0, row * sizeof(int));
    int doneNum = 0;
    int totalTime = 0;
    for (int i = 0; doneNum < row; i++)
    {
        if (PeopleDoneList[edgeData[i].people] == 0 && TaskDoneList[edgeData[i].task] == 0)
        {
            PeopleDoneList[edgeData[i].people] = 1;
            TaskDoneList[edgeData[i].task] = 1;
            totalTime += edgeData[i].time;
            doneNum++;
        }
    }
    return totalTime;
}

int main()
{
    edge *edgeData;
    cin >> row;
    edgeData = new edge[row * row];
    readData2(edgeData);
    QuickSort_LowFront(edgeData, row * row);
    int time = arrange(edgeData, row);
    printf("%d", time);
}