#include <stdio.h>

int length = -1;
int numbers[100];

void orderedInsert(int number){
    // if first
    if(length == -1) {
        numbers[++length] = number;
        return;
    } 
    // find index to insert
    int index = length + 1;
    for(int i = 0; i < length; i++){
        if(numbers[i] > number){
            index = i;
            break;
        }
    }

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


void main(){
    orderedInsert(3);
    orderedInsert(7);
    orderedInsert(20);
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

    for(int i =0; i <= length; i++){
        printf("%d\n", numbers[i]);
    }

    printf("------");
}