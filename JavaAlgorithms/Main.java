package JavaAlgorithms;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Main
{
    public static void main(String[] args)
    {
        Random random = new Random();
        int[] backwardsInsert = new int[1000];
        int[] backwardsBubble = new int[1000];
        int[] backwardsShell = new int[1000];

        for(int i = 1000; i > 0; i--)
        {
            backwardsBubble[1000 - i] = i;
            backwardsInsert[1000 - i] = i;
            backwardsShell[1000 - i] = i;
        }

        int[] counts = new int[1000];
        for(int i = 1; i <= 1000; i++)
        {
            int[] insertArr = new int[i];
            for (int j = 0; j < i; j++)
            {
                insertArr[j] = random.nextInt();
            }
            counts[i - 1] = InsertionSort.insertionSort(insertArr);
        }
        try {
            FileWriter csvwriter = new FileWriter("insertionSort.csv");
            for (int i = 0; i < 1000; i++) {
                csvwriter.write(i + 1 + "," + counts[i] + "\n");
            }
            csvwriter.close();
        } catch (IOException e) {
            System.out.println(e);
        }

        int[] bubbleCounts = new int[1000];
        for(int i = 1; i <= 1000; i++)
        {
            int[] bubbleArr = new int[i];
            for (int j = 0; j < i; j++)
            {
                bubbleArr[j] = random.nextInt();
            }
            bubbleCounts[i - 1] = BubbleSort.bubbleSort(bubbleArr);
        }
        try {
            FileWriter csvwriter = new FileWriter("bubbleSort.csv");
            for (int i = 0; i < 1000; i++) {
                csvwriter.write(i + 1 + "," + bubbleCounts[i] + "\n");
            }
            csvwriter.close();
        } catch (IOException e) {
            System.out.println(e);
        }

        int[] shellCounts = new int[11];
        int k = 0;

        for(int i = 2; i <= Math.pow(2, 10); i = 2*i)
        {
            int[] shellArr = new int[i];
            for (int j = 0; j < i; j++)
            {
                shellArr[j] = random.nextInt();
            }
            shellCounts[k] = ShellSort.shellSort(shellArr);
            k++;
        }
        try {
            FileWriter csvwriter = new FileWriter("shellSort.csv");
            for (int i = 0; i < 11; i++) {
                csvwriter.write(shellCounts[i] + "\n");
            }
            csvwriter.close();
        } catch (IOException e) {
            System.out.println(e);
        }

        //  <@  Writing backwards array counts to csv
        try {
            FileWriter csvwriter = new FileWriter("backwardsForwards.csv");
            csvwriter.write("Insertion Sort Highest-Lowest: ," + InsertionSort.insertionSort(backwardsInsert) + "\n"
            + "Bubble Sort Highest-Lowest: ," + BubbleSort.bubbleSort(backwardsBubble) + "\n"
            + "Insertion Sort Lowest-Highest: ," + InsertionSort.insertionSort(backwardsInsert) + "\n"
            + "Bubble Sort Lowest-Highest: ," + BubbleSort.bubbleSort(backwardsBubble));
            csvwriter.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
