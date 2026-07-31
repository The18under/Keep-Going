#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include "MyUtils.hpp"
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/EditorUI.hpp>


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

		if(player->m_isDead && !this->m_isPracticeMode && m_attempts % x == 0 ) {
		DeathNotifcation();
}

	}

};

class $modify(MyEditorUI, EditorUI) {

	bool init(LevelEditorLayer* editorLayer) {
		if(!EditorUI::init(editorLayer))
			return false;

		auto myUItexture = CCSprite::create("chat-bubble.png"_spr);
	

		auto btnSprite = EditorButtonSprite::create(
			myUItexture,
			EditorBaseColor::Gray,
			EditorBaseSize::Normal
		
		);
		
		auto myButton = CCMenuItemSpriteExtra::create(
			btnSprite,
			this,
			menu_selector(MyEditorUI::onMyButton)
		);

		

		if(auto menu = this->querySelector("editor-buttons-menu")) {
		
			geode::log::info("menu exits");

		myButton->setContentSize({40.0f, 40.0f});

		if(auto btnSprite = myButton->getNormalImage()) {
			btnSprite->setPosition({ 20.0f, 20.0f});
		}

		menu->addChild(myButton);
		menu->updateLayout();
		if(auto btnSprite = myButton->getNormalImage()) {
			btnSprite->setPositionX(btnSprite->getPositionX() - 4.0f); 
		}
	}

	return true;
	}

	void onMyButton(CCObject* sender) {
		geode::log::info("My editor button clicked!");
		MotivationPopup();
	}
};