#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define MAX 50

char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

int isEmpty(){
        if(top==-1)
                return 1;
        else
                return 0;
}
int white_space(char symbol){
        if( symbol == ' ')
                return 1;
        else
                return 0;
}
int priority(char symbol){
        switch(symbol){
            case '(':
                return 0;
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
            case '%':
                return 2;
            case '^':
                return 3;
            default :
                return 0;
        }
}

void push(long int symbol){
    if(top>MAX)
        exit(1);
    stack[++top]=symbol;
}

int pop(){
    if(isEmpty())
        exit(1);
        return (stack[top--]);
}

void infix_to_postfix(char *infix){
        unsigned int i,p=0;
        char next;
        char symbol;

        for(i=0;i<strlen(infix);i++)
        {
                symbol=infix[i];
                if(!white_space(symbol))
                {
                        switch(symbol)
                        {
                        case '(':
                                push(symbol);
                                break;
                        case ')':
                                while((next=pop())!='(')
                                        postfix[p++] = next;
                                break;
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '%':
                        case '^':
                                while( !isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
                                        postfix[p++]=pop();
                                push(symbol);
                                break;
                        default:
                             postfix[p++]=symbol;
                        }
                }
        }
        while(!isEmpty( ))
                postfix[p++]=pop();
        postfix[p]='\0';
}

int main(){
        long int value;
        top=-1;
        printf("Enter infix : ");
        fgets(infix, MAX, stdin);
        infix_to_postfix(infix);
        printf("Postfix : %s",postfix);

        return 0;

}
