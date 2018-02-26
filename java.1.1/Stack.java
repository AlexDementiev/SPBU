package com.spbu.group144.Dementiev;

public class Stack {
    private StackElement head;
    private StackElement tail;

    void push(int data) {
        StackElement newElement = new StackElement();
        newElement.value = data;

        if (head == null) {
            head = newElement;
            tail = newElement;
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

        if (head == tail) {
            int data = head.value;
            head = null;
            tail = null;
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
