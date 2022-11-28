#include <stdio.h>

#define ARR_MAX_LEN 50

/**
 * @brief    Swap the value of 2 numbers
 * 
 * @param n1 The first number 
 * @param n2 The second number
 */
void Swap(int* n1, int* n2);
/**
 * @brief         Sort the numbers in an array in ascending order
 * 
 * @param arr     The array to sort
 * @param arr_len The length of the array
 */
void Selection_Sort(int* arr, int arr_len);

int main()
{
    /* declaration of the array */  
    int arr[ARR_MAX_LEN];
    int arr_len;
    int arr_idx; /* Loop counter */
    int target; /* the number that want to find the first and the last index of that number in the array */
    int first_idx = -1; /* The first index where that target appear in the array */
    int last_idx = -1; /* The first index where that target appear in the array */

    printf("Enter the number of numbers in the array:\n");
    scanf("%d", &arr_len);
    printf("Enter an array containing number only:\n");
    for (arr_idx=0; arr_idx<arr_len; arr_idx++)
    {
        printf("Enter:\n");
        scanf("%d", &arr[arr_idx]);
    }
    printf ("Enter the target number: \n");
    scanf ("%d", &target);
    Selection_Sort(arr, arr_len);
    /* Check the first and the last index of the target in the sorted array */
    for (arr_idx=0; arr_idx<arr_len; arr_idx++)
    {
        if (target == arr[arr_idx])
        {
            if (-1 == first_idx)
            {
                first_idx = arr_idx;
            }
            else
            {
                last_idx = arr_idx;
            }
        }
        else
        {
            if (-1 != first_idx)
            {
                break;
            }
        }

    }
    printf("The first and the last index of the target number in the array are [%d, %d]\n", first_idx, last_idx);

    return 0;
}

void Swap(int* n1, int* n2)
{
    int temp;

    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void Selection_Sort(int* arr, int arr_len)
{
    int i; /* loop counter */
    int j; /* Loop counter*/
    int min_idx; /* the current index of the smallest number in the considered array */ 

    for (i = 0; i < arr_len - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < arr_len; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            Swap(&arr[i], &arr[min_idx]);
        }
    }
}
