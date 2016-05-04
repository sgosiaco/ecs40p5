#ifndef PASSENGER_H
#define	PASSENGER_H

#include "plane.h"

class Passenger
{
public:
  static const int NAME_LENGTH = 30;
  static const int CANCELLED = -1;
private:
  short flightNum;
  short row;
  char seat;
  char name[NAME_LENGTH];
public:
  Passenger();
  Passenger(short flightNu, short ro, char sea, const char nam[]);
  static void copyPassengers();
  bool operator==(const int num) const;
  bool operator==(const char *name) const;
  const Passenger& operator!();
  friend ostream& operator<<(ostream &os, const Passenger &pass);
  friend istream& operator>>(istream &is, Plane &plane);
}; // class passengers

#endif	// PASSENGERS_H
