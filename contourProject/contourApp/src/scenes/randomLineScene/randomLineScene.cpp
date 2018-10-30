

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
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        int which = ofRandom(0, CT->resampleSmoothed.size());
        ofLine(CT->resampleSmoothed[i],
               CT->resampleSmoothed[which]);
    }
    
    
    
}
