#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace ::std;

typedef struct
{
    double Tc;
    double Pc;
    double Vc;
    double Zc;
    double w;

} compMess;

vector input1()
{
    int i = 0;
    cout << "输入物质总数";
    cin >> i;
    vector<compMess> dataSheet(i);
    for (int k = 0; k < i, k++)
    {
        printf("输入Tc%d,Pc%d,Vc%d,Zc%d,w%d,以空格区分\n", k, k, k, k, k);
        cin >>
            dataSheet[k].Tc >>
            dataSheet[k].Pc >> dataSheet[k].Vc >> dataSheet[k].Zc >> dataSheet[k].w;
    }
    printf("输入内容 Tc,Pc,Vc,Zc,w，\n"
    for (int k = 0; k < i, k++)
    {
        
        cout >>k" ">>
            dataSheet[k].Tc" " >>
            dataSheet[k].Pc" " >> dataSheet[k].Vc" " >> dataSheet[k].Zc" " >> dataSheet[k].w>>endl;
    }
    return dataSheet;
}

vector input2(){
    int k = 0;
    cout << "输入物质总数";
    cin >> k;
    vector<vector<int> (i)> B(i);
    for (int i = 0; i < k, i++)
    {
        for (int j = 0;j<k,j++){
            printf("输入b%d%d", j, j);
        cin >>
        }
    }
}

void calculate(vector data)
{
    int comNum = data.size();
    double Bm = 0;
    for (int i = 0; i < comNum;i++){
        for (int j = 0; j < comNum;j++){
            Bm+=
        }
    }
}

int main
{
    freopen("testData.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    time_t begin, end;
    double ret;
    begin = clock();

    data=input();
    calculate(data);

    end = clock();
    ret = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("\n runtime:%f", ret);

    //fclose(fp);
    fclose(stdin);
    fclose(stdout);
}