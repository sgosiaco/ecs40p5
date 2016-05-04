// Author: Sean Davis

#include "flights.h"
#include "utilities.h"
#include "passenger.h"

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

const Flights& Flights::operator++()
{
  int i;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    cout << *(flights[i]);

  Flight *flight = new Flight();
  flight->addFlight();
  *this += flight;
  return *this;
} //++

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

const Flights& Flights::operator+=(Flight *flight)
{
  int i;

  if(capacity == size)
  {
    Flight **temp = flights;
    capacity *= RESIZE_MULTIPLIER;
    flights = new Flight*[capacity];

    for(i = 0; i < size; i++)
      flights[i] = temp[i];

    delete [] temp;
  } // if size == capacity

  for(i = size - 1;
    i >= 0 && flights[i]->getFlightNumber() > flight->getFlightNumber(); i--)
    flights[i + 1] = flights[i];

  flights[i + 1] = flight;
  (size)++;
  return *this;
} //+=

istream& operator>>(istream &is, Flights &flights)
{
  Flight *flight;
  int numberOfFlights;
  is >> numberOfFlights;

  for(int i = 0; i < numberOfFlights; i++)
  {
    flight = new Flight;
    is >> *flight;
    flights += flight;
  }  // for each flight

  return is;
} //>>

const Flights& Flights::operator--(int)
{
  int i, flightNumber;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    cout << *(flights[i]);

  cout << "\nFlight number to remove: ";
  cin >> flightNumber;
  cin.ignore(TEN, '\n');

  for(i = 0; i < size; i++)
    if(flights[i]->getFlightNumber() == flightNumber)
    {
      !(*(flights[i]));
      delete flights[i];

      for(; i < size - 1; i++)
        flights[i] = flights[i + 1];

      size--;
      break;
    }  // if found match of flight

  return *this;
} //--

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

void Flights::find() const
{
  char name[Passenger::NAME_LENGTH];
  cout << "\nName of passenger: ";
  cin.getline(name, Passenger::NAME_LENGTH);
  bool found = false;

  for(int i = 0; i < size; i++)
    if(flights[i]->find(name))
      found = true;

  if(!found)
      cout << name << " not found.\n";
} //find
