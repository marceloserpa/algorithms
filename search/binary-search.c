#include <stdio.h>

int binarySearch(int numbers[], int n, int length){
    int low = 0,
        high = length,
        mid = 0;    
    int times = 0;        
    while(numbers[mid] != n){
        mid = (int) (high + low) / 2;
        if(low == mid || high == mid) return -1;       
        if(numbers[mid] < n){
            low = mid;
        } else if(numbers[mid] > n){
            high = mid;
        }
        times++;
    }
    printf("cycles: %d", times);
    return mid;
}

void main(){
    int numbers[100000];
    for(int i =0;i<100000;i++){
        numbers[i] = i;
    }
           
    int index = binarySearch(numbers, 60, 100000);    
    printf("\n index: %d \n\n",index);

    index = binarySearch(numbers, 98523, 100000);    
    printf("\n index: %d \n\n",index);    

    index = binarySearch(numbers, 1, 100000);    
    printf("\n index: %d \n\n",index);    

    index = binarySearch(numbers, 0, 100000);    
    printf("\n index: %d \n\n",index);        
}