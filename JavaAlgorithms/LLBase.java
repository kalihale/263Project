/** ／(^ㅅ^)＼
 * @file JavaAlgorithms.LLBase.java
 * @author Dr. Craig Reinhart
 *
 * Code from CS 220 at California Lutheran University,
 * used with permission.
 */

package DoubleLinkedList;

public abstract class LLBase<T> {

	protected Node<T> head = null;
	protected Node<T> tail = null;

	protected int size; // -- number of items in list

	// -- Inner class to define the node used by the linked-list
	public class Node<T> {

		// -- the object value
		private T value;

		// -- references to next and previous nodes
		// (e.g. for use in a linked list)
		private Node<T> next;
		private Node<T> previous;

		// -- parameter is assigned to value
		public Node(T value) {
			this.value = value;
			this.next = null;
			this.previous = null;
		}

		public void setNext(Node<T> next) {
			this.next = next;
		}

		public void setPrevious(Node<T> previous) {
			this.previous = previous;
		}

		public Node<T> getNext() {
			return this.next;
		}

		public Node<T> getPrevious() {
			return this.previous;
		}

		// -- returns the object stored at value
		// (e.g. removes the Node wrapper)
		public T getValue() {
			return this.value;
		}

		// -- uses toString of object stored at value
		public String toString() {
			return "Node: " + value;
		}

		@Override
		public boolean equals(Object o) {
			Node<T> e = (Node<T>) o;
			T lhs = this.getValue();
			T rhs = e.getValue();

			return lhs.equals(rhs);
		}

	}

}