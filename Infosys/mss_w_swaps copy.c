/*Given an array a of length n and an integer k. You must perform the following operation exactly k times:
choose two indices i, j and swap (ai, aj).
Find the maximum possible MSS (maximum subarray sum) after performing the above operation exactly
k times.*/

#include<stdio.h>
int first_max = -1000000;
// Kadence's Algorithm
int kadence(int a,int n){

}

void swap(){

}


void solve(int a[],int n, int k){
    int curr_mss = kadence(a, n);
    if(curr_mss > first_max){
        first_max = curr_mss;
    }

}

int main(){
    int n,k;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);
    int a[n];
    printf("Enter an array: ");
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }
    solve(a, n, k);
}