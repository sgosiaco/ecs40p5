#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <fstream>
#include <iostream>
using namespace std;

class LinkedList;
class ListNode
{
  private:
    int offset;
    ListNode *next;
    friend class LinkedList;
    ListNode(int off, ListNode *n);
    friend ostream& operator<<(ostream &os, LinkedList list);
}; // class listnode

class LinkedList
{
  private:
    ListNode *head = NULL;
    static const int EMPTY = -1;
  public:
    void initialize(int row);
    ~LinkedList();
    int& operator[](int index);
    const int& operator[](int index) const;
    friend ostream& operator<<(ostream &os, LinkedList list);
}; //class LinkedList

#endif	// LINKEDLIST_H
