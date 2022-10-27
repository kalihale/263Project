package JavaAlgorithms;

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
