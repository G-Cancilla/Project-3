#include "flightMap.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

// Define the overloaded methods for struct type here
bool flightRec::operator<(const flightRec &rhs) const {
  if (destination < rhs.destination) {
    return true;
  } else {
    return false;
  }
}

bool flightRec::operator==(const flightRec &rhs) const {
  if ((origin == rhs.origin) && (destination == rhs.destination)) {
    return true;
  } else {
    return false;
  }
}

ostream &operator<<(ostream &outputStream, const flightRec &flights) {
  outputStream << setw(12) << flights.origin << setw(12) << flights.destination
               << setw(8) << flights.flightNum << setw(12) << "Price: $"
               << flights.price << endl;
  return outputStream;
}