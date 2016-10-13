/*
 * SLL.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: Debra
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

SLL::SLL(){
	first = NULL;
	last = NULL;
	size = 0;
}
SLL::~SLL(){
	SNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size --;
	}
	first = NULL;
	last = NULL;
}
void SLL::printSLL() {
	SNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	cout << endl;
}

void SLL::addFirst(int x) { // 3 pts
//make a new list of only one node, data is x
	SNode *n = new SNode(x);
	first = n;
	last = n;
	size += 1;
} // addFirst
void SLL::addAtFront(int x) {  //3 pts
//add a new node to the front of the list with data being x
	if (first == NULL) {
		first = new SNode(x);
		size += 1;
	} // if
	else {
		SNode *temp = new SNode(x);
		temp->next = NULL;
		temp->next = first;
		first = temp;
		size += 1;
	} // else
} // addAtFirst

void SLL::push(int x) { //6 pts
//add a new node to the end of the list, with data x
	SNode* temp = new SNode(x);
	temp->next = NULL;

	if (first == NULL) {
		first = temp;
	} // if
	else {
		SNode* last = first;
		while(last->next != NULL) {
			last = last->next;
		} // while
		last->next = temp;
	} // else
} // push

void SLL::addAtK(int x, int k){
	SNode *tmp = first;
	if (k==0) {
		addAtFront(x);
		size++;
	}
	if (k < size  && k >= 0) {
		for (int i = 0; i < k-1; i++) {
			tmp = tmp->next;
		}
		SNode *tmp2 = tmp->next;
		tmp->next = new SNode(x);
		tmp->next->next = tmp2;
		size++;
	}
}
void SLL::join(SLL *list2){ //3 pts
//join the list with list2, making the current list one longer list
	SNode* temp;
	SNode* temp2;
	if (first == NULL || list2->first == NULL) {
		cout << "One or both lists are empty" << endl;
	} // if
	else {
		temp = first;
		if (temp->next == NULL) {
			temp->next = list2->first;
		} // if
		else {
			while ( temp->next != NULL) {
				temp2=temp;
				temp =temp->next;
			} // while
			temp->next = list2->first;
		} // else
	} // else
} // join

int SLL::pop() {
	if (size > 0) {
		int x = last->data;
		if (first != last){
			SNode *tmp = first;
			for (int i = 0; i < size-1;i++) {
				tmp = tmp->next;
			}
			delete last;
			last = tmp;
			last->next = NULL;
		}
		else {
			delete last;
			first = NULL;
			last = NULL;
		}
		size --;
		return x;
	}
	else {
		return -1;
	}
}
SNode *SLL::findKth(int k) { //4 pts
// find the node at the kth location and return it
	SNode *tmp = first;
	for (int i = 0; i < k; i++) {
		tmp = tmp->next;
	} // for
	return tmp;
} // findKth

int SLL::findK(int k) {
	SNode *tmp = first;
	int ind = 0;
	while (tmp != NULL && tmp->data != k) {
		tmp = tmp->next;
		ind++;
	} // while
	if (ind < size) {
		return ind;
	} // if
	else {
		return -1;
	} // else
} // findK
int SLL::remFirst() { //3 pts
//remove the first node from the list, returning its data
	SNode *tmp = first;
	int tmpData = tmp->data;
	first = first->next;
	free(tmp);
	return tmpData;
} // remFirst
int SLL::remKth(int k) {
	if (k < size && k > 0) {
		SNode *tmp = first;
		for (int i = 0; i < k - 1; i++) {
			tmp = tmp->next;
		} // for
		int x = tmp->next->data;
		SNode *tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
		return x;
	} // if
	else {
		return 0;
	} // else
} // remKth
void SLL::reverseList() { // 10 pts
	SNode *marker = first;
	SNode *prev = NULL;
	SNode *nxt = NULL;
	while(marker != NULL) {
		nxt = marker->next;
		marker->next = prev;
		prev = marker;
		marker = nxt;
	} // while
	first = prev;
} // reverseList
