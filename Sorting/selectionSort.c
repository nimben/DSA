#include<stdio.h>

void bubbleSort(int a[],int n){
    for (int i = 0; i < n ; i++){
        int k = 0;
        for (int j = i + 1; j < n ; j++){
            if(a[i]>a[j]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
            k++;
        }
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