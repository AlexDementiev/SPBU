package com.spbu.group144.Dementiev;

public class List {
    private class ListNode {
        private ListNode next;
        private int value;

        public ListNode (int value) {
            this.next = null;
            this.value = value;
        }
    }

    private ListNode head = null;
    private ListNode tail = null;
    private int size;
    List() {
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
        return head.value;
    }

    public void push(int value) {
        ListNode newNode = new ListNode(value);
        newNode.next = head;
        head = newNode;
        size++;
    }

    public void push(int value, int index) {
        ListNode tmp = head;
        for (int i = 0; i < index - 1; i++)
            tmp = tmp.next;

        ListNode newNode = new ListNode(value);
        newNode.next = tmp.next;
        tmp.next = newNode;
        size++;
    }

    public int pop() {
        if (isEmpty())
            return -1;

        int data = head.value;
        head = head.next;
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
            tmp = tmp.next;
        int result = tmp.next.value;
        tmp.next = tmp.next.next;
        size--;
        return result;
    }

    public int find(int value) {
        ListNode tmp = head;
        for (int i = 0; i < getSize(); i++) {
            if (tmp.value == value)
                return i;
            tmp = tmp.next;
        }
        return -1;
    }
}
