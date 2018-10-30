

#include "myCoolScene.h"

//---------------------------------------------------------------
void myCoolScene::setup(){
    

}


//---------------------------------------------------------------
void myCoolScene::update(){
   
    
}


//---------------------------------------------------------------
void myCoolScene::draw(){
    
    
    //CT->resampleSmoothed.draw();
    
    ofPoint midPt;
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        midPt += CT->resampleSmoothed[i];
    }
    midPt /= (float)CT->resampleSmoothed.size();
    
    
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        ofLine(midPt, CT->resampleSmoothed[i]);
    }
        
    
//    for (int i = 0; i < CT->resampleSmoothed.size(); i+=5){
//        ofDrawCircle(CT->resampleSmoothed[i], 3);
//    }
    
    
}
