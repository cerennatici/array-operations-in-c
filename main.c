#include <stdio.h>
#include <stdlib.h>

// Cift sayilarin karelerini toplar
void evenSquaresSum(int array[], int size)
{
    int total = 0;
    printf("Even numbers and their squares:\n");
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            printf("%d ^ 2 = %d\n", array[i], array[i] * array[i]);
            total += array[i] * array[i];
        }
    }
    printf("Total of squares: %d\n", total);
}

// Diziyi terse cevirir
void reverseArray(int array[], int size)
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
    printf("Reversed array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Diziyi siralar (buyukten kucuge)
void sortArray(int array[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("Sorted array (desc): ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// En buyuk ve en kucuk sayiyi bulur
void findMinMax(int array[], int size)
{
    int min = array[0], max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min) min = array[i];
        if (array[i] > max) max = array[i];
    }
    printf("Min: %d, Max: %d\n", min, max);
}

// Ortalama hesaplar
void averageArray(int array[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += array[i];
    }
    float average = (float)total / size;
    printf("Average: %.2f\n", average);
}

// Asal sayilari sayar
int isPrime(int n)
{
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void countPrimes(int array[], int size) {
    int count = 0;
    printf("Prime numbers: ");
    for (int i = 0; i < size; i++) {
        if (isPrime(array[i])) {
            printf("%d ", array[i]);
            count++;
        }
    }
    printf("\nPrime numbers count: %d\n", count);
}

// Kullanici tarafindan girilen sayi dizide var mi?
void searchValue(int array[], int size, int value)
{
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            printf("Value %d found at index %d\n", value, i);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Value %d not found in array\n", value);
    }
}

// Eleman frekanslari
void frequencyCount(int array[], int size)
{
    int frequency[1000] = {0};
    for (int i = 0; i < size; i++)
    {
        frequency[array[i]]++;
    }
    printf("Frequencies:\n");
    for (int i = 0; i < 1000; i++)
    {
        if (frequency[i] > 1)
        {
            printf("%d appears %d times\n", i, frequency[i]);
        }
    }
}

int main()
{
    int choice, size;

    printf("Array size: ");
    scanf("%d", &size);

    int *array = (int *) malloc(size * sizeof(int));
    if (array == NULL)
    {
        printf("Memory error!\n");
        return 1;
    }

    // Dizi elemanlarini al
    for (int i = 0; i < size; i++)
    {
        printf("%d. number: ", i + 1);
        scanf("%d", &array[i]);
    }

    while (1)
    {
        // Menu
        printf("\n-- MENU --\n");
        printf("1. Even numbers squares sum\n");
        printf("2. Reverse array\n");
        printf("3. Sort array (desc)\n");
        printf("4. Find max & min\n");
        printf("5. Calculate average\n");
        printf("6. Count prime numbers\n");
        printf("7. Search a value\n");
        printf("8. Count duplicates\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            evenSquaresSum(array, size);
            break;
        case 2:
            reverseArray(array, size);
            break;
        case 3:
            sortArray(array, size);
            break;
        case 4:
            findMinMax(array, size);
            break;
        case 5:
            averageArray(array, size);
            break;
        case 6:
            countPrimes(array, size);
            break;
        case 7:
        {
            int value;
            printf("Enter value to search: ");
            scanf("%d", &value);
            searchValue(array, size, value);
            break;
        }
        case 8:
            frequencyCount(array, size);
            break;
        case 0:
            printf("Exiting...\n");
            free(array);
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
