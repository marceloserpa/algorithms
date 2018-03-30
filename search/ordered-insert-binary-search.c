#include <stdio.h>

int length = -1;
int numbers[100];

void orderedInsert(int number){
    printf("%d\n", number);

    // verify if is first
    if(length == -1) {
        numbers[++length] = number;
        return;
    } 
    // find ideal place to insert
    int index = findIndexToInsert(number, length);
    
    // shift to left all elements greater than number
    int j = length + 1;
    while(j != index){
        numbers[j] = numbers[j-1];
        j--;
    }
    // insert number
    numbers[index] = number;
    length++;
}


int findIndexToInsert(int n, int length){
    int low = 0,
        high = length,
        mid = 0;    
    int times = 0;    
    if(numbers[low] > n) return low;
    else if(numbers[high-1] < n) return high+1;
    
    int index = -1;
    while(index < 0){
        mid = (int) (high + low) / 2; 
        if(n >= numbers[mid-1] && n <= numbers[mid]){
            index = mid;        
        } else {
            if(numbers[mid] < n){
                low = mid;
            } else if(numbers[mid] > n){
                high = mid;
            }
        }
        printf("low = %d - high = %d - mid = %d\n", low, high, mid);
        times++;
    }
    printf("cycles: %d\n", times);
    return index;
}

void delete(int n){
    int index = findIndex(numbers, n, length);
    if(index != -1){
        // shift to right all elements 
        for(int i = index; i < length; i++){
            numbers[i] = numbers[i+1];
        }
        length = length -1;
        printf("index found: %d", index);
    }
}

int findIndex(int numbers[], int n, int length){
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

void print(){
    printf("\nPRINT ALL ELEMENTS\n");
    for(int i =0; i <= length; i++){
        printf("%d\n", numbers[i]);
    }
    printf("------");  
}

void main(){    
    orderedInsert(3);
    orderedInsert(2);
    orderedInsert(1);
    orderedInsert(32);
    orderedInsert(45);   
    orderedInsert(55);
    orderedInsert(60);
    orderedInsert(75);
    orderedInsert(52);
    orderedInsert(44);
    orderedInsert(13);
    orderedInsert(59);
    orderedInsert(44);   
    orderedInsert(1);   

    print();

    delete(32);

    print();
}