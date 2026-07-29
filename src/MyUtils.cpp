#include <Geode/Geode.hpp>
#include <Geode/ui/Notification.hpp>
#include "MyUtils.hpp"
#include <vector>
#include <string>
#include <cstdlib> 

void MotivationPopup() {
    
    std::vector<std::string> quotes = {
        "Do what you can, with what you have, where you are. --Theodore Roosevelt",
        "You can do it. -- Mr.Jim",
        "time to murder a Planet. -- UZI",
        "Get back on the Level, wait wrong stream my bad. -- MindCap",
        "Is this possible with accurate hitboxes. -- GeoGD",
        "All our dreams can come true, if we have the courage in pursue them. -- Walt Disney",
        "Nothing is impossible. The word itself says I'm possible -- Audrey Hepburn",
        "Every level needs a triple spike -- Michigun",
    };

    
    
    FLAlertLayer::create(
        "Motivation Quote",
        quotes[rand() % quotes.size()],
        "OK"
    )->show();
}

    void DeathNotifcation() {
 
        std::vector<std::string> quotesnotification = {
 "You can do it. -- Mr.Jim",
 "time to murder a Planet. -- UZI",
 "Is this possible with accurate hitboxes. -- GeoGD",
    };
geode::Notification::create(
    quotesnotification[rand() % quotesnotification.size()],
    geode::NotificationIcon::Info,
    3.0f
)->show();

    }

