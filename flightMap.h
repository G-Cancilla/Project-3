#include <fstream>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

#ifndef FLIGHTMAPCLASS_H
#define FLIGHTMAPCLASS_H

#include "type.h"

using namespace std;

class FlightMapClass {
public:
  // constructors and destructor
  FlightMapClass(); // default constructor

  ~FlightMapClass(); // destructor

  FlightMapClass(const FlightMapClass &); // copy constructor
                                          // FlightMapClass operations:

  // Read cities from a data file
  // Pre-condition: Input stream is provided
  // Post-condition: Data file is read
  //				  Cities are in ascending order
  void ReadInCities(ifstream &theCities);

  // Reads flight information and build the adjacency list
  // Pre-condition: list of the flight information is provided
  // Post-condition: Flight map is built

  void ConstructMap(ifstream &flights);
  // Displays the flight map in a formatted table
  // using overloaded << opererator
  // Pre-condition: none
  // Post-condition: Flight map is displayed
  void ShowMap();

private:
  int size;                   // number of cities
  vector<string> Cities;      // vector of cities
  list<flightRec> *flightMap; // flight map
};

#endif