/*
 * DLL.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Debra
 */

#include "DLL.hpp"
#include "DNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

DLL::DLL(){
	first = NULL;
	last = NULL;
	size = 0;
}
DLL::~DLL(){
	DNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size --;
	}
	first = NULL;
	last = NULL;
}
void DLL::printDLL() {
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	cout << endl;
}
void DLL::printRevDLL() {
	DNode *tmp = last;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->prev;
	}
	cout << endl;
}

void DLL::addFirst(int x) { //2 pts
//add very first element to list
	DNode *n = new DNode(x);
	first = n;
	last = n;
	size += 1;
}
void DLL::addAtFront(int x) { //2 pts
//	add a new node to the beginning of the list
	if (first == NULL) {
		first = new DNode(x);
	} // if
	else {
		DNode *tmp = new DNode(x);
		tmp->next = first;
		first = tmp;
		tmp->prev = NULL;
	} // else
	size += 1;
} // addAtFront

void DLL::push(int x) { //2 pts
// add a new node to the end of the list
	DNode* tmp = new DNode(x);
	DNode* final = first;
	tmp->next = NULL;
	if (first == NULL) {
		first->prev = NULL;
		first = tmp;
	}
	else {
		while (final->next != NULL) {
			final = final->next;
		}
		final->next = tmp;
		tmp->prev = final;
	}
	size += 1;
}

void DLL::addAtK(int x, int k){ //4 pts
//add at position k a new node with x as the data
	DNode *tmp;
	tmp->next = first;
	for (int i = 0; i < k; ++i) {
		tmp = tmp->next;
	}
	DNode *node = new DNode(x);
	node->next = tmp->next;
	tmp->next = node;
	size += 1;
}
void DLL::join(DLL *list2){ //2 pts
// join list 2 to the end of the list, modifying the size of the list
	if (first == NULL || list2->first == NULL) {
		cout << "One or both of the lists are empty";
	}

}

int DLL::pop() { //5 pts
//popping the last node off the end of the list and returning that data
	DNode *tmp = last;
	if (first == NULL) {
		return 0;
	}
	else if (first == last) {
		first = NULL;
		last = NULL;
		size -= 1;
	}
	else {
		tmp->prev->next = NULL;
		last = tmp->prev;
		size -= 1;
	}
}
DNode *DLL::findKth(int k) { 
//find the element at the kth position and returning a pointer to that node
}
int DLL::findK(int k) {
	DNode *tmp = first;
	int ind = 0;
	while (tmp != NULL && tmp->data != k) {
		tmp = tmp->next;
		ind++;
	}
	if (ind < size) {
		return ind;
	}
	else {
		return -1;
	}
}
int DLL::remFirst() { //2 pts
//remove the first node from the list, returning its data
	DNode *tmp = first;
	if (first == 0) {
		return 0;
	}
	else {
		first = tmp->next;
		first->prev = NULL;
		size -= 1;
		return tmp->data;
	}
}
int DLL::remKth(int k) { //4 pts
//remove the kth element of the list, returning its data
	DNode *tmp = first;
	DNode *kNode;
	if (k < size && k > 0) {
		for (int i = 0; i < k - 1; i++) {
			tmp = tmp->next;
		}
		int x = tmp->next->data;
		DNode *tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		tmp->next->next->prev = tmp->next;
		delete tmp2;
		return x;
	}
}
void RecursiveReverse(DLL *l2) { //6 pts
// RECURSIVELY reverses the list

}
void DLL::sortDLL() { //10 pts
//sort the list from smallest to largest
	for (int i = 0; i < size; i++) {
		DNode *tmp = first;
		for (int j = 0; j < (size - 1) - i; j++) {
			if (tmp->data > tmp->next->data) {
				int tmpNum = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = tmpNum;
			}
			tmp = tmp->next;
		}
	}
}

void DLL::Merge2(DLL *l2) { //10 pts
//Merge two sorted lists into one longer sorted list, and setting
//the current list to the longer sorted list
// Note that I sorted both lists before I called this.
//also note that joining the two lists and then sorting is NOT what I want
//here - I want this function to start at the beginning of each list,
//and pull the smallest of the 2 values into the new list, then move up
//one in that particular list.  
// e.g., 
// l1 = 3,7,12,15,22,23,24,29    l2=4,8,12,13,27
// n=3
// l1 = 7,12,15,22,23,24,29    l2=4,8,12,13,27
// n=3,4
// l1 = 7,12,15,22,23,24,29    l2=8,12,13,27
// n=3,4,7
// l1 = 12,15,22,23,24,29    l2=8,12,13,27
// n=3,4,7,8
// l1 = 12,15,22,23,24,29    l2=12,13,27
// n=3,4,7,8,12
// l1 = 15,22,23,24,29    l2=12,13,27
// n=3,4,7,8,12,12
// l1 = 15,22,23,24,29    l2=13,27
// n=3,4,7,8,12,12,13
// l1 = 15,22,23,24,29    l2=27
// n=3,4,7,8,12,12,13
// l1 = 15,22,23,24,29    l2=27
// n=3,4,7,8,12,12,13,15
// l1 = 22,23,24,29    l2=27
// n=3,4,7,8,12,12,13,15,22
// l1 = 23,24,29    l2=27
// n=3,4,7,8,12,12,13,15,22,23
// l1 = 24,29    l2=27
// n=3,4,7,8,12,12,13,15,22,23,24
// l1 = 29    l2=27
// n=3,4,7,8,12,12,13,15,22,23,24,27
// l1 = 29    l2
// n=3,4,7,8,12,12,13,15,22,23,24,27,29
}
void DLL::RemoveDuplicates() { //12pts
// assumes the list is unsorted, removes all duplicates from the list
//Note how massively easier this would be if we just sorted the list first...
// Note also that you can use a helper function if you like
	DNode *x = first;
	DNode *y = x->next;
	while (x != NULL) {
		DNode *mark = first;
		while (mark != x) {
			if (mark->data == x->data) {
				DNode *tmp = x->next;
				y->next = tmp;
				x = tmp;
			}
			mark = mark->next;
		}
		if (mark == x) {
			y = x;
			x = x->next;
		}
	}
}




