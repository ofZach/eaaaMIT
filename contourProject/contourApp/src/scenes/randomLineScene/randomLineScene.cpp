

#include "randomLineScene.h"

//---------------------------------------------------------------
void randomLineScene::setup(){
    

}


//---------------------------------------------------------------
void randomLineScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void randomLineScene::draw(){
    
    ofSeedRandom(0);
    ofNoFill();
    
    for (int i = 1; i < CT->resampleSmoothed.size()-1; i+=2){
        int which = ofRandom(1, CT->resampleSmoothed.size()-1);
        //ofLine(CT->resampleSmoothed[i],
          //     CT->resampleSmoothed[which]);
        int iiii = i-ofGetMouseX();
        if (iiii < 0 ) iiii += CT->resampleSmoothed.size();
        int bbbb =which+ofGetMouseY();
        bbbb %= CT->resampleSmoothed.size();
        
        ofPoint aa = CT->resampleSmoothed[iiii];
        ofPoint bb = CT->resampleSmoothed[i];
        ofPoint cc = CT->resampleSmoothed[which];
        ofPoint dd = CT->resampleSmoothed[bbbb];
        
        
        
        ofDrawBezier(aa.x, aa.y, bb.x, bb.y, cc.x, cc.y, dd.x, dd.y);
//        for (int j = 0; j < 10; j+=2){
//            float pct = ofMap(j,0, 10, 0, 1);
//            float pct2 = ofMap(j+1,0, 10, 0, 1);
//            ofPoint a = ofBezierPoint(aa, bb, cc, dd, pct);
//            ofPoint b = ofBezierPoint(aa, bb, cc, dd, pct2);
//            ofLine(a,b);
//
//        }
        
    }
    
    
    
}
