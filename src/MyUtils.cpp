#include <Geode/Geode.hpp>
#include "MyUtils.hpp"
#include <vector>
#include <string>
#include <cstdlib> 

void MotivationPopup() {
    
    std::vector<std::string> quotes = {
        "Do what you can, with what you have, where you are.\n-Theodore Roosevelt",
        "You can do it.\n-Mr.Jim",
        "Get back on the Level, wait wrong stream my bad.\n-MindCap",
        "Is this possible with negative hitboxes.\n-GeoGD",
        "All our dreams can come true, if we have the courage in pursue them.\n-Walt Disney",
        "Nothing is impossible. The word itself says I'm possible.\n-Audrey Hepburn",
        "Every level needs a triple spike.\n-Michigun",
        "Doubt kills more dreams than failure ever will.\n-Suzy Kassem",
        "Keep your face always towards the sunshine,and shadows will fall behind you.\n-Walt Whitman",
        "Whether you think you can or you cant't, you're right.\n-Henry Ford",
        "The happiness of your life depends on the quality of your thoughts.\n-Marcus Aurelius",
        "You do not find the happy life.You make it.\n-Camilla Eyring Kimball",
        "Folks are usually about as happy as they make their mindds to be.\n-Abraham Lincoln",
        "Swag\n-Roit",
        "Black Hole, Save me\n-Marker(BFDI)",
        "FINE\n-One(BFDI)",
        "PRACTICE MODE!!\n-Dorami",
        "Lava Chicken\n-Jack Black,",
        "And it anit Keanu Reeves\n-Jack Black",
        "Your looking for Mooga\n-Vortrox",
    };

    
    
    FLAlertLayer::create(
        "Motivation Quote",
        quotes[rand() % quotes.size()],
        "OK"
    )->show();
}

    void DeathNotifcation() {

        auto SFX = geode::Mod::get()->getSettingValue<bool>("Enable-death-SFX");
	if(SFX) {
        FMODAudioEngine::sharedEngine()->playEffect("achievement_01.ogg");
             }

        std::vector<std::string> quotesnotification = {
 "You can do it\n-Mr.Jim",
 "TIME TO MURDER A PLANET!!!\n-UZI",
 "Is this possible with accurate hitboxes.\n- GeoGD",
 "The mooga is ours.\n-KingSammelot",
 "The KRUSTY KRAB PIZZA, is the pizza, for you and me.\n- SpongeBob",
 "Belif creates the actual fact.\n-William James",
 "The journey of a thousand miles begins with a single step.\n-Lao Tzu",
 "The greastest pleasure of life is love.\n-Euripides",
 "I hope the kid ####### dies.\n-Denni",
 "Fire in the Hole.\n-Normal",
 "That spider part.....\n GD colon"
    };

geode::Notification::create(
    quotesnotification[rand() % quotesnotification.size()],
    geode::NotificationIcon::Info,
    3.0f
)->show();

    
}

