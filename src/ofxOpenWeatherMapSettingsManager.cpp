//
//  ofxOpenWeatherMapSettingsManager.cpp
//  ofxOpenWeatherMap
//
//  Created by Matteo on 05/11/2019.
//

#include "ofxOpenWeatherMapSettingsManager.h"


void ofxOpenWeatherMapSettingsManager::loadSettings(string filename){
    xmlSettings.load(filename);
}

string ofxOpenWeatherMapSettingsManager::getUrlBase(){
    return xmlSettings.getAttribute("ofxOpenWeatherMap:url", "base", "");
}

string ofxOpenWeatherMapSettingsManager::getUrlParams(){
    string params ="";
    xmlSettings.pushTag("ofxOpenWeatherMap");
    xmlSettings.pushTag("params");
    
    int numParams = xmlSettings.getNumTags("param");
    for(int i = 0; i < numParams; i++){
        string param = xmlSettings.getValue("param", "", i);
        params += param + "&";
    }
    
    xmlSettings.popTag();
    xmlSettings.popTag();
    
    return params;
}

string ofxOpenWeatherMapSettingsManager::getAuthenticationApiKey(){
    return xmlSettings.getAttribute("ofxOpenWeatherMap:authentication", "apiKey", "");
}
