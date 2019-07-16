#include <stdio.h>
#include <string.h>

#define textLimtit 4096

//获得文本，统计字母出现次数

int count[26];//字母统计数组

int main(){
    
    char text[textLimtit];//储存文本
    gets(text);

    for(int i =0;i < strlen(text);i++){
        if((text[i]>='A'&&text[i]<='Z')||(text[i]>='a'&&text[i]<='z')){//该自负为字母
            if(text[i]<='Z'){//大写字母
                count[text[i]-'A']++;//对应统计数++
            }else//小写字母
            {
                count[text[i]-'a']++;
            }
        }
        
    }
    for(int i =0;i <=25;i++){
        if(count[i]!=0){
        printf("%c: %d\n",i+'A',count[i]);
        }
    }
return 0;

}
