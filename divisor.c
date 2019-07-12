#include <stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int i=1;
    while(i){
        i=a%b;
        a=b;
        b=i;
    }
    printf("%d\n",a);
    return 0;
}