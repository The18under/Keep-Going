#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include "MyUtils.hpp"
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/modify/MenuLayer.hpp>


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
auto value = Mod::get()->getSettingValue<bool>("Enable-quotes-pause");
	if(value) {
		menu->addChild(button);
		menu->updateLayout();
		 }
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

		auto death = Mod::get()->getSettingValue<bool>("Enable-quotes-death");
	
		if(death) {
		if(player->m_isDead && !this->m_isPracticeMode && m_attempts % x == 0 ) {
		DeathNotifcation(); }
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
			EditorBaseColor::DarkGray,
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

		auto options = AxisLayoutOptions::create();
		options->setNextGap(2.2f);
		myButton->setLayoutOptions(options);

		auto editbutton = Mod::get()->getSettingValue<bool>("Enable-quotes-editor");
	
	if(editbutton) {
		menu->addChild(myButton);
		menu->updateLayout();
		if(this->m_uiItems) {
		this->m_uiItems->addObject(myButton);
		}
	if(auto btnSprite = myButton->getNormalImage()) {
			btnSprite->setPositionX(btnSprite->getPositionX() - 4.0f); 
		} 
	}
	
}
	return true;
	}

	void onMyButton(CCObject* sender) {
		geode::log::info("My editor button clicked!");
		MotivationPopup();
	}
};

class $modify(MyMenuLayer, MenuLayer) {
	
 bool init() {
        if (!MenuLayer::init())
            return false;

		
		auto chatbuttonSprite = CircleButtonSprite::create(
			CCSprite::create("chat-bubble.png"_spr),
			CircleBaseColor::DarkAqua,
			CircleBaseSize::MediumAlt
		);

auto button2 = CCMenuItemSpriteExtra::create(
	chatbuttonSprite,
	this,
	menu_selector(MyMenuLayer::onChatButtonClick)
);
		button2->setLayoutOptions(
		AxisLayoutOptions::create()
			->setRelativeScale(0.9f)
);

button2->setID("chat-bubble.png"_spr);
auto menu = this->getChildByID("right-side-menu");

	auto menubutton = Mod::get()->getSettingValue<bool>("Enable-quotes-main-menu");
	
	if(menubutton) {
		menu->addChild(button2);
		menu->updateLayout();
}

return true;

 }
	void onChatButtonClick(CCObject* sender) {
	geode::log::info("My button clicked!");
	MotivationPopup();
	}

};
