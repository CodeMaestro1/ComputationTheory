#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lambdalib.h"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void merge(int left[], int right[], int result[], int leftSize, int rightSize)
{

    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while((i < leftSize) && (j < rightSize))
    {
        if(left[i] <= right[j])
        {
            result[k] = left[i];
            i = i + 1;

        }
        else
        {
            result[k] = right[j];
            j = j + 1;

        }
        k = k + 1;
    }
    while(i < leftSize)
    {
        result[k] = left[i];
        i = i + 1;
        k = k + 1;
    }
    while(j < rightSize)
    {
        result[k] = right[j];
        j = j + 1;
        k = k + 1;
    }

}

void mergeSort(int arr[], int temp[], int size)
{

    int mid;
    int left;
    int right;
    int i;
    if(size <= 1)
    {
        return;

    }
    mid = size / 2;
    for(int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for(int i = 0; i < (size - mid); i++)
    {
        right[i] = arr[mid + i];
    }
    mergeSort(left, temp, mid);
    mergeSort(right, temp, size - mid);
    merge(left, right, arr, mid, size - mid);

}
int main()
{

    int arr[8];
    int temp[8];
    int i;
    arr[0] = 64;
    arr[1] = 34;
    arr[2] = 25;
    arr[3] = 12;
    arr[4] = 22;
    arr[5] = 11;
    arr[6] = 90;
    arr[7] = 1;
    writeStr("Original array: ");
    for(int i = 0; i < 8; i++)
    {
        writeInteger(arr[i]);
        writeStr(" ");
    }
    writeStr("\n");
    mergeSort(arr, temp, 8);
    writeStr("Sorted array: ");
    for(int i = 0; i < 8; i++)
    {
        writeInteger(arr[i]);
        writeStr(" ");
    }
    writeStr("\n");

    return 0;
}
