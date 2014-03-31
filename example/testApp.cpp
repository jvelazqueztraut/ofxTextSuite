#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    myText.init("frabk.ttf", 24);

    myText.setText("Welcome. \nL is for Left, while R is for Right. Center it up with C, or hit J to Justify.  Press 1 to wrap constrained on x fitting the window's width, or 2 to fit type to the area.");

    //Initially wrap the text to the screen width
    myText.wrapTextX(ofGetWidth());
    
   
    //Convert text to Image
    //Get the resultaing image height to preallocate an ofPixels object
    string text2 = "This is a text converted to image. Press m to mirror it";
    float textToImgHeight = ofxTextBlock::getTextToPixelsHeight(text2, "frabk.ttf", 24, ofGetWidth()/4);
    ofPixels pixels;
    pixels.allocate(ofGetWidth()/4,textToImgHeight, OF_IMAGE_COLOR_ALPHA);
    ofxTextBlock::TextToPixels(&pixels, text2, "frabk.ttf", 24, ofGetWidth()/4, textToImgHeight);

    myTextToImage.setFromPixels(pixels);
    myTextToImage.setAnchorPercent(0.5,0.5);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    switch (alignment) {

        case OF_TEXT_ALIGN_LEFT:
            myText.draw(0,0);
            break;
        case OF_TEXT_ALIGN_RIGHT:
            myText.drawRight(ofGetWidth(), 0);
            break;
        case OF_TEXT_ALIGN_CENTER:
            myText.drawCenter(ofGetWidth()/2,0);
            break;
        case OF_TEXT_ALIGN_JUSTIFIED:
            myText.drawJustified(0, 0, myText.getWidth());
            break;

    }
    
    myTextToImage.draw(ofGetWidth()/2, ofGetHeight()/2);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    switch (key) {


        case '1':
            myText.wrapTextX(ofGetWidth());
            break;
        case '2':
            myText.wrapTextArea(ofGetWidth(), ofGetHeight());
            break;
        case 'l':
            alignment = OF_TEXT_ALIGN_LEFT;
            break;
        case 'r':
            alignment = OF_TEXT_ALIGN_RIGHT;
            break;
        case 'c':
            alignment = OF_TEXT_ALIGN_CENTER;
            break;
        case 'j':
            alignment = OF_TEXT_ALIGN_JUSTIFIED;
            break;

        case 'm':
            myTextToImage.mirror(false,true);
            break;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

