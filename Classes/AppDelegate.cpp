#include "AppDelegate.h"
#include "MyGameScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

// 应用程序启动后将调用这个方法默认的实现中有已经包含了游戏启动的必要准备
bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director 初始化导演
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS 是否显示FPS信息
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
	// 设置FPS，设置绘制间隔，这里表示60帧
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
	// 创建场景，是一个自动释放的对象
    auto scene = MyGame::createScene();

    // run 运行场景
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
// 当应用程序进入后台后，会调用该函数，一般情况下会暂停游戏，包含动作，音效等，可以理解和暂停时一样的效果
void AppDelegate::applicationDidEnterBackground() {
	// 停止动画
    Director::getInstance()->stopAnimation();

	// 如果使用了SimpleAudioEngine音效引擎，那么这里应该调用以下音效暂停
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// 该函数与applicationDidEnterBackground对应，表示程序从后台恢复到前台时被调用，那么这里会继续游戏，包含动作，音效等等。
// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	// 开始动画
    Director::getInstance()->startAnimation();

	// 如果使用了SimpleAudioEngine音效引擎，那么这里应该调用以下音效恢复
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
