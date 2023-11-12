#include<stdio.h>
#include<ctype.h>
int stack[40];
int top = -1;

void push(float x)
{
    stack[++top] = x;
}

float pop()
{
    return stack[top--];
}

int main()
{
    char exp[40];
    char *e;
    float n1,n2,n3,num;
    //printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("%.2f",pop());
    return 0;
}