#ifndef PLANE_H
#define	PLANE_H
#include <fstream>

using namespace std;

class Plane
{
  static const int EMPTY = -1;
  static const int FIRST_ROW = 1;
  static const int FIRST_SEAT = 'A';
  static const int TEN = 10;
  static const int ROW_SPACE = 2;
  int rows;
  int width;
  int reserved;
  int **passengers;
  int flightNumber;
  int getRow() const;
  void showGrid() const;
  void showPassengers() const;
  friend ostream& operator<<(ostream &os, const Plane &rhs);
public:
  Plane();
  Plane(int flightNum);
  ~Plane();
  void addFlight();
  void writePlane(ofstream &outf) const;
  friend istream& operator>>(istream &is, Plane &plane);
  Plane& operator++();
  Plane& operator--(int);
  Plane& operator!();
}; // class Plane

#endif	// PLANE_H
