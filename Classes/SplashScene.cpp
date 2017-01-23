#include "SplashScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* Splash::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = Splash::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Splash::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto spriteCache = SpriteFrameCache::getInstance();
	auto logo = Sprite::create("HelloWorld.png");
	logo->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(logo);
    return true;
}
