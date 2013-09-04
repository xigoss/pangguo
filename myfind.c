#include<stdio.h>
#include <string.h>
#include <stdlib.h>
char* my_find(char  input[],   char rule[])
{
    //write your code here
    int n,i,flag=0,end=0,k=0,m=0,flag1=0;
    char *p,*q;
    static char s[1000];
    while(*input && flag==0){
        for(n=0; input[n]==rule[n]||rule[n]=='?'
            ||rule[n]=='*'; n++){            
            if(rule[n] == '*'){
                if(!rule[n+1]){
                    flag1 = 1;
                    break;
                }
                flag = 1;
                p = input + n;
                q = rule + n + 1;
                while(*p){
                    for(m=0;p[m]==q[m];m++){
                        if(!q[m+1]){
                            end = p-input+m;
                        }
                        if(!p[m+1]){
                            break;
                        }
                    }
                    p++;                
                }
            }
                       
            if(!rule[n+1] || flag==1){
                if(flag == 0){
                    end = n;
                }
                if(k!=0){
                    s[k++] = ' ';                                    
                }                
                for(i=0; i<=end; i++){
                    s[k++] = input[i];
                }
                input = input+end;
            }
            if(!input[n+1]){
                break;
            }
        }

        if(flag1 == 1){
            for(i=0;input[i];i++){
                s[i] = input[i];
                k++;
            }
            break;
        }
        input++;
    }

    s[k] = '\0';
    return s;
}

//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{    
    //write your code here
    char *output;
    char *input1 = "breakfastfood";
    char *rule1 = "f*d";
    char *input2 = "abcadefg";
    char *rule2 = "a?c";
    char *input3 = "newsadfanewfdadsf";
    char *rule3 = "new";   
    output = my_find(input1, rule1);
    printf("%s\n", output);
    output = my_find(input2, rule2);
    printf("%s\n", output);
    output = my_find(input3, rule3);
    printf("%s\n", output);
    return 0;
}