#include<cstdio>
using namespace std;

int main(){
int n;scanf("%d",&n);
int sum[1500000];
for(int a,b,i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    sum[i]=a+b;
}
for(int i=0;i<n;i++){
    printf("%d\n",sum[i]);}
return 0;

}