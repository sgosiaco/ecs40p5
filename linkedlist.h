#ifndef LINKEDLIST_H
#define	LINKEDLIST_H


class List;
class ListNode
{
  private:
    int offset;
    ListNode *next;
    friend class LinkedList;
    ListNode(int off, ListNode *n);
}; // class listnode

class LinkedList
{
  private:
    ListNode *head;
    static const int EMPTY = -1;
  public:
    void initalize(int row);
    ~LinkedList();
    int& operator[](int index);
    const int& operator[](int index) const;
}; //class LinkedList

#endif	// LINKEDLIST_H