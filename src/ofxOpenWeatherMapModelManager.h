//
//  ofxOpenWeatherMapModelManager.hpp
//  ofxOpenWeatherMap
//
//  Created by Matteo on 05/11/2019.
//

#ifndef ofxOpenWeatherMapModelManager_hpp
#define ofxOpenWeatherMapModelManager_hpp

#include <stdio.h>
#include "ofxOpenWeatherMapModel.h"
#include "ofxXmlSettings.h"

class ofxOpenWeatherMapModelManager{
public:
    static void updateModel(ofxXmlSettings &xml, ofxOpenWeatherMapModel &model);
};

#endif /* ofxOpenWeatherMapModelManager_hpp */
