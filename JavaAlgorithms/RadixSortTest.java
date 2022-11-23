package JavaAlgorithms;

/**
 * @file JavaAlgorithms.RadixSortTest.java
 * @author Aaron Jimenez
 * @version 1.0
 *
 */

public class RadixSortTest {
    public static final int RUNS = 100;
    public static void main(String[] args) {
        Integer[] toSort;
        double totalTime = 0.0;
        double startTime;
        double endTime;
        // Get multiple runs and average them
        for(int i = 0; i < RUNS; i++)
        {
            toSort = CommonUtils.generateRandomIntegerArray(0, 1000);

            startTime = System.currentTimeMillis();
            RadixSort.radix(toSort, 4);
            endTime = System.currentTimeMillis();

            totalTime += (endTime - startTime);

        }

        System.out.println("Total Avg Runtime: " + (totalTime/RUNS));

    }
}
