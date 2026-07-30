#include <Geode/binding/PauseLayer.hpp>
#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include "MyUtils.hpp"
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/binding/MenuLayer.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>
#include <Geode/ui/Layout.hpp>


using namespace geode::prelude;

class $modify(myPauseLayer, PauseLayer) {
	
	void customSetup() {
		PauseLayer::customSetup(); 
		
		auto chatbuttonSprite = CircleButtonSprite::create(
			CCSprite::create("chat-bubble.png"_spr),
			CircleBaseColor::DarkAqua,
			CircleBaseSize::MediumAlt
		);
auto button = CCMenuItemSpriteExtra::create(
	chatbuttonSprite,
	this,
	menu_selector(myPauseLayer::onChatButtonClick)
);
button->setLayoutOptions(
	AxisLayoutOptions::create()
	->setRelativeScale(0.6f)
);
button->setID("chat-bubble.png"_spr);
auto menu = this->getChildByID("right-button-menu");
menu->addChild(button);
menu->updateLayout();
return;
	}

	void onChatButtonClick(CCObject* sender) {
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