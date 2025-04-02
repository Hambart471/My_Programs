// Virtual Override

#include <iostream>

// Abstract base class
// This means you cannot instantiate an object of Item directly
class Item
{
public:
	// Pure virtual method
	virtual void getDurability() = 0;
};

class Gun :public Item
{
public:
	void getDurability() override
	{
		std::cout << "Gun durability: 100/100\n";
	}
	virtual void shoot()
	{
		std::cout << "BANG!\n";
	}
};

class SubmachineGun :public Gun
{
public:
	void getDurability() override
	{
		std::cout << "Submachine Gun durability: 100/100\n";
	}
	void shoot() override
	{
		std::cout << "BANG! BANG! BANG!\n";
	}
};

class Player
{
public:
	void shoot(Gun& gun)
	{
		gun.shoot();
	}
	void checkDurability(Item& item)
	{
		item.getDurability();
	}
};

int main()
{
	Gun gun;
	gun.getDurability();
	gun.shoot();

	std::cout << '\n';
	SubmachineGun submachineGun;
	submachineGun.getDurability();
	submachineGun.shoot();

	std::cout << '\n';
	Item* pItem = &gun;
	pItem->getDurability();
	pItem = &submachineGun;
	pItem->getDurability();

	std::cout << '\n';
	Gun* pGun = &gun;
	pGun->shoot();
	pGun = &submachineGun;
	pGun->shoot();

	std::cout << '\n';
	Player player;
	player.checkDurability(gun);
	player.checkDurability(submachineGun);

	std::cout << '\n';
	player.shoot(gun);
	player.shoot(submachineGun);
}