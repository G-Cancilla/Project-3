#include "flightMap.h"
#include <fstream>
#include <iomanip>
#include <iostream>
FlightMapClass::FlightMapClass() {
  size = 0;         // Set size to a default of 0
  flightMap = NULL; // set map to null
}
// implement the methods of the flightMap class here

FlightMapClass::~FlightMapClass() {
  size = 0;
  flightMap = NULL;
}
FlightMapClass::FlightMapClass(FlightMapClass &Flights) {
  size = Flights.size;
  flightMap = new list<flightRec>[size];
  for (int i = 0; i < size; i++) {
    Cities.push_back(Flights.Cities[i]);
  }
  for (int i = 0; i < size; i++) {
    flightMap[i] = Flights.flightMap[i];
  }
}

void FlightMapClass::ReadInCities(ifstream &theCities) {
  theCities >> size;

  string HoldCity;
  for (int i = 0; i < size; i++) {
    theCities >> HoldCity;
    Cities.push_back(HoldCity);
  }
}

void FlightMapClass::ConstructMap(ifstream &theFlights) {
  int Flight_Number;
  int price;
  string origin_city;
  string dest;

  flightRec temp;
  flightMap = new list<flightRec>[size];

  while (theFlights >> Flight_Number >> origin_city >> dest >> price) {
    temp.flightNum = Flight_Number;
    temp.origin = origin_city;
    temp.destination = dest;
    temp.price = price;

    for (int i = 0; i < size; i++) {
      if (temp.origin == Cities[i]) {
        flightMap[i].push_back(temp);
      }
    }
  }
}

void FlightMapClass::ShowMap() {
  list<flightRec> tempList;
  flightRec tempRec;
  cout << setw(20) << "Origin" << setw(20) << "Destination" << setw(8)
       << "Flight" << setw(7) << "Price" << endl;
  cout << "-------------------------------------------------------"
       << endl;
  for (int i = 0; i < size; i++) {
    if (flightMap[i].size() == 0) {
      continue;
    } else {
      cout << "From: " << setw(10) << Cities[i] << "  to:";

      tempList = flightMap[i];
      list<flightRec>::iterator it;

      for (it = flightMap[i].begin(); it != flightMap[i].end(); it++) {
        tempRec = *it;
        cout << endl;
        cout << right << setw(40) << tempRec.destination << setw(8)
             << tempRec.flightNum << setw(4) << "$" << setw(3) << tempRec.price;
      }
    }
    cout << endl;
  }
}
