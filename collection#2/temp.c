#include<stdio.h>

int main()
{
    freopen("testData.txt", "w", stdout);
    printf("16\n");
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16;j++){
            if(j!=i)
            printf("9999 ");
            else
                printf("9998 ");
        }
        printf("\n");
    }
}