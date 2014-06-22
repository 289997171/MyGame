#include "AppDelegate.h"
#include "MyGameScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

// Ӧ�ó��������󽫵����������Ĭ�ϵ�ʵ�������Ѿ���������Ϸ�����ı�Ҫ׼��
bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director ��ʼ������
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS �Ƿ���ʾFPS��Ϣ
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
	// ����FPS�����û��Ƽ���������ʾ60֡
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
	// ������������һ���Զ��ͷŵĶ���
    auto scene = MyGame::createScene();

    // run ���г���
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
// ��Ӧ�ó�������̨�󣬻���øú�����һ������»���ͣ��Ϸ��������������Ч�ȣ�����������ͣʱһ����Ч��
void AppDelegate::applicationDidEnterBackground() {
	// ֹͣ����
    Director::getInstance()->stopAnimation();

	// ���ʹ����SimpleAudioEngine��Ч���棬��ô����Ӧ�õ���������Ч��ͣ
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// �ú�����applicationDidEnterBackground��Ӧ����ʾ����Ӻ�̨�ָ���ǰ̨ʱ�����ã���ô����������Ϸ��������������Ч�ȵȡ�
// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	// ��ʼ����
    Director::getInstance()->startAnimation();

	// ���ʹ����SimpleAudioEngine��Ч���棬��ô����Ӧ�õ���������Ч�ָ�
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
