/*BCSL404 Program 10*/
/*10.sort a given set of n integer elements using Quick Sort method and compute its time complexity. Run the program for varied values of n> 5000 and record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Pivot element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate random numbers
void generateRandomNumbers(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000; // Generate random numbers between 0 and 99999
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n); // Read the number of elements from the user

    if (n <= 5000)
    {
        printf("Please enter a value greater than 5000\n");
        return 1; // Exit if the number of elements is not greater than 5000
    }

    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    // Generate random numbers and store them in the array
    generateRandomNumbers(arr, n);

    // Measure the time taken to sort the array
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    // Calculate and print the time taken to sort the array
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    // Free the allocated memory
    free(arr);
    return 0;
}
/*import matplotlib.pyplot as plt

# Example data collected
n_values = [10000, 20000, 30000, 35000, 50000]
time_taken = [0.0000, 0.015000, 0.011000, 0.003000, 0.015000]  # replace with actual times recorded

plt.plot(n_values, time_taken, marker='o')
plt.title('Quick Sort Time Complexity')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time taken (seconds)')
plt.grid(True)
plt.show()*/