// Author: Sean Davis

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "flight.h"

using namespace std;

Flight& Flight::operator++(int)
{
  ++(*plane);
  return *this;
} //++

Flight::~Flight()
{
  ofstream outf("flights2.csv", ios::app);
  outf << flightNum << ',' << origin << ',' << destination << ',';
  plane->writePlane(outf);
  outf.close();
  delete plane;
}  // freeFlight()

void Flight::addFlight()
{
  cout << "\nFlight number to add: ";
  cin >> flightNum;
  cin.ignore(TEN, '\n');
  cout << "Origin: ";
  cin.getline(origin, MAX_CITY_LENGTH);
  cout << "Destination: ";
  cin.getline(destination, MAX_CITY_LENGTH);
  plane = new Plane(flightNum);
  plane->addFlight();
}  // addFlight()

int Flight::getFlightNumber() const
{
  return flightNum;
}  // getFlightNumber()

ostream& operator<<(ostream &os, const Flight &flight)
{
  os << left << setw(flight.FLIGHT_NUM_SPACE) << flight.flightNum << ' ';
  os << setw(flight.MAX_CITY_LENGTH) << flight.origin;
  os << ' '  << flight.destination << endl;
  return os;
} // <<

istream& operator>>(istream &is, Flight &flight)
{
  is >> flight.flightNum;
  is.ignore(flight.TEN, ',');
  is.getline(flight.origin, flight.MAX_CITY_LENGTH, ',');
  is.getline(flight.destination, flight.MAX_CITY_LENGTH, ',');
  flight.plane = new Plane(flight.flightNum);
  is >> *flight.plane;
  return is;
} // >>

Flight& Flight::operator!()
{
  !(*plane);
  return *this;
} //!

Flight& Flight::operator--()
{
  (*plane)--;
  return *this;
} //--

bool Flight::find(char *name)
{
  return plane->find(name);
} //find
