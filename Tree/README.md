#include<iostream>
using namespace std;
 
void counting_sort(int arr[], int n, int range)
{
    int count[range + 1], i;
    int output[n];
    memset(count, 0, sizeof(count));
 
    for(i = 0; i < n; i++)
        count[arr[i]]++;
 
    for(i = 1; i <= range; i++)
        count[i] += count[i-1];
 
    for(i = n-1; i >= 0; i--)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
 
    for(i = 0; i < n; i++)
        arr[i] = output[i];
}
 
int main()
{
    int arr[] = {4, 2, 10, 3, 1, 7, 9, 8, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int range = 10; // Phạm vi giá trị từ 0 đến 9
 
    cout << "Mang truoc khi sap xep: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    counting_sort(arr, n, range);
 
    cout << "\nMang sau khi sap xep: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}
                          
                          
