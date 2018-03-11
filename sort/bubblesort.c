#include <stdio.h>

int main(){
    int numbers[5] = {12,8,7,5,2};
    int temp = 0;
    int length = sizeof(numbers) / sizeof(numbers[0]);  
    printf("length: %d ", length)  ;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i; j++){
            if(numbers[j] > numbers[j+1]){
                temp = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = temp;
            }
        }        
    }    

    for(int i = 0; i < length; i++){
        printf("\n%d", numbers[i]);
    }
    return 0;
}