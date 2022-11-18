package JavaAlgorithms;

/** ／(^ㅅ^)＼
 * @file JavaAlgorithms.Matrix.java
 * @author Kali Hale
 * @version 1.0
 *
 * Code from CS 310 taught by Dr. Craig Reinhart at California Lutheran University,
 * used with permission.
 */

public class ShellSort
{
    public static int shellSort(int[] list)
    {
        int count = 0;
        int passes = (int)(Math.log(list.length)/Math.log(2));
        while(passes >= 1)
        {
            int increment = (int)Math.pow(2, passes - 1);
            for(int i = 0; i < increment; i++)
            {
                count += InsertionSort.insertionSortModified(list, i, increment);
            }
            passes--;
        }
        return count;
    }
}
