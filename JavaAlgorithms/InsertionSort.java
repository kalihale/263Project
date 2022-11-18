package JavaAlgorithms;

/** ／(^ㅅ^)＼
 * @file JavaAlgorithms.Matrix.java
 * @author Kali Hale
 * @version 1.0
 *
 * Code from CS 310 taught by Dr. Craig Reinhart at California Lutheran University,
 * used with permission.
 */

public class InsertionSort
{
    public static int insertionSort(int[] list)
    {
        int count = 0;
        int n = list.length;
        for (int i = 1; i < n; i++)
        {
            int newElement = list[i];
            int location = i - 1;
            count++;
            while (location >= 0 && list[location] > newElement)
            {
                list[location + 1] = list[location];
                location = location - 1;
                count++;
            }
            list[location + 1] = newElement;
        }
        return count;
    }
    public static int insertionSortModified(int[] list, int start, int increment)
    {
        int count = 0;
        int n = list.length;
        //  <@  Must have a loop which compares each number in the sublist to each previous number in its sublist
        //      (starts at i + increment and ends when => n)
        for(int j = start + increment; j < n; j += increment)
        {
            //  <@  Inside this is where the insertion sort logic goes
            int newElement = list[j];
            int location = j - increment;
            count++;
            while (location >= 0 && list[location] > newElement && location + increment < list.length)
            {
                list[location + increment] = list[location];
                location = location - increment;
                count++;
            }
            list[location + increment] = newElement;
        }
        return count;
    }
}
