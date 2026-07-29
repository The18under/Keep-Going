#include <Geode/Geode.hpp>
#include "MyUtils.hpp"
#include <vector>
#include <string>
#include <cstdlib> 

void MotivationPopup() {
    
    std::vector<std::string> quotes = {
        "Do what you can, with what you have, where you are. --Theodore Roosevelt",
        "You can do it. -- Mr.Jim",
        "time to murder a Planet",
    };
    
    FLAlertLayer::create(
        "Motivation quote from someone",
        quotes[rand() % quotes.size()],
        "OK"
    )->show();
}