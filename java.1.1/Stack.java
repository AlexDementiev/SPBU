package com.spbu.group144.Dementiev;

public class Stack {
    private StackElement head;

    private class StackElement {
        int value;
        StackElement next;
    }
    
    void push(int data) {
        StackElement newElement = new StackElement();
        newElement.value = data;

        if (head == null) {
            head = newElement;
        }
        else {
            newElement.next = head;
            head = newElement;
        }

    }

    int pop() {
        if (head == null) {
            System.out.println("Stack is empty");
            return 42;
        }

        if (head.next == null) {
            int data = head.value;
            head = null;
            return data;
        }

        int data = head.value;
        head = head.next;
        return data;
    }

    void printStack() {
        StackElement tmp = head;
        while (tmp != null) {
            System.out.println(tmp.value);
            tmp = tmp.next;
        }
    }
}
