#include "Item.h"
#include "Stats.h"

class PassiveItem : public Item {
private:
	Stats bonusStats;

public:
	PassiveItem(const Stats& bonus, const std::string& icon);

	const Stats& getBonusStats() const;
};