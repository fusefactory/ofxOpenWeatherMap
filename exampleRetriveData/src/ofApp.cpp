#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofAddListener(openWeatherMapAPI.newData, this, &ofApp::newDataOfxOpenWeatherMap);
    openWeatherMapAPI.setup("openWeatherMap.xml");
    openWeatherMapAPI.requestAsyncDataFromAPI();
}

void ofApp::newDataOfxOpenWeatherMap(ofxOpenWeatherMapAPI & openWeatherMapAPI){
    cout << "newDataOfxOpenWeatherMap" << endl;
    openWeatherMapAPI.getXmlData().save("data.xml");   //save to file
}


//--------------------------------------------------------------
void ofApp::update(){
    time_t currTime = time(0);
    //request new data
       if(openWeatherMapAPI.isLoadedData() && currTime - openWeatherMapAPI.getModel().timeLastUpdate > openWeatherMapAPI.getPickupPeriod()){
           openWeatherMapAPI.requestAsyncDataFromAPI();   //async
       }
}



//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofDrawBitmapString("ofxOpenWeatherMap - exampleRetriveData", 10, 20);
    
    if(openWeatherMapAPI.isLoadedData()){
        
        ofxOpenWeatherMapModel &model = openWeatherMapAPI.getModel();
        
        string fullString ="";
        fullString += "Observation time: " + model.lastUpdate.value + "\n";
        fullString += "Last update: " + ofToString(model.timeLastUpdate) + "\n";
        fullString +="Pressure: " +  ofToString(model.pressure.value) + " " + model.pressure.unit + "\n";
        fullString += "Temperature: " +  ofToString(model.temperature.value) + " " + model.temperature.unit + "\n";
        fullString += "Wind speed: " +  ofToString(model.wind.speed.value) + model.wind.speed.unit + "\n";
        fullString += "Wind direction: " + ofToString(model.wind.direction.value) +  " degree"+ "\n";
                
         ofDrawBitmapString(fullString, 10, 60);
     }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
