package com.github.marceloserpa.algo.binarytree;

public class BinarySearchTree {

	private TreeNode root;
	
	public void insert(Integer data) {
		if(root == null) {
			root = new TreeNode(data);
		} else {
			root.insert(data);
		}
	}
	
	public TreeNode find(Integer data) {
		if(root != null) return root.find(data);
		return null;
	}
	
	public void delete(Integer data) {
		TreeNode parent = root;
		TreeNode current = root;
		Boolean isLeft = false;
		
		while(current != null && current.getData() != data) {
			parent = current;
			
			if(data < current.getData()) {
				current = current.getLeft();
				isLeft = true;
			} else {
				current = current.getRight();
				isLeft = false;
			}
		}
		
		if(current == null) {
			return;
		}
		
		if(current.getLeft() == null && current.getRight() == null) {
			if(current == root) {
				root = null;
			} else {
				if(isLeft) {
					parent.setLeft(null);
				} else {
					parent.setRight(null);
				}
			}
		} else if (current.getRight() == null) {
			
			if(current == root) {
				root = current.getLeft();
			} else if(isLeft) {
				parent.setLeft(current.getLeft());
			} else {
				parent.setRight(current.getLeft());
			}
			
		} else if (current.getLeft() == null) {
			
			if(current == root) {
				root = current.getRight();
			} else if(isLeft) {
				parent.setLeft(current.getRight());
			} else {
				parent.setRight(current.getRight());
			}		
		}
		
	}
	
}
