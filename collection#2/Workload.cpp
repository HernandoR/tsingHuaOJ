#include <cstring>
#include <iostream>
//#include <vector>
using namespace std;

int **data; //data store
int **datacopy;

int *solution;

int row = 0;
int sum = 160001;

typedef struct edge
{
    int people;
    int time;
    int task;
} edge;
/*
void readData()
{                          //读取数据（方阵），{指针data,行数}
    data = new int *[row]; //创建行
    memset(data, 0, sizeof(data));
    for (int i = 0; i < row; i++)
    {
        data[i] = new int[row]; //创建列
        for (int j = 0; j < row; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }
    datacopy = new int *[row]; //创建行
    memset(datacopy, 0, sizeof(datacopy));
    for (int i = 0; i < row; i++)
    {
        data[i] = new int[row]; //创建列
        for (int j = 0; j < row; j++)
        {
            datacopy[i][j] = data[i][j];
        }
    }
}
*/
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

int arrange(edge edgeData[], int row)
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

//数组记录已安排任务，递归安排未安排任务（n!)
/*
void search(int serialNum)
{
    if (serialNum == row)
    {

        int temp = 0;
        for (int i = 0; i < row; i++)
        {
            temp = temp + data[i][solution[i]];
        }
        if (temp < sum)
            sum = temp;
        temp = 0;
    }
    for (int i = 0; i < row; i++)
    {
        int flag = 1;
        solution[serialNum] = i;
        for (int j = 0; j < serialNum; j++)
        {
            if (solution[j] == solution[serialNum])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            search(serialNum + 1);
    }
}
*/
int experiment()
{
    edge *edgeData;
    cin >> row;
    edgeData = new edge[row * row];
    readData2(edgeData);
    QuickSort_LowFront(edgeData, row * row);
    int time = arrange(edgeData, row);
    printf("%d", time);
    return time;
}

int main()
{
    freopen("testData.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    time_t begin, end;
    double ret;
    begin = clock();

    experiment();

    end = clock();
    ret = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("\n runtime:%f", ret);

    //fclose(fp);
    fclose(stdin);
    fclose(stdout);
}
