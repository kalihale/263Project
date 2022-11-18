package JavaAlgorithms;

/** ／(^ㅅ^)＼
 * @file JavaAlgorithms.Matrix.java
 * @author Kali Hale
 * @version 1.0
 *
 * Code from CS 310 taught by Dr. Craig Reinhart at California Lutheran University,
 * used with permission.
 */

public class BubbleSort
{
    public static int bubbleSort(int[] list)
    {
        int count = 0;
        int numberOfPairs = list.length;
        boolean swappedElements = true;
        int temp;
        while(swappedElements)
        {
            numberOfPairs--;
            swappedElements = false;
            for(int i = 0; i < numberOfPairs; i++)
            {
                count++;
                if(list[i] > list[i + 1])
                {
                    temp = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = temp;
                    swappedElements = true;
                }
            }
        }
        return count;
    }
}
