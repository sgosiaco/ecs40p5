#ifndef PLANE_H
#define	PLANE_H
#include <fstream>
#include "linkedlist.h"

using namespace std;

class Plane
{
  static const int NEG = -1;
  static const int FIRST_ROW = 1;
  static const int FIRST_SEAT = 'A';
  static const int TEN = 10;
  static const int ROW_SPACE = 2;
  int rows;
  int width;
  int reserved;
  LinkedList *passengers;
  int flightNumber;
  int getRow() const;
  void showGrid() const;
  friend ostream& operator<<(ostream &os, const Plane &rhs);
public:
  Plane(int flightNum);
  ~Plane();
  void addFlight();
  void writePlane(ofstream &outf) const;
  bool find(const char *name) const;
  const Plane& operator++();
  const Plane& operator--(int) const;
  const Plane& operator!() const;
  friend istream& operator>>(istream &is, Plane &plane);
}; // class Plane

#endif	// PLANE_H
