/** ／(^ㅅ^)＼
 * @file JavaAlgorithms.LLInterface.java
 * @author Dr. Craig Reinhart
 *
 * Code from CS 220 at California Lutheran University,
 * used with permission.
 */

package DoubleLinkedList;

// import java.util.Iterator;

public interface LLInterface<T> {

	// -- returns the number of objects in the list can hold
	//    returns the same as size() for a linked-list
	int capacity();

	// -- returns true if list is empty
	boolean isEmpty();

	// -- returns the number of objects in the list
	int size();

	// -- returns true if list contains object o, false otherwise
	//    compare the value of the object, not its reference nor
	//    the previous and next links in the linked list
	boolean contains(T o);

	// -- convert the list to an array T of length size
	//    will have to unwrap the objects from their Nodes for a linked list
	//    the size of array must be equal to or greater than the size of
	//    the linked list. If it is not, throw the exception. This method
	//    modifies the argument AND returns a reference to the argument
	T[] toArray(T[] array) throws IllegalArgumentException;

	// -- insert an object e at end of list
	//    will have to wrap with an object of type Node<T> for a linked list
	void add(T e);

	// -- insert an object e at position
	//    if index > size then add to back
	//    if index < 0 throw exception
	//    will have to wrap with an object of type Node<T> for a linked list
	void add(int index, T element) throws IndexOutOfBoundsException;

	// -- remove first occurrence of an object T
	//    compare the value of the object, not its reference nor
	//    the previous and next links in the linked list
	//    return true if object is found/removed, false otherwise
	boolean remove(T o);

	// -- remove object at position
	//    return the removed object
	T remove(int index) throws IndexOutOfBoundsException;

	// -- remove all objects from list
	void clear();

	// -- returns element at position
	T get(int index) throws IndexOutOfBoundsException;

	// -- replace object T at specified position with given object T
	//    returns the original node at the specified index of the list
	T set(int index, T element) throws IndexOutOfBoundsException;

	// -- location of first occurrence of object T, -1 if not in list
	//    compare the value of the object, not its reference nor
	//    the previous and next links in the linked list
	int indexOf(T o);

	// -- index of last occurrence of object T, -1 if not in list
	//    only compare the value of the object, not the links
	int lastIndexOf(T o);

	// -- print the list of Nodes, one Node per line, in the
	//    forward direction starting from head following next references
	//    calls the Node toString() function to print individual Nodes
	void printForward();

	// -- print the list of Nodes, one Node per line, in the
	//    reverse direction starting from tail following previous references
	//    calls the Node toString() function to print individual Nodes
	void printReverse();

	// -- unused at this time
	// Iterator<T> iterator ();

}