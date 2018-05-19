
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int queue[MAXSIZE];

int head = -1;
int tail = -1;
int size = -1;

int hasCapacity(){
  if((tail - head) < (MAXSIZE-1)){
    return 1;
  } else {
    return 0;
  }
}

void enqueue(int value){
  if(hasCapacity() == 1){
    if(head < 0){
      head++;
    }
    size++;
    if(tail == MAXSIZE-1){
      tail = -1;
    }
    tail++;
    queue[tail] = value;
  } else {
    printf("the max is: %d and current size is: %d \n", MAXSIZE, size);
  }

}

int dequeue(){
  size--;
  return queue[head++];
}

int peek(){
  return queue[head];
}

void printQueue(){
  for(int i =0; i < MAXSIZE; i++){
    printf("%d,", queue[i]);
  }
}

int main(){

  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);

  dequeue();
  printf("%d\n", peek());

  dequeue();
  printf("%d\n", peek());

  dequeue();
  printf("%d\n", peek());

  enqueue(6);
  printf("%d\n", peek());

  enqueue(6);
  printf("%d\n", peek());

  printQueue();

  printf("\n\n\n");

}
