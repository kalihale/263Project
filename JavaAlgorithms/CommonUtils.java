package JavaAlgorithms;

import java.util.Random;

public class CommonUtils {
    public static int[] generateRandomIntArray(int min, int max)
    {
        int[] toSort = new int[max];

        // Generate array of random integers
        int genInt;
        Random rand = new Random();
        for(int i = 0; i < toSort.length; i++)
        {
            genInt = rand.nextInt((max - min) + 1) + min;
            toSort[i] = genInt;
        }

        return toSort;

    }

    public static Integer[] generateRandomIntegerArray(int min, int max)
    {
        Integer[] toSort = new Integer[max];

        // Generate array of random integers
        int genInt;
        Random rand = new Random();
        for(int i = 0; i < toSort.length; i++)
        {
            genInt = rand.nextInt((max - min) + 1) + min;
            toSort[i] = Integer.valueOf(genInt);
        }

        return toSort;

    }
}
