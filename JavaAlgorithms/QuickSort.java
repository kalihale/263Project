package JavaAlgorithms;/** ／(^ㅅ^)＼
 * @file JavaAlgorithms.Matrix.java
 * @author Kali Hale
 * @version 1.0
 *
 * Code from CS 310 taught by Dr. Craig Reinhart at California Lutheran University,
 * used with permission.
 */

import java.util.Random;

public class QuickSort {
    public static int quickSortPivotFirst(int[] list, int first, int last, int[] comparisons)
    {
        int count = 0;
        int pivot;
        if(first < last)
        {
            pivot = pivot(first, list, first, last, comparisons);
            quickSortPivotFirst(list, first, pivot - 1, comparisons);
            quickSortPivotFirst(list, pivot + 1, last, comparisons);
        }
        return count;
    }
    public static int quickSortPivotLast(int[] list, int first, int last, int[] comparisons)
    {
        int count = 0;
        int pivot;
        if(first < last)
        {
            pivot = pivot(last, list, first, last, comparisons);
            quickSortPivotLast(list, first, pivot - 1, comparisons);
            quickSortPivotLast(list, pivot + 1, last, comparisons);
        }
        return count;
    }
    public static int quickSortPivotRandom(int[] list, int first, int last, int[] comparisons)
    {
        Random random = new Random(13);
        int count = 0;
        int pivot;
        if(first < last)
        {
            pivot = pivot(random.nextInt(last - first) + first, list, first, last, comparisons);
            quickSortPivotRandom(list, first, pivot - 1, comparisons);
            quickSortPivotRandom(list, pivot + 1, last, comparisons);
        }
        return count;
    }
    public static int pivot(int pivot, int[] arr, int left, int right, int[] comparisons)
    {
        int temp = arr[right];
        arr[right] = arr[pivot];
        arr[pivot] = temp;
        int i = left;

        for(int j = i; j < right; j++)
        {
            comparisons[0]++;
            if(arr[j] < arr[right])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }

        }
        temp = arr[i];
        arr[i] = arr[right];
        arr[right] = temp;
        return i;
    }
}
