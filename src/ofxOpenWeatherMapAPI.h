//
//  ofxWeatherMapAPI.hpp
//  ofxOpenWeatherMap
//
//  Created by Matteo on 05/11/2019.
//

#ifndef ofxWeatherMapAPI_hpp
#define ofxWeatherMapAPI_hpp

#include <stdio.h>
#include<string>
#include "ofxOpenWeatherMapSettingsManager.h"
#include "ofxOpenWeatherMapModel.h"
#include "ofxOpenWeatherMapModelManager.h"

using namespace std;

class ofxOpenWeatherMapAPI {

public:
    ofxOpenWeatherMapAPI();
    
    ofEvent<ofxOpenWeatherMapAPI> newData;

    void setup(string settingsXml);
    void setup(string url, string params, string apiKey);
    
    void urlResponse(ofHttpResponse &httpResponse);
    void requestAsyncDataFromAPI();

    void setPickupPeriod(int seconds){pickupPeriod=seconds;}
    int getPickupPeriod(){return pickupPeriod;}
    bool isLoadedData(){return bLoadedData;}
    bool isRequestData(){return bRequestData;}

    ofxXmlSettings &getXmlData(){return xmlData;}
    ofxOpenWeatherMapModel &getModel(){return model;}
    
protected:
    bool bLoadedData, bRequestData;
    string fullUrl;
    string url, params, apiKey;
    int pickupPeriod = 60;
    
    ofxOpenWeatherMapModel model;
    ofxXmlSettings xmlData;
};

#endif /* ofxWeatherMapAPI_hpp */
