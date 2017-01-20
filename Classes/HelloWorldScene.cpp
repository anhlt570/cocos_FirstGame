#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto helloWorld = Sprite::create("HelloWorld.png");
	helloWorld->setPosition(visibleSize.height / 2, helloWorld->getContentSize().width / 2);
	auto moveBy = MoveBy::create(2, Vec2(200, 0));
	auto rotateBy = RotateBy::create(2, 360);
	helloWorld->runAction(Spawn::create(moveBy, rotateBy, nullptr));
	this->addChild(helloWorld);

	auto lamdaFunc = [](){ };
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", 
		[&](Ref* sender)
	{
		printf("holy shit");
	});
	auto myMenu = Menu::createWithItem(closeItem);
	this->addChild(myMenu);
    return true;
}

void HelloWorld::menuClosedCallback()
{

}