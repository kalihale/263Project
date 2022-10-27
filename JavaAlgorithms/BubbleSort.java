package JavaAlgorithms;


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
