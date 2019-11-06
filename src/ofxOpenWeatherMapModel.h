//
//  ofxOpenWeatherMapCity.hpp
//  ofxOpenWeatherMap
//
//  Created by Matteo on 05/11/2019.
//

#ifndef ofxOpenWeatherMapCity_hpp
#define ofxOpenWeatherMapCity_hpp

#include <stdio.h>
#include<string>
#include <ctime>

using namespace std;

class Coordinate{
public:
    float lon;     //City geo location, longitude
    float lat;     //City geo location, latitude
};

class Sun{
public:
    string rise;                //Sunrise time
    string set;                 //Sunset time
};

class City{
public:
    int id;                       // City ID
    string name;                 //City name
    Coordinate coord;
    string country;             //Country code (GB, JP etc.)
    int timezone;       //Shift in seconds from UTC
    Sun sun;
};

class Temperature{
public:
    float value;                //Temperature
    float min;                   //Minimum temperature at the moment of calculation. This is deviation from                      'temp' that is possible for large cities and megalopolises geographically                        expanded (use these parameter optionally).
    
    
    float max;                  //Maximum temperature at the moment of calculation. This is deviation from 'temp' that is possible for large cities and megalopolises geographically expanded (use these parameter optionally).
    
    string unit;                //Unit of measurements. Possilbe valure is Celsius, Kelvin, Fahrenheit.
};

class Humidity{
public:
    int value;                 //Humidity value
    string unit;                 //units
};

class Pressure{
public:
    int value;        //Pressure value
    string unit;        //Pressure units, hPa
};

class Speed{
public:
    int value;        //Wind speed
    string unit;       //Wind speed units, m/s
    string name;        //Type of the wind
};

class Direction{
public:
    int value;        //Wind direction, degrees (meteorological)
    string code;        //Code of the wind direction. Possilbe value is WSW, N, S etc.
    string name;        //Full name of the wind direction.
};

class Wind{
public:
    Speed speed;    //Wind speed. Unit Default: meter/sec, Metric: meter/sec, Imperial: miles/hour.
    Direction direction; //Wind direction, degrees (meteorological)
};

class Clouds{
public:
    int value;        //Cloudiness
    string name;        //Name of the cloudiness
};

class Visibility{
public:
    int value;        //Visibility, meter
};

class Precipitation{
public:
    int value = 0;        //Precipitation, mm
    string mode;        //Possible values are 'no", name of weather phenomena as 'rain', 'snow'
};

class Weather{
public:
    int number;     //Weather condition id
    string value;   //Weather condition name
    string icon;    //Weather icon id
};

class LastUpdate {
public:
    string value;   //Last time when data was updated
};

class ofxOpenWeatherMapModel{
public:
    City city;
    Temperature temperature;
    Humidity humidity;
    Pressure pressure;
    Wind wind;
    Clouds clouds;
    Visibility visibility;
    Precipitation precipitation;
    Weather weather;
    LastUpdate lastUpdate;
    time_t timeLastUpdate = 0;      //last time get data from web service
};

#endif /* ofxOpenWeatherMapCity_hpp */
