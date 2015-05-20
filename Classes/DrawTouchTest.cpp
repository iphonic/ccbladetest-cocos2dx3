//
//  DrawTouchTest.cpp
//  bladetest
//
//  Created by Ved Prakash on 18/05/15.
//
//

#include "DrawTouchTest.h"


USING_NS_CC;

#define kStreakFile "streak.png"
#include "CCBlade.h"

Scene* DrawTouchTest::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = DrawTouchTest::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool DrawTouchTest::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init())
    {
        return false;
    }
    
    auto touchListener = EventListenerTouchAllAtOnce::create();
    touchListener->onTouchesBegan = CC_CALLBACK_2(DrawTouchTest::onTouchesBegan, this);
    touchListener->onTouchesMoved = CC_CALLBACK_2(DrawTouchTest::onTouchesMoved, this);
    touchListener->onTouchesEnded = CC_CALLBACK_2(DrawTouchTest::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
   
    
    // add "DrawTouchTest" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}



void DrawTouchTest::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
    for (Touch* touch : touches)
    {
        
       
        
        
    }
}

void DrawTouchTest::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
{
    
    
    for (Touch* touch : touches)
    {
       
    }
}

void DrawTouchTest::onTouchesEnded(const std::vector<Touch*>& touches, Event *event){
    
    
    for (Touch* touch : touches)
    {
        
        
    }
}

void DrawTouchTest::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags){

}