#include <stdio.h>

int main(){
    printf("Selection Sort");
    int numbers[5] = {12,8,7,5,2};
    int temp = 0;
    int minIndex = 0;

    int length = sizeof(numbers) / sizeof(numbers[0]);  
    printf("length: %d ", length);
    for(int i = 0; i < length; i++){
        minIndex = i;
        for(int j = i; j < length; j++){
            if(numbers[j] < numbers[minIndex])
                minIndex = j;
        }  
        temp = numbers[i];
        numbers[i] = numbers[minIndex];
        numbers[minIndex] = temp;
    }    

    for(int i = 0; i < length; i++){
        printf("\n%d", numbers[i]);
    }
    return 0;
}