
/*
    Ví dụ:
    Với numerators = [5, 2, 5] và denominators = [6, 3, 4], 
    thì kết quả maxFraction(numerators, denominators) = 2. 
    5/4 là phân số lớn nhất, có chỉ số là 2.
    Đầu vào/Đầu ra:
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct arr_integer {
    int *arr;
    int size;
} arr_integer;

int maxFraction(arr_integer numerators, arr_integer denominators) {
    arr_integer a;
    int res = 0;
    for(int i = 1; i < a.size; i++) {
        if (numerators.arr[res]*denominators.arr[i] < numerators.arr[i]*denominators.arr[res]){
            res = i;
        }
    }
    return res;
}

int main() {
    arr_integer a;
    arr_integer array_1;
    arr_integer array_2;
    printf("Enter size between two array: ");
    scanf("%d", &a.size);
    printf("Enter elements array_1: ");
    for(int i=0; i<a.size; i++) {
        scanf("%d", &array_1.arr[i]);
    }
    printf("Enter elements array_2: ");
    for(int i=0; i<a.size; i++) {
        scanf("%d", array_2.arr[i]);
    }    

    // int result = maxFraction(array_1, array_2);
    printf("%d", maxFraction(array_1, array_2));

    return 0;
}