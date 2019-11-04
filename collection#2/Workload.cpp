#include<iostream>
#include<vector>
using namespace std;

/* 
struct workerOnJob{
    int workerNum;
    int jobNum;
    int time;
};

workerOnJob 
*/
int** readData(int** data,int row){//读取数据（方阵），{指针data,行数}
    data = new int* [row];//创建行
    for(int i=0;i<row;i++){
        data[i] = new int*[row];//创建列
    }
    return data;
}

inline int miniMize (int* rowData,int num) {//找到一行中的最小值
    int miniData=0
    for(int i=1,i<num,i++){
        if(rowData[i]<rowData[miniData]) miniData=i;
    }
    return i;
}

handin(int** data,int* solution,int row){
    int time=0
    for(int i=0,i<row,i++)[
        time+=data[i][solution[i]];
    ]
    printf("%d",time);
}

bool checkout(int* data,int dataLength){
    for(int t,i=0;i<dataLength;i++){
        for(t=i+1;t<row,t++){
            
        }
    }
}

int main(){
    int row;
    int** data;//data store
    int* solution;
    cin >> row;
    readData(data,row);
    solution = new int* [row];
    for(int i=0;i<row;i++){
        solution[i]=miniMize(data[i],row);
    }
    if(checkout)
    handin(data,solution,row);
    return 0;
}