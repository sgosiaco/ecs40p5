// Author: Sean Davis

#include "flights.h"
#include "utilities.h"

Flights::Flights() : size( 0 ), capacity(INITIAL_SIZE)
{
  flights = new Flight*[capacity];
} // Flights()


Flights::~Flights()
{
  ofstream outf ("flights2.csv");
  outf << size << endl;
  outf.close();
  outf.open("passengers3.dat", ios::trunc | ios::out);
  outf.close();

  for(int i = 0; i < size; i++)
    delete flights[i];

  delete [] flights;
} // ~Flights()

Flights& operator++(Flights &rhs)
{
  int i;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < rhs.size; i++)
    cout << *(rhs.flights[i]);

  Flight *flight = new Flight();
  flight->addFlight();
  rhs += flight;
  return rhs;
} //addFlight()

void Flights::addPassenger() const
{
  int i, flightNumber;

  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    cout << *flights[i];

  do
  {
    cout << "\nFlight number (0 = exit): ";
    flightNumber = getNumber();

    if(flightNumber > 0)
    {

      for(i = 0; i < size; i++)
        if(flights[i]->getFlightNumber() == flightNumber)
        {
          (*flights[i])++;
          break;
        }  // if found match of flight

      if(i == size)
      {
        cout << "We do not have a flight number " << flightNumber << ".\n";
        cout << "Please try again.\n";
      }  // if flightNumber not found
    }  // if flightNumber > 0
    else // if flightNumer <= 0
      if(flightNumber == ERROR)
        cout << "That is an invalid flight number.\nPlease try again.\n";
  } while((flightNumber != 0 && i == size) || flightNumber == ERROR);
}  // addPassenger()

Flights& operator+=(Flights &rhs, Flight *flight)
{
  int i;

  if(rhs.capacity == rhs.size)
  {
    Flight **temp = rhs.flights;
    rhs.capacity *= rhs.RESIZE_MULTIPLIER;
    rhs.flights = new Flight*[rhs.capacity];

    for(i = 0; i < rhs.size; i++)
      rhs.flights[i] = temp[i];

    delete [] temp;
  } // if size == capacity

  for(i = rhs.size - 1;
    i >= 0 && rhs.flights[i]->getFlightNumber() > flight->getFlightNumber(); i--)
    rhs.flights[i + 1] = rhs.flights[i];

  rhs.flights[i + 1] = flight;
  (rhs.size)++;
  return rhs;
} //insert()

int Flights::getSize() const
{
  return size;
}  // size()

istream& operator>>(istream &is, Flights &rhs)
{
  Flight *flight;
  int numberOfFlights;
  is >> numberOfFlights;

  for(int i = 0; i < numberOfFlights; i++)
  {
    flight = new Flight;
    is >> *flight;
    rhs += flight;
  }  // for each flight

  return is;
} //readFlights()

Flights& operator--(Flights &rhs)
{
  int i, flightNumber;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < rhs.size; i++)
    cout << *(rhs.flights[i]);

  cout << "\nFlight number to remove: ";
  cin >> flightNumber;
  cin.ignore(rhs.TEN, '\n');

  for(i = 0; i < rhs.size; i++)
    if(rhs.flights[i]->getFlightNumber() == flightNumber)
    {
      !(*(rhs.flights[i]));
      delete rhs.flights[i];

      for(; i < rhs.size - 1; i++)
        rhs.flights[i] = rhs.flights[i + 1];

      rhs.size--;
      break;
    }  // if found match of flight

  return rhs;
} //removeFlight()

void Flights::removePassenger() const
{
  int i, flightNumber;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    cout << *flights[i];

  cout << "\nFlight number of passenger remove: ";
  cin >> flightNumber;
  cin.ignore(TEN, '\n');

  for(i = 0; i < size; i++)
    if(flights[i]->getFlightNumber() == flightNumber)
    {
      --(*flights[i]);
      break;
    }  // if found match of flight
}  // removePassenger()
