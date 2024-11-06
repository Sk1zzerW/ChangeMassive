#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
using namespace std;

class Weapon {
private:
    std::string name;
    int damage;

public:
    Weapon(const std::string& name = "", int damage = 0) : name(name), damage(damage) {}

    std::string getName() const { return name; }
    int getDamage() const { return damage; }

    void setName(const std::string& name) { this->name = name; }
    void setDamage(int damage) { this->damage = damage; }
};

class Unit {
protected:
    std::string name;
    int health;
    std::shared_ptr<Weapon> weapon;

public:
    Unit(const std::string& name = "", int health = 100, const std::shared_ptr<Weapon>& weapon = nullptr)
        : name(name), health(health), weapon(weapon) {}

    std::string getName() const { return name; }
    int getHealth() const { return health; }
    std::shared_ptr<Weapon> getWeapon() const { return weapon; }

    void setName(const std::string& name) { this->name = name; }
    void setHealth(int health) { this->health = health; }
    void setWeapon(const std::shared_ptr<Weapon>& weapon) { this->weapon = weapon; }
};

class Team {
private:
    std::vector<std::shared_ptr<Unit>> units;

public:
    void addUnit(const std::shared_ptr<Unit>& unit) {
        units.push_back(unit);
    }

    void displayUnits() const {
        for (const auto& unit : units) {
            cout << "Значеник " << unit->getName() << ", Здоровбе " << unit->getHealth() << endl;
        }
    }
};
