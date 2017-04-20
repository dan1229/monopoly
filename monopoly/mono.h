#ifndef MONO_H_
#define MONO_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Property {

private:

	string name;
	string color;
	int location;
	int price;
	int housePrice;
	int rent[6];
	int nHouses;
	bool inMonopoly;
	int owner;

public:

	Property(string n, string c, int l, int p, int hp, int r0, int r1, int r2, int r3, int r4, int r5) {
		name = n;
		color = c;
		location = l;
		price = p;
		housePrice = hp;
		rent[0] = r0;
		rent[1] = r1;
		rent[2] = r2;
		rent[3] = r3;
		rent[4] = r4;
		rent[5] = r5;
		nHouses = 0;
		inMonopoly = false;
		owner = -1;
	}	
	
	string getName() {
		return name;
	}

	string getColor() {
		return color;
	}

	int getLocation() {
		return location;
	}

	int getPrice() {
		return price;
	}

	int getHousePrice() {
		return housePrice;
	}

	int getRent() {

		if (owner < 0) return 0;
		else if (inMonopoly && (nHouses == 0)) return rent[nHouses] * 2;
		return rent[nHouses];
	}

	int getHouses() {
		return nHouses;
	}


	void setHouses(int h) {  // if int h is b/w 0 and 5 inclusive
		nHouses = h;
	}

	int getOwner() {
		return owner;
	}

	void setOwner(int own) {
		owner = own;
	}

	bool getMonopoly() {
		return inMonopoly;
	}

	void setMonopoly(bool m) {
		inMonopoly = m;
	}


};

class Player {

private:

	string name;
	string piece;
	int money;
	int location;
	vector<Property*> properties;
	bool inJail;
	int jailTime;
	int doubleTime;
	bool hasMonopoly;
	vector<string> monoColors;

public:

	Player(string n, string p) {
		name = n;
		piece = p;
		money = 1500;
		location = 0;
		inJail = false;
		jailTime = 0;
		doubleTime = 0;
		hasMonopoly = false;
		vector<Property*> properties;
		vector<string> monoColors;
	}

	string getName() {
		return name;
	}

	string getPiece() {
		return piece;
	}

	int getMoney() {
		return money;
	}

	void setMoney(int m) {
		money = m;
	}

	void addMoney(int m) {
		money += m;
	}

	void subtractMoney(int m) {
		money -= m;
	}

	int getLocation() {
		return location;
	}

	bool getJail() {
		return inJail;
	}

	void changeJail() {
		inJail = !inJail;
	}

	int getJailTime() {
		return jailTime;
	}

	void setJailTime(int time) {
		jailTime = time;
	}

	int getDoubleTime() {
		return doubleTime;
	}

	void setDoubleTime(int time) {
		doubleTime = time;
	}

	void setLocation(int loc) {
		location = loc;
	}

	void setMonopoly(bool mono) {
		hasMonopoly = mono;
	}

	bool getMonopoly() {
		return hasMonopoly;
	}

	bool addLocation(int addSpaces) {
		int prevLoc = location;
		location = (location + addSpaces) % 32;
		if (location - prevLoc < 0) {
			return true;
		}
		return false;
	}

	void addProperty(Property* property) {
		properties.push_back(property);
	}

	vector<Property*> getProperties() {
		return properties;
	}

	vector<string> getColors() {
		return monoColors;
	}

	void addColors(string color) {
		monoColors.push_back(color);
	}

};

int rollDye();
bool jail(Player*, int&, int&);
void landOnProperty(Property*, Player*, int, vector<Player*>);
void monopoly(Player*);
void communityChest(Player*);
void chance(Player*);
bool menu(Player*, vector<Property*>);
void buildHouses(Player*, vector<Property*>);

#endif /* MONO_H_ */
