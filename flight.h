#ifndef FLIGHT_H
#define	FLIGHT_H

#include <iostream>
#include <fstream>
#include "plane.h"

using namespace std;

class Flight
{
  static const int MAX_CITY_LENGTH = 20;
  static const int TEN = 10;
  static const int FLIGHT_NUM_SPACE = 4;
  int flightNum;
  char origin[MAX_CITY_LENGTH];
  char destination[MAX_CITY_LENGTH];
  Plane *plane;
public:
  const Flight& operator++(int) const;
  ~Flight();
  void addFlight();
  int getFlightNumber() const;
  bool find(char *name);
  friend ostream& operator<<(ostream &os, const Flight &flight);
  friend istream& operator>>(istream &is, Flight &flight);
  const Flight& operator!() const;
  const Flight& operator--() const;
} ;  // class Flight
#endif	// FLIGHT_H
