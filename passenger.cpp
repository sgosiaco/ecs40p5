// Author: Sean Davis
// Edited by: Sean Gosiaco
#include <cstring>
#include <fstream>
#include "passenger.h"
using namespace std;


Passenger::Passenger()
{
} // Passenger()


Passenger::Passenger(short flightNu, short ro, char sea, const char nam[]) :
  flightNum(flightNu), row(ro), seat(sea)
{
  strcpy(name, nam);
}  // Passenger()


void Passenger::copyPassengers()
{
  Passenger passenger;

  ifstream inf("passengers.dat", ios::binary);
  ofstream outf("passengers2.dat", ios::binary);

  while(inf.read( (char*) &passenger, sizeof(Passenger)))
    outf.write((char*) &passenger, sizeof(Passenger));

  outf.close();
  inf.close();
}  // copyPassengers()

bool Passenger::operator==(const int num) const
{
  return flightNum == num;
} //num equal

bool Passenger::operator==(const char* n) const
{
  return (strcmp(name, n) == 0);
} //name equal

const Passenger& Passenger::operator!()
{
  flightNum = CANCELLED;
  return *this;
} //cancel

ostream& operator<<(ostream &os, const Passenger &pass)
{
  os << pass.name;
  return os;
} //print info
