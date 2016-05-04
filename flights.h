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
  void removePassenger() const;
  void find() const;
  const Flights& operator++();
  const Flights& operator+=(Flight* const flight);
  const Flights& operator--(int);
  friend istream& operator>>(istream &is, Flights &rhs);
}; // class flights

#endif	// FLIGHTS_H
