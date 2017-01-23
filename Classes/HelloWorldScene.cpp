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
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("my_hello_world.plist");

	auto helloWorld = Sprite::createWithSpriteFrameName("hello_world_01.png");
	
	auto moveBy = MoveBy::create(2, Vec2(200, 0));
	auto rotateBy = RotateBy::create(2, 360);
	auto scaleBy = ScaleBy::create(2, 2.5f);
	auto fadeIn = FadeIn::create(2.0f);

	

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(10);
	animFrames.pushBack(SpriteFrame::create("hello_world_01.png", Rect(0, 0, helloWorld->getContentSize().width, helloWorld->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_02.png", Rect(0, 0, helloWorld->getContentSize().width, helloWorld->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_03.png", Rect(0, 0, helloWorld->getContentSize().width, helloWorld->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_04.png", Rect(0, 0, helloWorld->getContentSize().width, helloWorld->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_05.png", Rect(0, 0, helloWorld->getContentSize().width, helloWorld->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_06.png", Rect(0, 0, helloWorld->getContentSize().width, helloWorld->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_07.png", Rect(0, 0, helloWorld->getContentSize().width, helloWorld->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_08.png", Rect(0, 0, helloWorld->getContentSize().width, helloWorld->getContentSize().height)));
	Animation* myAnimation = Animation::createWithSpriteFrames(animFrames,0.1f);
	auto frameAnimation = RepeatForever::create(Animate::create(myAnimation));
	auto repeatedFade = RepeatForever::create(fadeIn);
	helloWorld->runAction(frameAnimation);
	helloWorld->runAction(Spawn::create(moveBy, rotateBy,  nullptr));
	
	helloWorld->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
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