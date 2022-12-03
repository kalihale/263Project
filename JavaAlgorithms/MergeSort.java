package JavaAlgorithms;/** ／(^ㅅ^)＼
 * @file JavaAlgorithms.Matrix.java
 * @author Kali Hale
 * @version 1.0
 *
 * Code from CS 310 taught by Dr. Craig Reinhart at California Lutheran University,
 * used with permission.
 */

public class MergeSort {
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
}
