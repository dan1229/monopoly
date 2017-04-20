//#include "mono.h"
//#include <string>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//Player(string n, string p) {
//	name = n;
//	piece = p;
//	money = 1500;
//	location = 0;
//	inJail = false;
//	jailTime = 0;
//	doubleTime = 0;
//	hasMonopoly = false;
//	vector<Property*> properties;
//	vector<string> monoColors;
//}
//
//string getName() {
//	return name;
//}
//
//string getPiece() {
//	return piece;
//}
//
//int getMoney() {
//	return money;
//}
//
//void setMoney(int m) {
//	money = m;
//}
//
//void addMoney(int m) {
//	money += m;
//}
//
//void subtractMoney(int m) {
//	money -= m;
//}
//
//int getLocation() {
//	return location;
//}
//
//bool getJail() {
//	return inJail;
//}
//
//void changeJail() {
//	inJail = !inJail;
//}
//
//int getJailTime() {
//	return jailTime;
//}
//
//void setJailTime(int time) {
//	jailTime = time;
//}
//
//int getDoubleTime() {
//	return doubleTime;
//}
//
//void setDoubleTime(int time) {
//	doubleTime = time;
//}
//
//void setLocation(int loc) {
//	location = loc;
//}
//
//void setMonopoly(bool mono) {
//	hasMonopoly = mono;
//}
//
//bool getMonopoly() {
//	return hasMonopoly;
//}
//
//bool addLocation(int addSpaces) {
//	int prevLoc = location;
//	location = (location + addSpaces) % 32;
//	if (location - prevLoc < 0) {
//		return true;
//	}
//	return false;
//}
//
//void addProperty(Property* property) {
//	properties.push_back(property);
//}
//
//vector<Property*> getProperties() {
//	return properties;
//}
//
//vector<string> getColors() {
//	return monoColors;
//}
//
//void addColors(string color) {
//	monoColors.push_back(color);
//}
