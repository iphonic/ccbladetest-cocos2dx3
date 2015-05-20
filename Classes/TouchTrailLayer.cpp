/*
 * CCBlade
 *
 * Copyright (c) 2011 - Ngo Duc Hiep
 * Copyright (c) 2012 - YangLe
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "TouchTrailLayer.h"
#include "CCBlade.h"

#define kFileStreak "streak.png"

USING_NS_CC;

TouchTrailLayer::TouchTrailLayer()
{
    auto touchListener = EventListenerTouchAllAtOnce::create();
    touchListener->onTouchesBegan = CC_CALLBACK_2(TouchTrailLayer::onTouchesBegan, this);
    touchListener->onTouchesMoved = CC_CALLBACK_2(TouchTrailLayer::onTouchesMoved, this);
    touchListener->onTouchesEnded = CC_CALLBACK_2(TouchTrailLayer::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
   
}

TouchTrailLayer* TouchTrailLayer::create()
{
    TouchTrailLayer *pRet = new TouchTrailLayer();
    pRet->autorelease();
    return pRet;
}

void TouchTrailLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
    for (Touch* touch : touches) {
       
		CCBlade *blade = CCBlade::create(kFileStreak, 8, 40);
        _map[touch] = blade;
		addChild(blade);
        
        //blade->setColor(ccc3(255,120,89));
        blade->setOpacity(100);
        blade->setDrainInterval(1.0/100000);
        
        Vec2 point = convertTouchToNodeSpace(touch);
		blade->push(point);
	}
}

void TouchTrailLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
{
    for (Touch* touch : touches) {
        
        //if (_map.find(touch) == _map.end()) continue;
        
        CCBlade *blade = _map[touch];
        Vec2 point = convertTouchToNodeSpace(touch);
        point = ccpAdd(ccpMult(point, 0.6f), ccpMult(touch->getPreviousLocation(), 0.4f));
		blade->push(point);
    }
}

void TouchTrailLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *event)
{
    for (Touch* touch : touches) {
        
        //if (_map.find(touch) == _map.end()) continue;
        
        CCBlade *blade = _map[touch];
        blade->autoCleanup();
        _map.erase(touch);
    }
}