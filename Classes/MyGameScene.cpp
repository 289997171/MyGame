#include "MyGameScene.h"

USING_NS_CC;

Scene* MyGame::createScene()
{
    // 'scene' is an autorelease object
	// ����ͼ���еĳ���������һ���Զ��ͷŶ���
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	// ����ͼ�����
    auto layer = MyGame::create();

    // add layer as a child to scene
	// �����У����ͼ��
    scene->addChild(layer);

    // return the scene
	// ���س���
    return scene;
}

// on "init" you need to initialize your instance
bool MyGame::init()
{
    //////////////////////////////
    // 1. super init first ���ø���ĳ�ʼ������
    if ( !Layer::init() )
    {
        return false;
    }
    
	// ͨ�������ף���ó���Size��Ϣ
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
	//    ����һ������ť�ע�����ﲢ�ǰ�ť���ǰ�ť�е�һ����ڹرղ��������ð�ťĬ�Ϻ͵��״̬�µ�ͼƬ��������ӻص������ͻص�������Ҫ�Ĳ���
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MyGame::menuCloseCallback, this));
    
	// ���ð�ť������
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
	// ������ť������һ����ť���ֻ��һ����ť���ʱ����2����������ΪNULL���Դ�����
    auto menu = Menu::create(closeItem, NULL);
	// ���ð�ť����
    menu->setPosition(Vec2::ZERO);
	// ��ͼ������Ӱ�ť�������ò㼶���������ΪZ��˳��ֵԽ�󣬱�ʾ����ʾλ��Խ��ǰ
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World" ����һ����ʾHello World��Lable����
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen ����Lable������
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer ͼ������Ӹ�Lable
    this->addChild(label, 1);

    // add "MyGame" splash screen" ���MyGame��ͼƬ����
    auto sprite = Sprite::create("MyGame.png");

    // position the sprite on the center of the screen ���þ�������
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer ͼ������Ӿ���
    this->addChild(sprite, 0);
    
	// ��ʼ�����
    return true;
}

// ����¼��ص�����
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
