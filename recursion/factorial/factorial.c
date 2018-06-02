
#include <stdio.h>
#include <stdlib.h>

int factorial(int number){
  if(number == 0) return 1;
  return number * factorial(number-1);
}


int main(){
  int number = 5;
  int result = factorial(number);
  printf("Factorial of %d is %d\n\n", number, result);
}
