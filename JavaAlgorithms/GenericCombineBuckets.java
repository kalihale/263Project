package JavaAlgorithms;

import java.util.LinkedList;

public class GenericCombineBuckets <T>
{
    T[] list;
    LinkedList[] buckets;
    GenericCombineBuckets()
    {
    }
    public void CombineBuckets(T[] list, LinkedList[] buckets)
    {
        this.list = list;
        this.buckets = buckets;
        //  <@  This is literally the same method as before, I just overloaded it with a different method signature
        //      TBH this could easily be a generic method.
        int j = 0;
        for (LinkedList bucket : this.buckets)
        {
            while (!bucket.isEmpty())
            {
                this.list[j] = (T) bucket.remove();
                j++;
            }
        }
    }

}
