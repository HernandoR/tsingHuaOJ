#include<stdio.h>

int main(){
    short h1,h2,m1,m2,s1,s2;
    scanf("%hd:%hd:%hd %hd:%hd:%hd",&h1,&m1,&s1,&h2,&m2,&s2);
    int interval = ((h2-h1)*60+(m2-m1))*60+s2-s1;
    if (interval<0) interval=interval+86400;// seconds for one day
    printf("%d\n",interval);
    return 0;
}