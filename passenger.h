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
  friend bool operator==(Passenger &pass, int num);
  friend bool operator==(Passenger &pass, char *name);
  friend Passenger& operator!(Passenger &pass);
  friend ostream& operator<<(ostream &os, Passenger pass);
  friend istream& operator>>(istream &is, Plane &plane);
}; // class passengers

#endif	// PASSENGERS_H
