package com.spbu.group144.Dementiev;

public class ListNode {
    private ListNode next;
    private int value;

    public ListNode (int value) {
        this.next = null;
        this.value = value;
    }

    public void setNext(ListNode next) {
        this.next = next;
    }

    public int getValue() {
        return value;
    }

    public ListNode getNext() {
        return next;
    }
}
