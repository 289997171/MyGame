#ifndef __MyGame_SCENE_H__
#define __MyGame_SCENE_H__

#include "cocos2d.h"

// MyGame是一个场景，继承Layer图层
class MyGame : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	// 在层下设置一个创建场景的静态函数
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	// 初始化场景
    virtual bool init();  
    
    // a selector callback
	// 鼠标，触控事件回调
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
	// 通过宏，实现了static create()
    CREATE_FUNC(MyGame);
};

#endif // __MyGame_SCENE_H__
