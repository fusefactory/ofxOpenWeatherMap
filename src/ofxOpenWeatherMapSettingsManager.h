//
//  ofxOpenWeatherMapSettingsManager.hpp
//  ofxOpenWeatherMap
//
//  Created by Matteo on 05/11/2019.
//

#ifndef ofxOpenWeatherMapSettingsManager_hpp
#define ofxOpenWeatherMapSettingsManager_hpp

#include <stdio.h>
#include "ofxXmlSettings.h"

class ofxOpenWeatherMapSettingsManager{
public:
    void loadSettings(string filename);
    string getUrlBase();
    string getUrlParams();
    string getAuthenticationApiKey();
private:
    ofxXmlSettings xmlSettings;
};
#endif /* ofxOpenWeatherMapSettingsManager_hpp */
