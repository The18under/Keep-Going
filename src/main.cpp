#include <Geode/binding/PauseLayer.hpp>
#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include "MyUtils.hpp"
#include <Geode/modify/PlayLayer.hpp>



using namespace geode::prelude;

class $modify(myPauseLayer, PauseLayer) {
	
	void customSetup() {
		PauseLayer::customSetup(); 
		
		auto mybutton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_editModeBtn_001.png"),
			this, 
			menu_selector(myPauseLayer::onMybutton)

		);
		mybutton->setID("myButton"_spr);
		auto menu = this->getChildByID("right-button-menu");
		menu->addChild(mybutton);
		menu->updateLayout();
	return;
	}

	void onMybutton(CCObject* sender) {
	geode::log::info("My button clicked!");
	MotivationPopup();
	}

	
};
class $modify(MyPlayLayer,PlayLayer){
	void destroyPlayer(PlayerObject* player, GameObject* object) {
		PlayLayer::destroyPlayer(player, object);
		auto x = Mod::get()->getSettingValue<int64_t>("Death-qoutes-freqency");
if(player->m_isDead && !this->m_isPracticeMode)
	if(m_attempts % x == 0) {
		DeathNotifcation();
	}
	}
};