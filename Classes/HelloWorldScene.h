#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Weapon.h"

class BackgroundLayer : public cocos2d::Layer
{
    public:
    virtual bool init();
    void update(float dt);
    CREATE_FUNC(BackgroundLayer);
private:
    cocos2d::Sprite *background1;
    cocos2d::Sprite *background2;
};

class HintLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(HintLayer);
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);

    cocos2d::ClippingNode *clip;
    //    virtual void registerWithTouchDispatcher();
    //    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    //
    //    CCClippingNode* clip;
    //    CCSprite* tip;
private:
    int _page;
};

class HelloWorld : public cocos2d::Layer, public cocos2d::TextFieldDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void gamePauseCallback(cocos2d::Ref* pSender);
    
    void addTarget();
    void spriteMoveFinished(Node *sender);
    void gameLogic(float dt);
    void itemLogic(float dt);
    
    bool textFieldOnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    
    bool onSwipeBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onSwipeEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    
    bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF *sender);
    bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF *sender);
    void update(float dt);
    
    void activateSpells();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    
protected:
    cocos2d::Vector<cocos2d::Sprite *> _targets;
    cocos2d::Vector<cocos2d::Sprite *> _items;
    cocos2d::Vector<Weapon *> _projectiles;
    std::vector<std::string> _words;
    int _monsterNumber;
    int _projectilesDestroyed;
    cocos2d::Label *scoreLabel;
    cocos2d::Label *wordLabel;
    cocos2d::Label *timeLabel;
    cocos2d::Label *weaponLabel;
    cocos2d::Label *spellLabel;
    float _elapsedTime;
    cocos2d::TextFieldTTF *textField;
    int _shooting;
    float _reloadTime;
    float _bombReloadTime;
    int wordBomb;
    //// Fire = 0, Ice = 1, Thunder = 2.
    int _weaponType;
    float _weaponTime;
    
    cocos2d::Point startSwipe;
    cocos2d::Point endSwipe;
    bool swipeBegin;
    cocos2d::Sprite *player;
    Weapon *projectile;
    
    int _gameLevel;
    float item; //// For spamming the bullets
    cocos2d::Sprite *image;
    BackgroundLayer* _layer;
    int _swipeOrTouch; //// swipe = 0, touch = 1
    int _bossSpawning;
};



#endif // __HELLOWORLD_SCENE_H__
