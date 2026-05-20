//Optimized Bubble_Sort using 'swapped' variable

#include<stdio.h>

void bubbleSort(int a[],int n){
    for (int i = 0; i < n-1 ; i++){
        int swapped = 0;
        for (int j = 0; j < n-i-1 ; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0)
           { break;} 
    }
}

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter an array: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    bubbleSort(a, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}