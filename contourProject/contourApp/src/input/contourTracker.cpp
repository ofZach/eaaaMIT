

#include "contourTracker.h"

//---------------------------------------------------------------
void contourTracker::setup(){
    
    resampleAmt = 200;
    smoothing = 0.6;
}


//---------------------------------------------------------------
void contourTracker::analyze( ofPolyline & curFrame ){
    
    
    ofPolyline line = curFrame;
 
    
    // A++ if you fix getResampledByCount end points !
    //
    
    ofPolyline resampled = line.getResampledByCount( resampleAmt );
    
    // getResampledByCount sometimes is imprecise :(
    while(resampled.size() < resampleAmt){
        resampled.getVertices().push_back(resampled[resampled.size()-1]);
    }
    
 
    if (prevFrame.size() > 0){
        
        // if you want to make this faster
        // you will get an A +
        // this is pretty slow :(
        // but it works.
        
        int smallestStart = -1;
        float smallestAvgLen = 10000000;
        
        for (int i = 0; i < resampleAmt; i++){
            
            float avgLen = 0;
            for (int j = 0; j < resampleAmt; j++){
                avgLen += (resampled[ (j + i ) % resampleAmt] - prevFrame[j]).length() / (float)resampleAmt;
            }
            if (avgLen < smallestAvgLen){
                smallestAvgLen = avgLen;
                smallestStart = i;
            }
            
        }
        
        ofPolyline temp;
        for (int i = 0; i < resampleAmt; i++){
            temp.addVertex( resampled[ (i + smallestStart) % resampleAmt]);
        }
        resampled = temp;
        
        
        
    }
    
    ofPolyline tempT = resampled;
    
    if (resampleSmoothed.size() == 0){
        resampleSmoothed = tempT;
    } else {
        for (int i = 0; i < resampleAmt; i++){
            resampleSmoothed[i] = smoothing * resampleSmoothed[i] + (1-smoothing) * tempT[i];
        }
    }
    
    prevFrame = resampled;

}


//---------------------------------------------------------------
void contourTracker::draw(){
}
