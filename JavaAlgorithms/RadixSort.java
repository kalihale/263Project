package JavaAlgorithms;

/** ／(^ㅅ^)＼
 * @file JavaAlgorithms.Matrix.java
 * @author Kali Hale
 * @version 1.0
 *
 * Code from CS 310 taught by Dr. Craig Reinhart at California Lutheran University,
 * used with permission.
 */

import java.util.Arrays;
import java.util.LinkedList;

public class RadixSort
{
    public static void main(String[] args)
    {
        Integer[] intarr = new Integer[]{1405, 975, 23, 9803, 4835, 2082, 7368, 573, 804, 746, 4703, 1421, 4273, 1208, 521, 2050};
        String[] strarr = new String[] {"zero", "one", "two", "three", "four", "five", "six", "seven",
                "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
        System.out.println("Original Integer array: \n" + Arrays.toString(intarr));
        System.out.println("Sorted Integer array: \n" + Arrays.toString(radix(intarr, 4)));
        System.out.println("Original String array: \n" + Arrays.toString(strarr));
        System.out.println("Sorted String array: \n" + Arrays.toString(radix(strarr, 9)));
//        System.out.println((int)'a');
    }
    public static Integer[] radix(Integer[] list, int keySize)
    {
        //  <@  Create buckets
        LinkedList<Integer>[] buckets = new LinkedList[10];
        GenericCombineBuckets gcb = new GenericCombineBuckets();
        //  <@  Initialize linkedlists in array "buckets"
        for(int i = 0; i < buckets.length; i++)
        {
            buckets[i] = new LinkedList<>();
        }
        //  <@  Initialize shift at 1
        int shift = 1;
        //  <@  Up until the largest digit (starting with the ones digit for all numbers)
        //      Note: Once the number of digits in shift is larger than the number of digits in a number,
        //      (list[j] / shift) % 10 will return 0, which will put the number in the 0 bucket
        for(int i = 1; i <= keySize; i++)
        {
            //  <@  For the entire list, sort the digit in question into buckets 0-9
            for(int j = 0; j < list.length; j++)
            {
                buckets[(list[j] / shift) % 10].add(list[j]);
            }
            //  <@  Combine the buckets (using a generic class)
            //      Multiply shift by 10
            gcb.CombineBuckets(list, buckets);
            shift *= 10;
        }
        return list;
    }
    public static String[] radix(String[] list, int keySize)
    {
        //  <@  Create buckets
        LinkedList<String>[] buckets = new LinkedList[26];
        GenericCombineBuckets gcb = new GenericCombineBuckets();
        //  <@  Initialize
        for(int i = 0; i < buckets.length; i++)
        {
            buckets[i] = new LinkedList<>();
        }
        //  <@  Initialize shift
        int shift = 1;
        //  <@  Loops until we're done with the longest word
        for(int i = 1; i <= keySize; i++)
        {
            //  <@  Loop through the entire list looking at a certain index
            for(int j = 0; j < list.length; j++)
            {
                //  <@  If the last index of the word is a smaller number than the index we're looking at,
                //      put the word in the bucket for 'a' because smaller words come first in the dictionary
                //      (eg. "pea" always comes before "peacock", so we can use 'a' as a placeholder)
                if (list[j].length() - 1 < keySize - shift)
                {
                    buckets[0].add(list[j]);
                }
                //  <@  Else evaluate the character at that index
                else
                {
                    buckets[list[j].charAt(keySize - shift) - 97].add(list[j]);
                }
            }
            //  <@  Combine buckets (using a generic class) and increment shift (we are not dividing numbers so
            //      we're shifting one to the left this time)
            gcb.CombineBuckets(list, buckets);
            shift++;
        }
        return list;
    }
}
