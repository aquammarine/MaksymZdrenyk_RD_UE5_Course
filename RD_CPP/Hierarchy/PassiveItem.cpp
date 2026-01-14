#include "PassiveItem.h"

PassiveItem::PassiveItem(const Stats& bonus, const std::string& icon)
    : Item(icon), bonusStats(bonus) {
};

const Stats& PassiveItem::getBonusStats() const {
    return bonusStats;
}