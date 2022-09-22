// if late, give reason and pass # here
/*
 PROGRAMMER:   Mario Cancilla
 Program Description:
  Description of what assignment does/produces/performs/....
  Description of what program input is and form.......
  Description of what program output is and form.......
*/

#include "flightMap.h"
#include <iostream>
using namespace std;
int main() {
  FlightMapClass map, map1;
  ifstream Cities("cities.dat");
  ifstream Flights("flights.dat");

  // Read cities from a data file
  map.ReadInCities(Cities);

  // Read flight informations from a data file and build a flight map
  map.ConstructMap(Flights);

  // Display the entire map
  map.ShowMap();

  return 0;
}