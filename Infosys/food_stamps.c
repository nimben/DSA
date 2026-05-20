#include <stdio.h>

int main() {

    int n, m;

    printf("Enter number of foods: ");
    scanf("%d", &n);

    printf("Enter max meals: ");
    scanf("%d", &m);

    int v[n], d[n];

    // Input initial tastiness
    printf("Enter v values:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Input decrease values
    printf("Enter d values:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    int total = 0;

    // Current taste values
    int current[n];

    // Initially current taste = v
    for(int i = 0; i < n; i++) {
        current[i] = v[i];
    }

    // Buy m meals
    for(int meal = 0; meal < m; meal++) {

        int maxIndex = 0;

        // Find food with maximum current taste
        for(int i = 1; i < n; i++) {

            if(current[i] > current[maxIndex]) {
                maxIndex = i;
            }
        }

        // Add maximum taste
        total += current[maxIndex];

        // Reduce taste for next time
        current[maxIndex] -= d[maxIndex];
    }

    printf("Maximum taste points = %d", total);

    return 0;
}