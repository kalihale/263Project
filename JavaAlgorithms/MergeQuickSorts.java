package JavaAlgorithms;

/** ／(^ㅅ^)＼
 * @file JavaAlgorithms.Matrix.java
 * @author Kali Hale
 * @version 1.0
 *
 * Code from CS 310 taught by Dr. Craig Reinhart at California Lutheran University,
 * used with permission.
 */

import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Random;

public class MergeQuickSorts
{
    public static void main(String[] args)
    {
        try
        {
            FileWriter csvwriter = new FileWriter("quicksortPivot1RandNums.csv");
            Random random = new Random(37);

            int[] list;
            int[] comparisons = new int[1];

            for (int i = 10; i <= 1000000; i *= 10)
            {
                list = new int[i];

                for (int j = 0; j < i; j++)
                {
                    list[j] = random.nextInt(100000);
                }
                System.out.println(Arrays.toString(list));
                quickSortPivotFirst(list, 0, list.length - 1, comparisons);
                csvwriter.write(i + "," + comparisons[0] + "\n");
                System.out.println(Arrays.toString(list));
            }
            csvwriter.close();
        }catch(IOException e)
        {
            System.out.println(e);
        }
    }
    public static int mergeSort(int[] list, int first, int last)
    {
        int middle;
        int count = 0;
        if(first < last)
        {
            middle = (first + last)/2;
            count += mergeSort(list, first, middle);
            count += mergeSort(list, middle+1, last);
            count += mergeLists(list, first, middle, middle+1, last);
        }
        return count;
    }
    public static int mergeLists(int[] list, int start1, int end1, int start2, int end2)
    {
        int count = 0;
        int[] result = new int[list.length];
        int finalStart = start1;
        int finalEnd = end2;
        int indexC = 0;
        while(start1 <= end1 && start2 <= end2)
        {
            count++;
            if(list[start1] < list[start2])
            {
                result[indexC] = list[start1];
                start1++;
            }
            else
            {
                result[indexC] = list[start2];
                start2++;
            }
            indexC++;
        }
        if(start1 <= end1)
        {
            for(int i = start1; i <= end1; i++)
            {
                result[indexC] = list[i];
                indexC++;
            }
        }
        else
        {
            for(int i = start2; i <= end2; i++)
            {
                result[indexC] = list[i];
                indexC++;
            }
        }
        indexC = 0;
        for(int i = finalStart; i <= finalEnd; i++)
        {
            list[i] = result[indexC];
            indexC++;
        }
        return count;
    }
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
