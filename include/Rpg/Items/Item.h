#pragma once

#include <string>

namespace rpg::items
{

enum class ItemType
{
  Armor,
  Weapon,
  Consumable,
};

struct ItemAttributes
{
  int id{};
  ItemType type{};
  std::string name{};
  std::string description{};
  int currentQuantity{};
  int maxQuantity{};
  int weight{};
};

class Item
{

public:
  explicit Item(ItemAttributes itemAttr);
  virtual ~Item() = default;

  [[nodiscard]] int getId() const { return itemAttr_.id; }
  [[nodiscard]] ItemType getItemType() const { return itemAttr_.type; }
  static std::string getItemTypeName(ItemType type);
  [[nodiscard]] std::string getName() const { return itemAttr_.name; }
  [[nodiscard]] std::string getDescription() const { return itemAttr_.description; };
  [[nodiscard]] int getCurrentQuantity() const
  { return itemAttr_.currentQuantity; }
  [[nodiscard]] int getMaxQuantity() const { return itemAttr_.maxQuantity; }
  [[nodiscard]] int getWeight() const { return itemAttr_.weight; }

  void clampCount();
  void add(int count);
  void remove(int count);

private:
  ItemAttributes itemAttr_{};
};

} // namespace rpg::items
