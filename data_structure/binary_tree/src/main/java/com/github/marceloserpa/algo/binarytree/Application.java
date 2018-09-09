package com.github.marceloserpa.algo.binarytree;

public class Application {

	public static void main(String[] args) {
		
		BinarySearchTree bst = new BinarySearchTree();
		bst.insert(52);
		bst.insert(33);
		bst.insert(65);
		bst.insert(25);
		bst.insert(39);
		bst.insert(60);
		bst.insert(60);
		bst.insert(78);
		bst.insert(12);
		bst.insert(27);
		bst.insert(34);
		bst.insert(48);
		bst.insert(72);
		bst.insert(90);
		bst.insert(70);
		
		System.out.println(bst.find(70).getData());
		
		bst.delete(70);
		
		System.out.println(bst.find(70));
	}
	
}
