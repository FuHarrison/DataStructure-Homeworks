#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

#define STACKSIZE 50

struct stack{
    int top;
    float items [STACKSIZE];
};

struct stack s;

// bool isEmpty(int top){
//     if(top == -1){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// bool isFull(int top){
//     if(top == STACKSIZE-1){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

void push(float n){
    if(s.top < STACKSIZE-1){
        s.top++;
        s.items[s.top] = n;
    }
}

float pop(){
    if(s.top >= 0){
        float k = s.items[s.top];
        s.top--;
        return k;
    }
}


int main(){
    s.top = -1;
    char exp[50];
    char* e;
    scanf("%s",exp);
    e = exp;
    while(*e != '\0'){
        if(isdigit(*e)){
           push(*e - 48);
        }
        else{
            float n2 = pop();
            float n1 = pop();
            float result;
            switch(*e)
            {
                case '+':
                {
                    result = n1 + n2;
                    break;
                }
                case '-':
                {
                    result = n1 - n2;
                    break;
                }case '*':
                {
                    result = n1 * n2;
                    break;
                }case '/':
                {
                    result = n1 / n2;
                    break;
                }
            }
            push(result);
        }
        e++;
    }
    printf("%.2f",pop());
}
