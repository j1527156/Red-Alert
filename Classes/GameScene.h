//��Ϸ����

#ifndef __GameScene_H_
#define __GameScene_H_
#include"cocos2d.h"
#include<iostream>
#include"MyUtility.h"
#include"ConstUtil.h"
#include"MenuScene.h"
#include"Buildings/Buildings.h"

USING_NS_CC;



class GameScene :public Layer
{
public:

	static Scene *creatScene();
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	CREATE_FUNC(GameScene);

private:
	//EventListenerTouchOneByOne * touchBuildingListener;

	void backToMenuScene(Ref *pSender);//����MenuScene
	void buildingsCreate(Ref *pSender);//ѡ�����ｨ�죬������˵��ص�����

	void casernReady(float dt);//��Ӫ׼��
	//////////////////////////////
	//�����������������׼������
	//////////////////////////////

	void moneyUpdate(float dt);//ʵʱˢ�½�Ǯ

	int Money;//��Ǯ
};


#endif // !__GameScene_H_