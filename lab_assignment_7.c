/*
Lindberg Gay
COP 3205 "Lab 7"
*/

//#include <iostream>
#include <stdio.h>
#include <stdlib.h >

int total_swaps = 0;

void copyArray(int tmp_arr[], int arr[], int n) {
    for (int i = 0; i < n; i++) {
        tmp_arr[i] = arr[i];
    }
}

// Function to perform Bubble Sort and count swaps
void bubbleSort(int arr[], int n, int swaps[]) {

    int i, j, temp;
    total_swaps = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
                total_swaps += 1;
            }
        }
    }
}

// Function to perform Selection Sort and count swaps
void selectionSort(int arr[], int n, int swaps[]) {

    int i, j, min_index, temp;
    total_swaps = 0;

    for (i = 0; i < n - 1; i++) {
        min_index = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            swaps[arr[i]]++;
            swaps[arr[min_index]]++;
            total_swaps += 1;
        }
    }
}

void main() {
    int array1[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int array2[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
    
    const int n1 = sizeof(array1) / sizeof(array1[0]);
    const int n2 = sizeof(array2) / sizeof(array2[0]);

    const int swapNumber = 100; // Assuming maximum value in the array is 99
    //int swaps1[swapNumber] = { 0 };
    //int swaps2[swapNumber] = { 0 };
    int swaps1[100] = { 0 };
    int swaps2[100] = { 0 };

    //int array1a[n1];
    //int array2a[n2];

    int array1a[9];
    int array2a[9];

    copyArray(array1a, array1, n1);
    copyArray(array2a, array2, n2);

    fflush(stdout); //clearing the buffer
    //system("PAUSE");
    
    printf("array1 bubble sort:\n");
    total_swaps = 0;
    bubbleSort(array1, n1, swaps1);
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    printf("Total: %d\n", total_swaps);

    
    printf("array2 bubble sort:\n");
    total_swaps = 0;
    bubbleSort(array2, n2, swaps2);
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    printf("Total: %d\n", total_swaps);
    
    /****Restting swaps indexes ********/    

    for (int i = 0; i < 100; i++) {
        swaps1[i] = 0;
        swaps2[i] = 0;
    }

    printf("array1 selection sort:\n");
    total_swaps = 0;
    selectionSort(array1a, n1, swaps1);
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", array1a[i], swaps1[array1a[i]]);
    }
    printf("Total: %d\n", total_swaps);

    printf("array2 selection sort:\n");
    total_swaps = 0;
    selectionSort(array2a, n2, swaps2);
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", array2a[i], swaps2[array2a[i]]);
    }
    printf("Total: %d\n", total_swaps);

    printf("\n");
}
