#include <bits/stdc++.h>

class UndergroundSystem {
	std::unordered_map < int, std::pair <std::string, int> > id_station_start_time;
	std::unordered_map < std::string, std::pair <int, int> > all_station;
public:
   UndergroundSystem() {
   }
   void checkIn(int id, std::string stationName, int t) {
		id_station_start_time[id] = {stationName, t};
	}
   
   void checkOut(int id, std::string stationName, int t) {
		all_station[id_station_start_time[id].first + '-' + stationName];
		all_station[id_station_start_time[id].first + '-' + stationName].first += t - id_station_start_time[id].second;
		all_station[id_station_start_time[id].first + '-' + stationName].second++;
	}
   
   double getAverageTime(std::string startStation, std::string endStation) {
		return (double)all_station[startStation + '-' + endStation].first / all_station[startStation + '-' + endStation].second;
	}
};