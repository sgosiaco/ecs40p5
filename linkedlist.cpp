
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

} //initalize

LinkedList::~LinkedList()
{
  while(head != NULL)
  {
    ListNode *temp = head->next;
    delete head;
    head = temp;
  } //while
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
