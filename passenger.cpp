// Author: Sean Davis
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

bool operator==(Passenger &pass, int num)
{
  return pass.flightNum == num;
} //num equal

bool operator==(Passenger &pass, char* name)
{
  return (strcmp(pass.name, name) == 0);
} //name equal

Passenger& operator!(Passenger &pass)
{
  pass.flightNum = pass.CANCELLED;
  return pass;
} //cancel

ostream& operator<<(ostream &os, Passenger pass)
{
  os << pass.name;
  return os;
} //print info
