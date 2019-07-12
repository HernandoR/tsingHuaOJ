#include <stdio.h>
int main(){
    long a,b;
    char op;
    long long c;
    scanf("%ld %c %ld",&a,&op,&b);
    switch(op){
        case'+':c=a+b;break;
        case'-':c=a-b;break;
        case'*':c=a*b;
    }
    printf("%lld\n",c);
    return 0;
}
