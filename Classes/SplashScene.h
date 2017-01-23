#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"
class Splash : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void onEnter();
	void finishSplash(float dt);

    
    // implement the "static create()" method manually
    CREATE_FUNC(Splash);
};

#endif // __SPLASH_SCENE_H__
