#include <fstream>
#include "linkedlist.h"
using namespace std;

ListNode::ListNode(int off, ListNode *n): offset(off), next(n)
{

} //default const.

void LinkedList::initialize(int row)
{
  for(int i = 0; i < row; i++)
    head = new ListNode(EMPTY, head);

} //initialize

LinkedList::~LinkedList()
{
  ListNode *curr = head;

  while(curr != NULL)
  {
    ListNode *temp = curr->next;
    delete curr;
    curr = temp;
  } //while

  head = NULL;
} //decon

int& LinkedList::operator[](int index)
{
  ListNode *temp = head;
  int num = 0;

  while(temp != NULL)
  {
    if(num == index)
      return temp->offset;
    num++;
    temp = temp->next;
  }//while
  return temp->offset;
}//get

const int& LinkedList::operator[](int index) const
{
  ListNode *temp = head;
  int num = 0;

  while(temp != NULL)
  {
    if(num == index)
      return temp->offset;
    num++;
    temp = temp->next;
  }//while
  return temp->offset;
}//get

ostream& operator<<(ostream &os, const LinkedList &list)
{
  ListNode *curr = list.head;

  while(curr != NULL)
  {
    if(curr->offset != list.EMPTY)
      os << 'X';
    else //empty
      os << '-';

    curr = curr->next;
  } //while

  return os;
} //<<
