// Bubble sort in C

#include <stdio.h>
// -2,  45, 0,  11, -9 -> 5 element
//  0   1   2   3    4
void bubbleSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++) // i bắt đầu từ đầu dãy // i = 0
    {
        for (int j = 0; j < n - i - 1; j++) // j bắt đầu từ đầu dãy // j = 0 // 1 // // 2 // 3 // 4
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main()
{
    int data[] = {-2, 45, 0, 11, -9};
    int n = sizeof(data) / sizeof(data[0]);
    bubbleSort(data, n);
    printArray(data, n);
}
