#include "MyGameScene.h"

USING_NS_CC;

Scene* MyGame::createScene()
{
    // 'scene' is an autorelease object
	// 创建图层中的场景对象。是一个自动释放对象
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	// 创建图层对象
    auto layer = MyGame::create();

    // add layer as a child to scene
	// 场景中，添加图层
    scene->addChild(layer);

    // return the scene
	// 返回场景
    return scene;
}

// on "init" you need to initialize your instance
bool MyGame::init()
{
    //////////////////////////////
    // 1. super init first 调用父类的初始化函数
    if ( !Layer::init() )
    {
        return false;
    }
    
	// 通过导演雷，获得场景Size信息
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
	//    创建一个按按钮项，注意这里并非按钮而是按钮中的一项，用于关闭操作，设置按钮默认和点击状态下的图片，并且添加回调函数和回调函数需要的参数
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MyGame::menuCloseCallback, this));
    
	// 设置按钮的坐标
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
	// 创建按钮，设置一个按钮项，当只有一个按钮项的时，第2个参数设置为NULL，以此类推
    auto menu = Menu::create(closeItem, NULL);
	// 设置按钮坐标
    menu->setPosition(Vec2::ZERO);
	// 在图层中添加按钮，并设置层级，可以理解为Z轴顺序，值越大，表示其显示位置越靠前
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World" 创建一个显示Hello World的Lable对象
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen 设置Lable的坐标
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer 图层中添加该Lable
    this->addChild(label, 1);

    // add "MyGame" splash screen" 添加MyGame的图片精灵
    auto sprite = Sprite::create("MyGame.png");

    // position the sprite on the center of the screen 设置精灵坐标
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer 图层中添加精灵
    this->addChild(sprite, 0);
    
	// 初始化完毕
    return true;
}

// 点击事件回调函数
void MyGame::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
