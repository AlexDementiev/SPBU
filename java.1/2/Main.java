package com.spbu.group144.Dementiev;

public class Main {

    public static void main(String[] args) {
	    List list = new List();
	    list.push(1);
	    list.push(2);
	    list.push(3, 1);
        System.out.println(list.getSize());
        System.out.println(list.find(2));
        System.out.println(list.pop(3));
        System.out.println(list.pop());
        System.out.println(list.getSize());
    }
}
