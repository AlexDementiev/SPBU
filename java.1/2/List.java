package com.spbu.group144.Dementiev;

public class List {
    private ListNode head, tail;
    private int size;

    List() {
        head = null;
        size = 0;
    }

    public int getSize() {
        return size;
    }

    private boolean isEmpty() {
        return (size == 0);
    }

    public int peekBegin() {
        if (isEmpty())
            return 900009;
        return head.getValue();
    }

    public void push(int value) {
        ListNode newNode = new ListNode(value);
        newNode.setNext(head);
        head = newNode;
        size++;
    }

    public void push(int value, int index) {
        ListNode tmp = head;
        for (int i = 0; i < index - 1; i++)
            tmp = tmp.getNext();

        ListNode newNode = new ListNode(value);
        newNode.setNext(tmp.getNext());
        tmp.setNext(newNode);
        size++;
    }

    public int pop() {
        if (isEmpty())
            return -1;

        int data = head.getValue();
        head = head.getNext();
        size--;
        return data;
    }

    public int pop(int index) {
        if (index == 0) {
            return pop();
        }
        if (index > getSize()) {
            return -1;
        }
        ListNode tmp = head;
        for (int i = 0; i < index - 2; i++)
            tmp = tmp.getNext();
        int result = tmp.getNext().getValue();
        tmp.setNext(tmp.getNext().getNext());
        size--;
        return result;
    }

    public int find(int value) {
        ListNode tmp = head;
        for (int i = 0; i < getSize(); i++) {
            if (tmp.getValue() == value)
                return i;
            tmp = tmp.getNext();
        }
        return -1;
    }
}
