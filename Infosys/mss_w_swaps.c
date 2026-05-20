/*Given an array a of length n and an integer k. You must perform the following operation exactly k times:
choose two indices i, j and swap (ai, aj).
Find the maximum possible MSS (maximum subarray sum) after performing the above operation exactly
k times.*/

#include <stdio.h>

int maxAnswer = -1000000;

// Kadane's Algorithm
int kadane(int a[], int n){

    int current = a[0];
    int maximum = a[0];

    for(int i = 1; i < n; i++){

        if(current + a[i] > a[i]){
            current = current + a[i];
        }
        else{
            current = a[i];
        }

        if(current > maximum){
            maximum = current;
        }
    }

    return maximum;
}

// Swap function
void swap(int *x, int *y){

    int temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function
void solve(int a[], int n, int k){

    // Calculate MSS for current arrangement
    int currentMSS = kadane(a, n);

    if(currentMSS > maxAnswer){
        maxAnswer = currentMSS;
    }

    // No swaps left
    if(k == 0){
        return;
    }

    // Try every possible swap
    for(int i = 0; i < n; i++){

        for(int j = i + 1; j < n; j++){

            // Swap
            swap(&a[i], &a[j]);

            // Recurse with one less swap
            solve(a, n, k - 1);

            // Undo swap
            swap(&a[i], &a[j]);
        }
    }
}

int main(){

    int n, k;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter swaps: ");
    scanf("%d", &k);

    int a[n];

    printf("Enter array:\n");

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    solve(a, n, k);

    printf("Maximum MSS = %d", maxAnswer);

    return 0;
}