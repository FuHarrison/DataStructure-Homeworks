#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

#define STACKSIZE 50

struct stack{
    int top;
    char items [STACKSIZE];
};

struct stack s;

bool isEmpty(int top){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(int top){
    if(top == STACKSIZE-1){
        return true;
    }
    else{
        return false;
    }
}

void push(float n){
    if(s.top < STACKSIZE-1){
        s.top++;
        s.items[s.top] = n;
    }
}

char pop(){
    if(s.top >= 0){
        char k = s.items[s.top];
        s.top--;
        return k;
    }
}

int prec(char o){
    switch(o)
    {
        case '+': case '-':
        {
            return 1;
        }
        case '*': case '/':
        {
            return 2;
        }
    }
}

void reverse(char *string){
    int length = strlen(string);
    int middle = length / 2;
    char temp;
    for(int i = 0;i < middle;i++){
        temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
}



int main(){
    s.top = -1;
    char exp[STACKSIZE];
    char* e;
    scanf("%s",exp);
    reverse(exp);
    e = exp;
    char output[STACKSIZE];
    int i = 0;
    while(*e != '\0'){
        if(isdigit(*e)){
           output[i++] = *e;
        }
        else{
            if((isEmpty(s.top)) || (prec(*e) >= prec(s.items[s.top]))){
                push(*e);
            }
            else{
                while(prec(*e) < prec(s.items[s.top]) && !(isEmpty(s.top))){
                    output[i++] = pop();
                }
                push(*e);
            }
        }
        e++;
    }
    while(!(isEmpty(s.top))){
        output[i++] = pop();
    }
    reverse(output);
    printf("%s",output);
}