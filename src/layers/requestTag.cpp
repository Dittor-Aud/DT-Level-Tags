#include "requestTag.hpp"

bool RequestTag::setup(std::vector<std::variant<std::string, bool>> level) {
    auto winSize = CCDirector::sharedDirector()->getWinSize();

    m_closeBtn->setPosition({m_mainLayer->getContentWidth() / 2, 25});
    m_closeBtn->setSprite(ButtonSprite::create("Ok"));

    this->setTitle("Request your tags!");

    auto sad = CCSprite::create("sad.png"_spr);
    sad->setPosition({m_mainLayer->getContentWidth() / 2, 95});
    sad->setOpacity(50);
    m_mainLayer->addChild(sad);

    auto bg = CCScale9Sprite::create("square02b_001.png");
    bg->setContentSize({280, 100});
    bg->setPosition({m_mainLayer->getContentWidth() / 2, 95});
    bg->setColor({0, 0, 0});
    bg->setOpacity(100);
    m_mainLayer->addChild(bg);

    std::string infoStr = "Unfortunately you cannot request tags directly here.\n"
                          "But worry not, you can request tags on discord! Just click the discord icon "
                          "to join our server, find the tag request channel, req, wait for approval, and walaa.\n"
                          "We are waiting for the official dev to rebuild the requesting system.\n"
                          "In the meantime, tag requests are on our discord.\n";

    auto info = SimpleTextArea::create(infoStr, "chatFont.fnt", 0.6, 270);
    info->setAlignment(CCTextAlignment::kCCTextAlignmentCenter);
    info->setPosition({m_mainLayer->getContentWidth() / 2, 95});
    m_mainLayer->addChild(info);

    auto discordMenu = CCMenu::create();
    discordMenu->setContentSize({0, 0});
    discordMenu->setPosition({275, 25});
    m_mainLayer->addChild(discordMenu);
    discordMenu->addChild(
        CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png"), this, menu_selector(RequestTag::discord))
    );

    return true;
}

void RequestTag::discord(CCObject* sender) {
    web::openLinkInBrowser("https://discord.gg/6GXYHf9WTB");
}

RequestTag* RequestTag::create(std::vector<std::variant<std::string, bool>> level) {
    auto ret = new RequestTag();
    if (ret->initAnchored(300.f, 180.f, level)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}
