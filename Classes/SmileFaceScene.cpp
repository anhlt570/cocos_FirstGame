#include "SmileFaceScene.h"

USING_NS_CC;

Scene* SmileFace::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = SmileFace::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SmileFace::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto logo = Sprite::create("smiley.png");
	logo->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(logo);

    return true;
}

