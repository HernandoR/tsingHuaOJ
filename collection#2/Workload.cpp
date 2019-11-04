#include <iostream>
//#include <vector>
using namespace std;

int **data; //data store
int *solution;
int row;
int sum = 50001;
void readData()
{                          //读取数据（方阵），{指针data,行数}
    data = new int *[row]; //创建行
    for (int i = 0; i < row; i++)
    {
        data[i] = new int[row]; //创建列
        for (int j = 0; j < row; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }
}

//数组记录已安排任务，递归安排未安排任务（n!)
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

int main()
{
    cin >> row;
    readData();
    solution = new int[row];
    search(0);
    printf("%d", sum);
    return 0;
}
/*
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
}*/
