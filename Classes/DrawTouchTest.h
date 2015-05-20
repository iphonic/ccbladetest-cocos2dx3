//
//  DrawTouchTest.h
//  bladetest
//
//  Created by Ved Prakash on 18/05/15.
//
//

#ifndef __bladetest__DrawTouchTest__
#define __bladetest__DrawTouchTest__

#include "cocos2d.h"


using namespace cocos2d;

class DrawTouchTest : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
   
    
    // implement the "static create()" method manually
    CREATE_FUNC(DrawTouchTest);
    
    void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags);
    
    void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
    void onTouchesMoved(const std::vector<Touch*>& touches, Event* event);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event *event);
};

#endif /* defined(__bladetest__DrawTouchTest__) */
