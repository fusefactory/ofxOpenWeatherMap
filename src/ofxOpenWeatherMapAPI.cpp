//
//  ofxWeatherMapAPI.cpp
//  ofxOpenWeatherMap
//
//  Created by Matteo on 05/11/2019.
//

#include "ofxOpenWeatherMapAPI.h"

ofxOpenWeatherMapAPI::ofxOpenWeatherMapAPI(){
    bLoadedData = false;
    bRequestData = false;
}

void ofxOpenWeatherMapAPI::setup(string settingsXml){
    ofxOpenWeatherMapSettingsManager settingsManager;
    settingsManager.loadSettings(settingsXml);
    
    string url = settingsManager.getUrlBase();
    string params = settingsManager.getUrlParams();
    string apiKey = settingsManager.getAuthenticationApiKey();
    
    setup(url, params, apiKey);
}

void ofxOpenWeatherMapAPI::setup(string url, string params, string apiKey){
    ofxOpenWeatherMapAPI::url = url;
    ofxOpenWeatherMapAPI::params = params;
    ofxOpenWeatherMapAPI::apiKey = apiKey;
    
    if(params == ""){
        params += "&";
    }
    
    fullUrl = url + params + "mode=xml&appid=" + apiKey;
    
    cout << "ofxOpenWeatherMapApi::Request url: " << fullUrl << endl;
    
    ofRegisterURLNotification(this);
}

void ofxOpenWeatherMapAPI::requestAsyncDataFromAPI(){
    if(! bRequestData){
        bRequestData = true;
        ofLoadURLAsync(fullUrl, "weatherLinkAPI");
    }
}

void ofxOpenWeatherMapAPI::urlResponse(ofHttpResponse &httpResponse){
    if(httpResponse.status == 200 ){  // i.e is it ok
        //load response
        string response = httpResponse.data.getText();
        xmlData.loadFromBuffer(response);
        
        bLoadedData = true;

        //update data
        ofxOpenWeatherMapModelManager::updateModel(xmlData, model);
        
        ofxOpenWeatherMapAPI &sender = *this;
        ofNotifyEvent(newData, sender, this);
    }
    else{
        cout << "ofxOpenWheaterMap error retriving new data" << endl;
    }
    
    bRequestData = false;
}


