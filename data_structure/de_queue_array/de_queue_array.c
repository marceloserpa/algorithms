
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int queue[MAXSIZE];

int head = -1;
int tail = -1;
int size = 0;

int hasCapacity(){
  if(tail < MAXSIZE-1){
    return 1;
  } else {
    return 0;
  }
}

void insertRight(int number){
  if(hasCapacity() == 1){
    if(head < 0) head++;
    queue[++tail] = number;
    size++;
  } else {
      printf("the max is: %d and current size is: %d \n", MAXSIZE, size);
  }
}

void insertLeft(int number){
  if(hasCapacity() == 1){
    if(head <= 0) head = MAXSIZE;
    queue[--head] = number;
    ++size;
  } else {
      printf("the max is: %d and current size is: %d \n", MAXSIZE, size);
  }
}

void deleteRight(){
  queue[tail--] = 0;
  size--;
}

void deleteLeft(){
  queue[head++] = 0;
  size--;
}

int peek(){
  return queue[head];
}

int main(){

  insertRight(7);
  printf("head: %d size: %d\n", peek(), size);

  insertRight(12);
  printf("head: %d size: %d\n", peek(), size);

  deleteRight();
  printf("head: %d size: %d\n", peek(), size);

  insertLeft(5);
  printf("head: %d size: %d\n", peek(), size);


  for(int i =0; i < MAXSIZE; i++){
    printf("%d\n", queue[i]);
  }

}
