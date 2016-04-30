#ifndef FLIGHTS_H
#define	FLIGHTS_H

#include "flight.h"

class Flights
{
  static const int INITIAL_SIZE = 2;
  static const int RESIZE_MULTIPLIER = 2;
  static const int TEN = 10;
  Flight **flights;
  int size;
  int capacity;
public:
  Flights();
  ~Flights();
  void addPassenger() const;
  friend Flights& operator++(Flights &rhs);
  friend Flights& operator+=(Flights &rhs, Flight *flight);
  int getSize() const;
  friend istream& operator>>(istream &is, Flights &rhs);
  friend Flights& operator--(Flights &rhs);
  void removePassenger() const;
}; // class flights

#endif	// FLIGHTS_H
