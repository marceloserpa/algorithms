package com.github.marceloserpa.algo.binarytree;

public class TreeNode {

	private Integer data;
	private TreeNode left;
	private TreeNode right;
	
	public TreeNode(Integer data) {
		super();
		this.data = data;
	}
	
	public TreeNode find(Integer data) {
		System.out.println("compare to " + this.data);
		if(this.data == data) return this;
		if(this.data > data && left != null) return left.find(data);
		if(this.data < data && right != null) return right.find(data);
		return null;
	}
	
	public void insert(Integer data) {
		if(data >= this.data) {
			if(right == null) {
				right = new TreeNode(data);
			} else {
				right.insert(data);
			}
		} else {
			if(left == null) {
				left = new TreeNode(data);
			} else {
				left.insert(data);
			}
		}
	}
	
	public Integer getData() {
		return data;
	}
	public TreeNode getLeft() {
		return left;
	}
	public TreeNode getRight() {
		return right;
	}
	public void setLeft(TreeNode left) {
		this.left = left;
	}
	public void setRight(TreeNode right) {
		this.right = right;
	}
	
}
