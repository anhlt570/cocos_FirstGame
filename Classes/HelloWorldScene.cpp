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

	auto myLabel = Label::createWithTTF("This is my fucking first game !!!", "fonts/Marker Felt.ttf", 24);
	myLabel->setPosition(visibleSize.width / 2, visibleSize.height - myLabel->getContentSize().height / 2);
	this->addChild(myLabel);

	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		[&](Ref* sender)
	{
		Director::getInstance()->end();
	});

	auto nextSceneButton = MenuItemLabel::create(Label::create("Next scene", "Arial", 24), 
		[&](Ref *sender)
	{
		Director::getInstance()->pushScene(SmileFace::createScene());
	});
	
	Vector<MenuItem*> myMenuItems;
	myMenuItems.pushBack(closeItem);
	myMenuItems.pushBack(nextSceneButton);
	auto myMenu = Menu::createWithArray(myMenuItems);
	myMenu->alignItemsVertically();
	this->addChild(myMenu,1);

	

	

	spriteCache->addSpriteFramesWithFile("my_hello_world.plist");
	auto lion = Sprite::createWithSpriteFrameName("hello_world_01.png");
	auto moveBy = MoveBy::create(2, Vec2(200, 0));
	auto rotateBy = RotateBy::create(2, 360);
	auto scaleBy = ScaleBy::create(2, 2.5f);
	auto fadeIn = FadeIn::create(2);
	auto fadeOut = FadeOut::create(2);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(10);
	animFrames.pushBack(SpriteFrame::create("hello_world_01.png", Rect(0, 0, lion->getContentSize().width, lion->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_02.png", Rect(0, 0, lion->getContentSize().width, lion->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_03.png", Rect(0, 0, lion->getContentSize().width, lion->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_04.png", Rect(0, 0, lion->getContentSize().width, lion->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_05.png", Rect(0, 0, lion->getContentSize().width, lion->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_06.png", Rect(0, 0, lion->getContentSize().width, lion->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_07.png", Rect(0, 0, lion->getContentSize().width, lion->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("hello_world_08.png", Rect(0, 0, lion->getContentSize().width, lion->getContentSize().height)));
	Animation* myAnimation = Animation::createWithSpriteFrames(animFrames,0.1f);
	auto frameAnimation = RepeatForever::create(Animate::create(myAnimation));
	auto fadedAnimation = RepeatForever::create(Sequence::create(fadeIn,fadeOut,nullptr));
	lion->runAction(frameAnimation);
	lion->runAction(Spawn::create(moveBy, rotateBy,  nullptr));
	lion->runAction(fadedAnimation);
	lion->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
	this->addChild(lion);

	auto crab = Sprite::create("crab.png");
	crab->setPosition(crab->getContentSize().width / 2, visibleSize.height - crab->getContentSize().height / 2);
	this->addChild(crab);
	auto crabMove = MoveBy::create(2,Vec2(0,-200));
	auto crabMoveBack = crabMove->reverse();
	auto crabMoveEaseIn = EaseIn::create(crabMove,0.5f);
	auto crabSeqAction = Sequence::create(crabMoveEaseIn, crabMoveBack, nullptr);
	crab->runAction(RepeatForever::create(crabSeqAction));

    return true;
}

void HelloWorld::menuClosedCallback()
{

}