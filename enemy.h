#pragma once

#include <string>

class Witcher;


class Enemy
{
protected:
    const std::string name;
    int hp;
    int armor;
    int damage;

    Enemy(std::string_view name, int hp, int armor, int damage): 
    	name(name), 
    	hp(hp), 
    	armor(armor), 
    	damage(damage) 
    {}

public:
    std::string_view get_name() const;
    void take_damage(int damage);
    void attack(Witcher& herald) const;
    bool is_dead() const;
};



struct Monster: Enemy
{
protected:
	Monster(std::string_view name, int hp, int armor, int damage):
	Enemy(name, hp, armor, damage)
	{}
};

struct Draconid: Monster
{
	Draconid(std::string_view name):
	Monster(name, 
			200 + rand() % 301,
			5 + rand() % 11,
			100 + rand() % 101)
	{}
};

struct Ghost: Monster
{
	Ghost(std::string_view name, int hp, int armor, int damage):
	Monster(name, 
			50 + rand() % 21,
			1 + rand() % 5,
			50 + rand() % 201)
	{}
};

struct Necrophage: Monster
{
	Necrophage(std::string_view name, int hp, int armor, int damage):
	Monster(name, 
			100 + rand() % 401,
			3 + rand() % 6,
			60 + rand() % 101)
	{}
};



struct Human: Enemy
{
	Human(std::string_view name, int hp, int armor, int damage):
	Enemy(name, 
			40 + rand() % 11,
			0 + rand() % 3,
			20 + rand() % 6)
	{}
};

struct Rogue: Human
{
	Rogue(std::string_view name, int hp, int armor, int damage):
	Human(name, 
			40 + rand() % 11,
			1 + rand() % 7,
			50 + rand() % 21)
	{}
};