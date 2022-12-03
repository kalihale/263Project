package JavaAlgorithms;

/**
 * @file JavaAlgorithms.MergeSortTest.java
 * @author Aaron Jimenez
 * @version 1.0
 *
 */

public class MergeSortTest {
    public static final int RUNS = 100;

    public static void main(String[] args) {
        int[] toSort;
        double totalTime = 0.0;
        double startTime;
        double endTime;
        // Get multiple runs and average them
        for(int i = 0; i < RUNS; i++)
        {
            toSort = CommonUtils.generateRandomIntArray(0, 1000);

            startTime = System.currentTimeMillis();
            MergeSort.mergeSort(toSort, 0, toSort.length - 1);
            endTime = System.currentTimeMillis();

            totalTime += (endTime - startTime);

        }

        System.out.println("Total Avg Runtime: "+(totalTime/RUNS));
    }
}
