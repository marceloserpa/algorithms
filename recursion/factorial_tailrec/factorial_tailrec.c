
#include <stdio.h>
#include <stdlib.h>

/**
C compiler will not apply tail call optimization
this code is just for fun :D
*/
int factorialTail(int number, int acc){
  if(number == 0) return acc;
  factorialTail(number - 1, number * acc);
}

int factorial(int number){
  return factorialTail(number, 1);
}

int main(){
  int number = 5;
  int result = factorial(number);
  printf("Factorial of %d is %d\n\n", number, result);
}
