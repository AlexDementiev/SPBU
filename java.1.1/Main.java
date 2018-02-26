package com.spbu.group144.Dementiev;

public class Main {

    public static void main(String[] args) {
	    Stack stack = new Stack();
	    stack.push(4);

        stack.printStack();

        stack.pop();
        stack.pop();

        stack.printStack();
    }
}
