
#include <stdio.h>
#include <stdlib.h>

int top = -1;
int max = 10;

void push(int stack[], int number){
  if(top < max){
    top++;
    stack[top] = number;
  } else {
    printf("stack is full");
  }
}

int peek(int stack[]){
  if(top < 0){
    printf("stack is empty");
    return -1;
  }
  return stack[top];
}

int pop(int stack[]){
  if(top < 0){
    printf("stack is empty");
    return -1;
  }
  int value = stack[top];
  top--;
  return value;
}

int main(){
    int stack[max];

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("----------\n\n");
    int topValue = peek(stack);
    printf("top value = %d\n\n", topValue);

    topValue = pop(stack);
    printf("top value = %d\n\n", topValue);

    topValue = pop(stack);
    printf("top value = %d\n\n", topValue);

    topValue = peek(stack);
    printf("top value = %d\n\n", topValue);

    topValue = pop(stack);
    printf("top value = %d\n\n", topValue);

    topValue = pop(stack);
    printf("top value = %d\n\n", topValue);
            
    printf("----------");
}
