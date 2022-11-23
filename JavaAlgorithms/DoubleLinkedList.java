package JavaAlgorithms;

/** ／(^ㅅ^)＼
 * @file JavaAlgorithms.DoubleLinkedList.java
 * @author Kali Hale
 * @version 1.0
 *
 * Code from CS 220 at California Lutheran University,
 * used with permission.
 */

public class DoubleLinkedList<T> extends LLBase<T> implements LLInterface<T>
{

    //  <@  Returns same as size for linked list
    @Override
    public int capacity()
    {
        int size = 0;
        Node<T> ref = this.head;
        while(ref != null)
        {
            ref = ref.getNext();
            size++;
        }
        return size;
    }

    //  <@  Returns if list is empty (determined here if size == 0)
    @Override
    public boolean isEmpty()
    {
        return this.head == null;
    }

    //  <@  Returns number of objects in linked list
    @Override
    public int size()
    {
//        return this.size;
        int size = 0;
        Node<T> ref = this.head;
        while(ref != null)
        {
            ref = ref.getNext();
            size++;
        }
        return size;
    }

    //  <@  Returns true if object exists in linked list, false otherwise
    @Override
    public boolean contains(T o)
    {
        Node<T> ptr = this.head;
        while(ptr != null)
        {
            if(ptr.getValue().equals(o))
            {
                return true;
            }
            else
            {
                ptr = ptr.getNext();
            }
        }
        return false;
    }

    //  <@  Returns array of T objects, throws exception if length of array is
    //      shorter than size of linked list
    @Override
    public T[] toArray(T[] array) throws IllegalArgumentException
    {
        if(array.length < size())
        {
            throw new IllegalArgumentException();
        }
        Node<T> ptr = this.head;
        int index = 0;
        while(ptr != null)
        {
            array[index] = ptr.getValue();
            ptr = ptr.getNext();
            index++;
        }
        return array;
    }

    //  <@  Adds object e to end of list
    //      Must be wrapped in node
    @Override
    public void add(T e)
    {
        Node<T> addNode = new Node<T>(e);
        if(this.head == null)
        {
            addNode.setNext(null);
            this.head = addNode;
        }
        else
        {
            Node<T> ptr = this.tail;
            addNode.setNext(ptr.getNext());
            ptr.setNext(addNode);
            addNode.setPrevious(ptr);
        }
        this.tail = addNode;
        this.size++;
    }

    //  <@  Add element at index, throws index out of bounds if index is negative,
    //      adds to end if index is greater than size
    @Override
    public void add(int index, T element) throws IndexOutOfBoundsException
    {
        if(index < 0)
        {
            throw new IndexOutOfBoundsException();
        }
        else if(this.head == null)
        {
            add(element);
        }
        else if(index == 0)
        {
            Node<T> addNode = new Node<T>(element);
            addNode.setNext(this.head);
            this.head = addNode;
            addNode.setPrevious(null);
            addNode.getNext().setPrevious(addNode);
        }
        else if(index < size())
        {
            Node<T> addNode = new Node<T>(element);
            Node<T> ptr = this.head;
            int i = 0;
            while(i < index - 1)
            {
                ptr = ptr.getNext();
                i++;
            }
            addNode.setNext(ptr.getNext());
            addNode.setPrevious(ptr);
            ptr.setNext(addNode);
            addNode.getNext().setPrevious(addNode);
        }
        else
        {
            add(element);
        }

    }

    //  <@  Removes the first instance of a given object
    //      Return true if object is found, false otherwise
    @Override
    public boolean remove(T o)
    {
        if(size() == 1 && this.head.getValue().equals(o))
        {
            clear();
            return true;
        }
        else if(this.head.getValue().equals(o))
        {
            this.head = this.head.getNext();
            this.head.setPrevious(null);
            return true;
        }
        else if(this.tail.getValue().equals(o))
        {
            this.tail = this.tail.getPrevious();
            this.tail.setNext(null);
            return true;
        }
        else
        {
            Node<T> ptr = this.head.getNext();
            while(ptr != null)
            {
                if (ptr.getValue().equals(o))
                {
                    ptr.getPrevious().setNext(ptr.getNext());
                    ptr.getNext().setPrevious(ptr.getPrevious());
                    return true;
                }
                ptr = ptr.getNext();
            }
        }
        return false;
    }

    //  <@  Removes the object and node at index
    @Override
    public T remove(int index) throws IndexOutOfBoundsException
    {
        if(index < 0 || index >= size())
        {
            throw new IndexOutOfBoundsException();
        }
        else if(index == 0)
        {
            Node<T> ptr = this.head;
            this.head = this.head.getNext();
            this.head.setPrevious(null);
            return ptr.getValue();
        }
        else if(index == size() - 1)
        {
            Node<T> ptr = this.tail;
            this.tail = this.tail.getPrevious();
            this.tail.setNext(null);
            return ptr.getValue();
        }
        else
        {
            Node<T> ptr = this.head.getNext();
            for(int i = 1; i < index; i++)
            {
                ptr = ptr.getNext();
            }
            ptr.getPrevious().setNext(ptr.getNext());
            ptr.getNext().setPrevious(ptr.getPrevious());
            return ptr.getValue();
        }
    }

    //  <@  Clears the list
    @Override
    public void clear()
    {
        //  <@  Only need to set head and tail to null, garbage collector will take care of the rest
        this.head = null;
        this.tail = null;
    }

    //  <@  Get object at given index, throws IndexOutOfBoundsException if index < 0 || index > this.size
    @Override
    public T get(int index) throws IndexOutOfBoundsException
    {
        if(index >= size() || index < 0)
        {
            throw new IndexOutOfBoundsException();
        }
        Node<T> ptr = this.head;
        for(int i = 0; i < index; i++)
        {
            ptr = ptr.getNext();
        }
        return ptr.getValue();
    }

    //  <@  Set a given index to a given T element and replace node at same index, throws IndexOutOfBoundsException
    //      if index < 0 || index > this.size
    @Override
    public T set(int index, T element) throws IndexOutOfBoundsException
    {
        if(index < 0 || index >= size())
        {
            throw new IndexOutOfBoundsException();
        }
        Node<T> ptr = this.head;
        for(int i = 0; i < index; i++)
        {
            ptr = ptr.getNext();
        }
        Node<T> newNode = new Node<T>(element);
        newNode.setNext(ptr.getNext());
        newNode.setPrevious(ptr.getPrevious());
        newNode.getNext().setPrevious(newNode);
        newNode.getPrevious().setNext(newNode);
        return ptr.getValue();
    }

    //  <@  Returns the first index of a given T o
    @Override
    public int indexOf(T o)
    {
        Node<T> ptr = this.head;
        int i = 0;
        while(ptr != null)
        {
            if(ptr.getValue().equals(o))
            {
                return i;
            }
            ptr = ptr.getNext();
            i++;
        }
        return -1;
    }

    //  <@  Returns last index of a given T o
    @Override
    public int lastIndexOf(T o)
    {
        Node<T> ptr = this.tail;
        int i = size() - 1;
        while(ptr != null)
        {
            if(ptr.getValue().equals(o))
            {
                return i;
            }
            ptr = ptr.getPrevious();
            i--;
        }
        return -1;
    }

    //  <@  Prints the T objects starting at the head and ending at the tail
    @Override
    public void printForward()
    {
        Node<T> ptr = this.head;
        while(ptr != null)
        {
            System.out.println(ptr.toString());
            ptr = ptr.getNext();
        }
    }

    //  <@  Prints the T objects starting at the tail and ending at the head
    @Override
    public void printReverse()
    {
        Node<T> ptr = this.tail;
        while(ptr != null)
        {
            System.out.println(ptr.toString());
            ptr = ptr.getPrevious();
        }

    }
}