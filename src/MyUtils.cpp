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
        "Lava Chicken\n-Jack Black",
        "And it anit Keanu Reeves\n-Jack Black",
        "Your looking for Mooga\n-Vortrox",
        "Wait don't skip, then your going to miss out on these snacks\n-Chips Ahoy clone",
        "Click Between frames\n-That top 1 guy ig",
        "Try to kill as many brain cells as possible\n-GD colon",
        "I love GD Cologne\n-Wuzly",
        "AM I POSSIBLE WITH ACCURATE HITBOXES\n-GeoGD",
        "But is it even possible\n-GeoGD",
        "Is this spike possible with every hitbox\n-GeoGD",
        "My friend likes you.......\nMy friend is a worm\n-asdfmovie16",
        "I steal cheese!\nYou can't  catch me!\nHeheheheheh-[gunshots]\n-asdfmovie16",
        "In the future,\nEntertainment will be randomly generated.\n-Larry",
        "Baking soda is extremely good at absorbing oils and mositure\n-SMJS",
        "Why did you even install this mod\n-Junotrion",
        "C++ standard writers deciding what's UB by throwing blindfolded darts\n-HJfod",
        "The editor is where the men go to die\n-fleeym",
        "Wow, I can't believe they made windows 11 open source\n-mat",
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
        // @geode-ignore(unknown-resource)
        FMODAudioEngine::sharedEngine()->playEffect("achievement_01.ogg");
             }

        std::vector<std::string> quotesnotification = {
 "You can do it\n-Mr.Jim",
 "TIME TO MURDER A PLANET!!!\n-UZI",
 "Is this possible with accurate hitboxes.\n-GeoGD",
 "The mooga is ours.\n-KingSammelot",
 "The KRUSTY KRAB PIZZA, is the pizza, for you and me.\n-SpongeBob",
 "Belif creates the actual fact.\n-William James",
 "The journey of a thousand miles begins with a single step.\n-Lao Tzu",
 "The greastest pleasure of life is love.\n-Euripides",
 "I hope the kid ####### dies.\n-Denni",
 "Fire in the Hole.\n-Normal",
 "That spider part.....\n-GD Colon",
 "Ok, get in\n-SpongeBob",
 "Viprin and paste\n-Robtop",
 "That coin is kind of impossible timeing WTF\n-Doggie",
 "Launching Jeb at 1,876,710,418.3 meters per second\n-Martincitopants",
 "My supersonic ship\n-The Kinks",
 "I love GD Cologne\n-Wuzly",
 "I'm not a furry!!!\n-GD Colon",
 "I don't know, LET'S FIND OUT\n-GeoGD",
 "ACCURATE GEO GEOBOXES\n-GeoGD",
 "And now, Secret horse\n-asdfmovie16",
 "I like trains\n-asdfmovie",
 "Networking? i sure hope it does(it didn't(aws crash))\n-ninxout",
 "Reinstall geode to uninstall it\n-Cvolton",
 "what if you put all 48gb of level thumbnails on a spritesheet\n-dank_meme",
 "You ever drink soy sauce straight from the packet\n-junotrion",
 "Birds of the angry\n-junotrion",
 "The RECENT TAB\n-EVW",
    };

auto display = geode::Mod::get()->getSettingValue<double>("Death-qoutes-showtime");

geode::Notification::create(
    quotesnotification[rand() % quotesnotification.size()],
    geode::NotificationIcon::Info,
    display
)->show();

    
}

