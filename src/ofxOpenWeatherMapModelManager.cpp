//
//  ofxOpenWeatherMapModelManager.cpp
//  ofxOpenWeatherMap
//
//  Created by Matteo on 05/11/2019.
//

#include "ofxOpenWeatherMapModelManager.h"

void ofxOpenWeatherMapModelManager::updateModel(ofxXmlSettings &xml, ofxOpenWeatherMapModel &model){
    
    xml.pushTag("current");
    
    model.city.id = xml.getAttribute("city", "id", 0);
    model.city.name = xml.getAttribute("name", "name", "");
    
    xml.pushTag("city");
    model.city.coord.lat = xml.getAttribute("coord", "lat", 0);
    model.city.coord.lon = xml.getAttribute("coord", "lon", 0);

    model.city.country = xml.getValue("country", "country");
    model.city.timezone = xml.getValue("timezone", 0);

    model.city.sun.rise = xml.getAttribute("sun", "rise", 0);
    model.city.sun.set = xml.getAttribute("sun", "set", 0);
    xml.popTag();

    model.temperature.value = xml.getAttribute("temperature", "value", 0.0);
    model.temperature.min = xml.getAttribute("temperature", "min", 0.0);
    model.temperature.max = xml.getAttribute("temperature", "max", 0.0);
    model.temperature.unit = xml.getAttribute("temperature", "unit", "");
    
    model.humidity.value = xml.getAttribute("humidity", "value", 0);
    model.humidity.unit = xml.getAttribute("humidity", "unit", "");

    model.pressure.value = xml.getAttribute("pressure", "value", 0);
    model.pressure.unit = xml.getAttribute("pressure", "unit", "");

    xml.pushTag("wind");
    model.wind.speed.value = xml.getAttribute("speed", "value", 0);
    model.wind.speed.unit = xml.getAttribute("speed", "unit", "");
    model.wind.speed.name = xml.getAttribute("speed", "name", "");
    model.wind.direction.value = xml.getAttribute("direction", "value", 0);
    model.wind.direction.code = xml.getAttribute("direction", "code", "");
    model.wind.direction.name = xml.getAttribute("direction", "name", "");
    xml.popTag();
    
    model.clouds.value = xml.getAttribute("clouds", "value", 0);
    model.clouds.name = xml.getAttribute("clouds", "value", 0);

    model.visibility.value = xml.getAttribute("visibility", "value", 0);
    model.precipitation.value = xml.getAttribute("precipitation", "value", 0);
    model.precipitation.mode = xml.getAttribute("precipitation", "mode", "");
    
    model.weather.number = xml.getAttribute("weather", "number", 0);
    model.weather.value= xml.getAttribute("weather", "value", "");
    model.weather.icon = xml.getAttribute("weather", "icon", "");

    model.lastUpdate.value = xml.getAttribute("lastupdate", "value", "");

    xml.popTag();
    
    model.timeLastUpdate = time(0);

    return model;
}
