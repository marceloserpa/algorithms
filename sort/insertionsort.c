#include <stdio.h>

int main(){
    printf("Insertion Sort\n");
    int numbers[5] = {12,8,7,5,2};
    int length = sizeof(numbers) / sizeof(numbers[0]);  
    int current = 0;
    int j = 0;

    for(int i = 0; i < length; i++){
        current = numbers[i];
        j = i - 1;
        while(j >= 0 && numbers[j] > current){
            numbers[j+1] = numbers[j];
            j--;
        }
        numbers[j+1] = current;

    }

    for(int i =0; i < length; i++){
                printf("%d\n", numbers[i]);
    }

    printf("\n");
    return 0;
}