//
//  main.cpp
//  Gui
//
//  Created by Harsh Patel on 4/1/17.
//  Copyright © 2017 PROJECT_TEAM30. All rights reserved.
//

#define _WIN32_WINNT 0x0500

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Player.cpp"
#include "Property.cpp"
#include "mono.h"
#include "Windows.h"
#include <chrono>
#include <random>
#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <direct.h>

using namespace sf;
using namespace std;

int rollDye() {

	random_device rndm;
	mt19937 generator(rndm());
	uniform_int_distribution<> range(1, 6);

	return range(generator);
}

int main(int argc, const char * argv[]) {

	//get working directory and store in filepath
	char buf[256];
	GetCurrentDirectoryA(256, buf);
	string filepath = string(buf) + "\\Resources\\";

	//Load Console
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 0, 0, 400, 800, TRUE);

	//font variables
	Font font1, font2;

	//load fonts
	if ((!font1.loadFromFile(filepath + "8-BIT WONDER.TTF")) || (!font2.loadFromFile(filepath + "Arial.ttf"))) {
		cout << "ERROR" << endl;
	}

	vector <Text> playerName;

	vector <Text> budget;

	Text propertiesText;

	//use this varibale to store input from the cosole and use the setString method which is shown on line 82 to set a string to the Text varables (they only accept strings)
	string input = "";

	propertiesText.setCharacterSize(25);
	propertiesText.setFillColor(Color::Blue);
	propertiesText.setFont(font1);
	propertiesText.setString("Properties");

	//This variable will hold the position of the player on the tile. Tile starts at Go and is value 0, tile 1 is mediterannean avenue, tile 2 is baltic avenue.....etc.
	//increase the tilecounter+=dieValue (if you want to). I made 4 because 1 for each player. You guys can decide how you wanna do it
	int tileCounter = 0;

	//Texture holds the value for each image
	//board texture
	Texture board;

	//all the pieces textures
	Texture robot;
	Texture Car;
	Texture Dog;
	Texture Iron;
	Texture Phone;
	Texture PotOfGold;
	Texture Ship;
	Texture Thimble;

	//textures for those sexy vertical and horizonal lines
	Texture vLine;
	Texture hLine;

	//all the tiles textures
	Texture tile0;
	Texture tile1;
	Texture tile2;
	Texture tile3;
	Texture tile4;
	Texture tile5;
	Texture tile6;
	Texture tile7;
	Texture tile8;
	Texture tile9;
	Texture tile10;
	Texture tile11;
	Texture tile12;
	Texture tile13;
	Texture tile14;
	Texture tile15;
	Texture tile16;
	Texture tile17;
	Texture tile18;
	Texture tile19;
	Texture tile20;
	Texture tile21;
	Texture tile22;
	Texture tile23;
	Texture tile24;
	Texture tile25;
	Texture tile26;
	Texture tile27;
	Texture tile28;
	Texture tile29;
	Texture tile30;
	Texture tile31;

	//all the property textures
	Texture prop1;
	Texture prop2;
	Texture prop3;
	Texture prop4;
	Texture prop5;
	Texture prop6;
	Texture prop7;
	Texture prop8;
	Texture prop9;
	Texture prop10;
	Texture prop11;
	Texture prop12;
	Texture prop13;
	Texture prop14;
	Texture prop15;
	Texture prop16;
	Texture prop17;
	Texture prop18;
	Texture prop19;
	Texture prop20;
	Texture prop21;
	Texture prop22;

	//loading all the pieces
	robot.loadFromFile(filepath + "Robot.png");
	Car.loadFromFile(filepath + "Car.png");
	Dog.loadFromFile(filepath + "Dog.png");
	Iron.loadFromFile(filepath + "Iron.png");
	Phone.loadFromFile(filepath + "Phone.png");
	PotOfGold.loadFromFile(filepath + "Pot of Gold.png");
	Ship.loadFromFile(filepath + "Ship.png");
	Thimble.loadFromFile(filepath + "Thimble.png");

	//loading all textures
	board.loadFromFile(filepath + "Monopoly Board.png");
	vLine.loadFromFile(filepath + "vertical line.png");
	hLine.loadFromFile(filepath + "horizontal line.png");
	tile0.loadFromFile(filepath + "Go.png");
	tile1.loadFromFile(filepath + "Mediterranian Avenue.png");
	tile2.loadFromFile(filepath + "Baltic Avenue.png");
	tile3.loadFromFile(filepath + "Income Tax.png");
	tile4.loadFromFile(filepath + "Oriental Avenue.png");
	tile5.loadFromFile(filepath + "Community Chest1.png");
	tile6.loadFromFile(filepath + "Vermont Avenue.png");
	tile7.loadFromFile(filepath + "Connecticut Avenue.png");
	tile8.loadFromFile(filepath + "Jail.png");
	tile9.loadFromFile(filepath + "St Charles Place.png");
	tile10.loadFromFile(filepath + "States Avenue.png");
	tile11.loadFromFile(filepath + "Virginia Avenue.png");
	tile12.loadFromFile(filepath + "Chance1.png");
	tile13.loadFromFile(filepath + "St James Place.png");
	tile14.loadFromFile(filepath + "Tennessee Avenue.png");
	tile15.loadFromFile(filepath + "New York Avenue.png");
	tile16.loadFromFile(filepath + "Free Parking.png");
	tile17.loadFromFile(filepath + "Kentucky Avenue.png");
	tile18.loadFromFile(filepath + "Indiana Avenue.png");
	tile19.loadFromFile(filepath + "Illinois Avenue.png");
	tile20.loadFromFile(filepath + "Community Chest2.png");
	tile21.loadFromFile(filepath + "Atlantic Avenue.png");
	tile22.loadFromFile(filepath + "Ventor Avenue.png");
	tile23.loadFromFile(filepath + "Marvin Gardens.png");
	tile24.loadFromFile(filepath + "Go To Jail.png");
	tile25.loadFromFile(filepath + "Pacific Avenue.png");
	tile26.loadFromFile(filepath + "North Carolina Avenue.png");
	tile27.loadFromFile(filepath + "Pennsylvania Avenue.png");
	tile28.loadFromFile(filepath + "Luxury Tax.png");
	tile29.loadFromFile(filepath + "Park Place.png");
	tile30.loadFromFile(filepath + "Chance2.png");
	tile31.loadFromFile(filepath + "Boardwalk.png");

	//loading all the properties
	prop1.loadFromFile(filepath + "Mediterranian Avenue Label.png");
	prop15.loadFromFile(filepath + "Atlantic Avenue Label.png");
	prop22.loadFromFile(filepath + "Boardwalk Label.png");
	prop5.loadFromFile(filepath + "Connecticut Avenue Label.png");
	prop14.loadFromFile(filepath + "Illinois Avenue Label.png");
	prop13.loadFromFile(filepath + "Indiana Avenue Label.png");
	prop2.loadFromFile(filepath + "Baltic Avenue Label.png");
	prop12.loadFromFile(filepath + "Kentucky Avenue Label.png");
	prop17.loadFromFile(filepath + "Marvin Gardens Label.png");
	prop11.loadFromFile(filepath + "New York Avenue Label.png");
	prop19.loadFromFile(filepath + "North Carolina Ave Label.png");
	prop3.loadFromFile(filepath + "Oriental Avenue Label.png");
	prop21.loadFromFile(filepath + "Park Place Label.png");
	prop20.loadFromFile(filepath + "Pennsylvania Avenue Label.png");
	prop6.loadFromFile(filepath + "St Charles Place Label.png");
	prop9.loadFromFile(filepath + "St James Place Label.png");
	prop7.loadFromFile(filepath + "States Avenue Label.png");
	prop10.loadFromFile(filepath + "Tennessee Avenue Label.png");
	prop16.loadFromFile(filepath + "Ventor Avenue Label.png");
	prop4.loadFromFile(filepath + "Vermont Label.png");
	prop8.loadFromFile(filepath + "Virginia Avenue Label.png");
	prop18.loadFromFile(filepath + "Pacific Avenue Label.png");

	//all the textures in an array
	Texture array[32] = { tile0, tile1, tile2, tile3, tile4, tile5, tile6, tile7, tile8, tile9, tile10, tile11, tile12, tile13, tile14, tile15, tile16, tile17, tile18, tile19, tile20, tile21, tile22, tile23, tile24, tile25, tile26, tile27, tile28, tile29, tile30, tile31 };

	//all the properties in a vector (shouldve done the textures in a vector too but forgot they existed at the time so oh well)
	vector <Texture> propTextures;
	propTextures.push_back(prop1);
	propTextures.push_back(prop2);
	propTextures.push_back(prop3);
	propTextures.push_back(prop4);
	propTextures.push_back(prop5);
	propTextures.push_back(prop6);
	propTextures.push_back(prop7);
	propTextures.push_back(prop8);
	propTextures.push_back(prop9);
	propTextures.push_back(prop10);
	propTextures.push_back(prop11);
	propTextures.push_back(prop12);
	propTextures.push_back(prop13);
	propTextures.push_back(prop14);
	propTextures.push_back(prop15);
	propTextures.push_back(prop16);
	propTextures.push_back(prop17);
	propTextures.push_back(prop18);
	propTextures.push_back(prop19);
	propTextures.push_back(prop20);
	propTextures.push_back(prop21);
	propTextures.push_back(prop22);

	//The Sprite variable has textures object as you can (board) (tile0)

	//You have to turn the textures into sprites in order to draw them on the screen, move them around, scale them, or anything your heart desires.
	Sprite background(board);

	Sprite robotPiece(robot);
	Sprite carPiece(Car);
	Sprite dogPiece(Dog);
	Sprite ironPiece(Iron);
	Sprite phonePiece(Phone);
	Sprite potOfGoldPiece(PotOfGold);
	Sprite shipPiece(Ship);
	Sprite thimblePiece(Thimble);

	Sprite verticalLine(vLine);
	Sprite horizontalLine(hLine);
	Sprite secHorizontalLine(hLine);

	vector <Sprite> liveTileTextures;    //holds all the tiles in a Sprite vector. Use this information to dynamically update the tiles on the screen in the live tile section on the upper right
	vector <Sprite> property;            //holds all the properties in a sprite vector. Use this information to dynamically add or remove properties on/from the screen

	//puts all the property textures in the property sprite
	for (unsigned int i = 0; i < propTextures.size(); i++) {

		Sprite newProperty;
		newProperty.setTexture(propTextures[i]);

		property.push_back(newProperty);
	}

	//puts all the tile textures in the liveTileTexture sprite
	for (int i = 0; i != 32; i++) {

		Sprite newTile;
		newTile.setTexture(array[i]);

		liveTileTextures.push_back(newTile);

	}

	liveTileTextures[tileCounter].move(1612, 0);
	verticalLine.move(1601, 0);

	horizontalLine.move(1610, 421);
	secHorizontalLine.move(1610, 1308);

	robotPiece.scale(1.5, 1.5);
	robotPiece.move(35, 1430);
	carPiece.move(40, 1450);
	dogPiece.move(40, 1450);
	ironPiece.move(40, 1450);
	phonePiece.move(40, 1450);
	potOfGoldPiece.move(40, 1450);
	shipPiece.move(40, 1450);
	thimblePiece.move(40, 1450);

	propertiesText.move(1627, 430);

	property[1].move(1620, 480);

	board.setSmooth(true);

	int nPlayers = 0;

	cout << "Welcome to Monopoly!" << endl;
	cout << "Please input the number of players (2-4): " << endl;

	while (true) {

		// user input: number of players
		cin >> nPlayers;

		// if not an integer, clear buffer and reprompt
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n');
			nPlayers = 0;
		}

		// if not between 2-4, reprompt
		if (nPlayers > 4 || nPlayers < 2) {
			cout << "Invalid input. Please try again: ";
		}
		else break;
	}

	vector<string> names;
	cout << "Please enter the names of the players: (max 10 characters)" << endl;
	for (int i = 0; i < nPlayers; i++) {

		// user input: names
		string input;
		do {
			cout << i + 1 << ". ";
			cin >> input;

			// if name is more than 10 characters, reprompt
			if (input.size() < 1 || input.size() > 10) {
				cout << "Invalid name. Please enter again." << endl;
			}
		} while (input.size() < 1 || input.size() > 10);

		// add name to names vector
		names.push_back(input);
		Text pla;
		pla.setString(input);
		playerName.push_back(pla);
		playerName.at(i).setCharacterSize(40);
		playerName.at(i).setFillColor(Color::Color(62, 70, 255, 255));
		playerName.at(i).setFont(font2);
	}

	// adding possible pieces to pieces vector
	const string pcs[] = { "DOG","ROBOT","SHIP","CAR","IRON","POT","THIMBLE","PHONE" };
	vector<string> pieces(pcs, pcs + sizeof(pcs) / sizeof(pcs[0]));

	for (unsigned int i = 0; i < playerName.size(); i++) {
		Text budgetNew;
		budgetNew.setString("Budget: $1500");
		budget.push_back(budgetNew);
		budget.at(i).setCharacterSize(35);
		budget.at(i).setFillColor(Color::Color(62, 70, 255, 255));
		budget.at(i).setFont(font2);
	}

	int move0 = 0;

	for (unsigned int i = 0; i < budget.size(); i++) {
		budget.at(i).move(1616, 1345 + move0);
		move0 = move0 + 73;

	}

	int move = 0;
	for (int i = 0; i < playerName.size(); i++) {
		playerName.at(i).move(1616, 1311 + move);
		move = move + 71;

	}

	// shows who's who
	for (int i = 0; i < nPlayers; i++) {
		cout << names[i] << " is " << pieces[i] << "." << endl;
	}

	// creates main vector of player pointers
	vector<Player*> players;
	for (int i = 0; i < nPlayers; i++) {
		Player* player = new Player(names[i], pieces[i]);
		players.push_back(player);
	}

	string propertyNames[22] = { "MEDITERRANEAN AVENUE","BALTIC AVENUE","ORIENTAL AVENUE","VERMONT AVENUE",
		"CONNECTICUT AVENUE","ST. CHARLES PLACE","STATES AVENUE","VIRGINIA AVENUE","ST. JAMES PLACE",
		"TENNESSEE AVENUE","NEW YORK AVENUE","KENTUCKY AVENUE","INDIANA AVENUE","ILLINOIS AVENUE",
		"ATLANTIC AVENUE","VENTOR AVENUE","MARVIN GARDENS","PACIFIC AVENUE","NORTH CAROLINA AVENUE",
		"PENNSYLVANIA AVENUE","PARK PLACE","BOARDWALK" };

	string propertyColor[22] = { "PURPLE","PURPLE","L. BLUE","L. BLUE","L. BLUE","PINK","PINK","PINK","ORANGE",
		"ORANGE","ORANGE","RED","RED","RED","YELLOW","YELLOW","YELLOW","GREEN","GREEN","GREEN","D. BLUE","D. BLUE" };

	int propertyPrice[22] = { 60,60,100,100,120,140,140,160,180,180,200,220,220,240,260,260,280,300,300,320,350,400 };
	int propertyHousePrice[22] = { 50,50,50,50,50,100,100,100,100,100,100,150,150,150,150,150,150,200,200,200,200,200 };
	int initialRent[22] = { 2,4,6,6,8,10,10,12,14,14,16,18,18,20,22,22,24,26,26,28,35,50 };
	int oneHouseRent[22] = { 10,20,30,30,40,50,50,60,70,70,80,90,90,100,110,110,120,130,130,150,175,200 };
	int twoHouseRent[22] = { 30,60,90,90,100,150,150,180,200,200,220,250,250,300,330,330,360,390,390,450,500,600 };
	int threeHouseRent[22] = { 90,180,270,270,300,450,450,500,550,550,600,700,700,750,800,800,850,900,900,1000,1100,1400 };
	int fourHouseRent[22] = { 160,320,400,400,450,625,625,700,750,750,800,875,875,925,975,975,1025,1100,1100,1200,1300,1700 };
	int fiveHouseRent[22] = { 250,450,550,550,600,750,750,900,950,950,1000,1050,1050,1100,1150,1150,1200,
		1275,1275,1400,1500,2000 };

	vector<Property*> properties;
	for (int i = 0; i < 22; i++) {
		Property* property = new Property(propertyNames[i], propertyColor[i], i, propertyPrice[i], propertyHousePrice[i], initialRent[i],
			oneHouseRent[i], twoHouseRent[i], threeHouseRent[i], fourHouseRent[i], fiveHouseRent[i]);
		properties.push_back(property);
	}

	//    this is WHERE ALL THE LOGIC WILL GO THAT NEEDS TO BE REPEATED. This while is responsible for maintaining/loading the gui on the screen at all times

	int turn = 0; // turn of current player
	int location = 0; // location of player
	bool doubles = false; // bool if doubles are rolled, then true
	bool passGo; // if passes go, then true
	int dice1 = 0; // dice values
	int dice2 = 0;
	Player* currPlayer; // current player's turn
	Property* propertyClass; // pointer to property at landed location

	vector<float>x;
	vector<float>y;

	for (int i = 0; i < 32; i++) {
		if (i <= 8) {
			x.push_back(35);
			y.push_back(1458 - i * 177);
		}
		if ((i > 8) && (i <= 16)) {
			x.push_back(35 + (i % 8) * 177);
			y.push_back(35);
		}
		if ((i > 16) && (i <= 24)) {
			x.push_back(1458);
			y.push_back(35 + (i % 8) * 177);
		}
		if ((i > 24) && (i <= 32)) {
			x.push_back(1458 - (i % 8) * 177);
			y.push_back(1458);
		}
	}

	//creates the window that lopads the GUI
	RenderWindow app(VideoMode(2030, 1600), "Monopoly", Style::Default);

	while (app.isOpen()) {

		app.setFramerateLimit(30);
		app.setPosition(sf::Vector2i(800, 0));

		Event e;
		while (app.pollEvent(e)) {

			if (e.type == Event::Closed) {

				app.close();

			}

		}

		// this line of code is an example of how key presses can be used but i don't think we will need it. This is just for reference
		// if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		// {
		//    // left key is pressed: move our character
		//    robotPiece.move(1, 0);
		//}

		//Places live tile
		liveTileTextures.at(location).setPosition(1610, 0);
		for (int i = 0; i < 22; i++) {
			property.at(i).setPosition(1620, 470 + (30 * i));
		}

		//This is responible for changing the background of the window
		app.clear(sf::Color(216, 255, 232, 45));     

		// .draw function is responsible for actually "drawing" or displaying our objects on the window. SO MAKE SURE YOU KNOW WHAT TO DRAW AND WHEN!!!!!!!!!!!!!
		app.draw(background);
		app.draw(liveTileTextures[location]);
		app.draw(verticalLine);
		app.draw(horizontalLine);
		app.draw(secHorizontalLine);
		app.draw(dogPiece);
		app.draw(robotPiece);

		for (int i = 0; i < 22; i++) {
			app.draw(property[i]);
			property.at(i).setPosition(1620, 40 * (15 * i));
		}

		if (nPlayers == 3) {
			app.draw(shipPiece);
		} if (nPlayers == 4) {
			app.draw(shipPiece);
			app.draw(carPiece);
		}

		for (unsigned int i = 0; i < playerName.size(); i++)
			app.draw(playerName[i]);

		for (unsigned int i = 0; i < budget.size(); i++)
			app.draw(budget[i]);

		app.draw(propertiesText);

		app.display();

		currPlayer = players[turn];

		cout << "\n" << currPlayer->getName() << "'s turn. What would you like to do?" << endl << endl;

		// move character and update budgets
		int bud = currPlayer->getMoney();
		string budStr = to_string(bud);
		budget.at(turn).setString("Budget: $" + budStr);

		// displays menu, keeps running method while not "Proceed with turn"
		while (menu(currPlayer, properties));

		// if still in jail, go to next player's turn
		if (jail(currPlayer, dice1, dice2)) {
			turn = (turn + 1) % nPlayers;
			continue;
		}

		// if just out of jail, make doubles false no matter what
		if (currPlayer->getJail()) {
			doubles = false;
			currPlayer->changeJail();
		}
		else {
			cout << "Press ENTER to roll dice." << endl;
			dice1 = rollDye();

			// halts game until ENTER pressed
			cin.ignore();
			cin.ignore();
			dice2 = rollDye();

			// determines doubles
			doubles = (dice1 == dice2) ? true : false;
			cout << "You rolled a " << dice1 << " and a " << dice2 << "." << endl;
		}

		// if doubles rolled, count number of doubles
		if (doubles) currPlayer->setDoubleTime(currPlayer->getDoubleTime() + 1);

		// if number of doubles is 3, send player to jail
		if (currPlayer->getDoubleTime() >= 3) {
			cout << currPlayer->getName() << " was sent to jail." << endl;
			currPlayer->changeJail();
			currPlayer->setLocation(8);
			currPlayer->setDoubleTime(0);
			turn = (turn + 1) % nPlayers;
			continue;
		}

		// move player by dice1 plus dice2
		passGo = currPlayer->addLocation(dice1 + dice2);

		// current location
		location = currPlayer->getLocation();

		// if passGo, collect $200
		if (passGo) {
			currPlayer->addMoney(200);
			cout << currPlayer->getName() << " passed GO. Collect $200." << endl;
		}

		// main switch for determining what to do at each space
		// for property spaces, displays location & color and runs landOnProperty()
		switch (location) {

			// Go
		case 0:
			cout << "You landed on GO!" << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			break;

			// Mediterranean Ave
		case 1:
			propertyClass = properties[0];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);
			break;

			// Baltic Ave
		case 2:
			propertyClass = properties[1];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Income Tax
		case 3:
			cout << "You landed on INCOME TAX. Pay $200." << endl;
			currPlayer->subtractMoney(200);
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }

			break;

			// Oriental Ave
		case 4:
			propertyClass = properties[2];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Comm Chest
		case 5:
			cout << "You landed on COMMUNITY CHEST #1!" << endl;
			communityChest(currPlayer);
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }

			break;

			// Vermont Ave
		case 6:
			propertyClass = properties[3];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Connecticut Ave
		case 7:
			propertyClass = properties[4];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Jail
		case 8:
			cout << "You landed on JAIL, just visiting..." << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }

			break;

			// St. Charles Pl
		case 9:
			propertyClass = properties[5];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// States Ave
		case 10:
			propertyClass = properties[6];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Virginia Ave
		case 11:
			propertyClass = properties[7];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Chance
		case 12:
			cout << "You landed on CHANCE #1!" << endl;
			chance(currPlayer);
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }

			break;

			// St. James Pl
		case 13:
			propertyClass = properties[8];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			landOnProperty(propertyClass, currPlayer, turn, players);
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			break;

			// Tennessee Ave
		case 14:
			propertyClass = properties[9];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// NY Ave
		case 15:
			propertyClass = properties[10];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Free Parking
		case 16:
			cout << "You landed on FREE PARKING!!" << endl;
			cout << "You get $500!!" << endl;
			currPlayer->addMoney(500);
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }

			break;

			// Kentucky Ave
		case 17:
			propertyClass = properties[11];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Indiana Ave
		case 18:
			propertyClass = properties[12];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Illinois Ave
		case 19:
			propertyClass = properties[13];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Comm Chest
		case 20:
			cout << "You landed on COMMUNITY CHEST #2!" << endl;
			communityChest(currPlayer);
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }

			break;

			// Atlantic Ave
		case 21:
			propertyClass = properties[14];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Ventor Ave
		case 22:
			propertyClass = properties[15];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Marvin Gardens
		case 23:
			propertyClass = properties[16];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Go to Jail
		case 24:
			cout << "GO TO JAIL." << endl;
			currPlayer->changeJail();
			currPlayer->setLocation(8);
			currPlayer->setDoubleTime(0);
			if (turn == 0) { dogPiece.setPosition(x[8], y[8]); }
			if (turn == 1) { robotPiece.setPosition(x[8], y[8]); }
			if (turn == 2) { shipPiece.setPosition(x[8], y[8]); }
			if (turn == 3) { carPiece.setPosition(x[8], y[8]); }

			break;

			// Pacific Ave
		case 25:
			propertyClass = properties[17];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// NC Ave
		case 26:
			propertyClass = properties[18];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Penn Ave
		case 27:
			propertyClass = properties[19];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Luxury Tax
		case 28:
			cout << "You landed on LUXURY TAX. Pay $200." << endl;
			currPlayer->subtractMoney(200);
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }

			break;

			// Park Place
		case 29:
			propertyClass = properties[20];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// Chance
		case 30:
			cout << "You landed on CHANCE #2!" << endl;
			chance(currPlayer);
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }

			break;

			// Boardwalk
		case 31:
			propertyClass = properties[21];
			cout << "You landed on " << propertyClass->getName() << "!" << endl;
			cout << "Location: " << location << " | Color: " << propertyClass->getColor() << endl;
			if (turn == 0) { dogPiece.setPosition(x[location], y[location]); }
			if (turn == 1) { robotPiece.setPosition(x[location], y[location]); }
			if (turn == 2) { shipPiece.setPosition(x[location], y[location]); }
			if (turn == 3) { carPiece.setPosition(x[location], y[location]); }
			landOnProperty(propertyClass, currPlayer, turn, players);

			break;

			// should never happen
		default:
			cout << "Error: Unreachable?" << endl;
			exit(EXIT_SUCCESS);
			break;
		}

		//Update budget at end of turn
		bud = currPlayer->getMoney();
		budStr = to_string(bud);
		budget.at(turn).setString("Budget: $" + budStr);

		// determines if the player's properties are part of monopoly
		monopoly(currPlayer);

		// if player is bankrupt, delete player from players vector
		if (currPlayer->getMoney() < 0) {
			cout << "You are bankrupt. You lose :(" << endl;

			// resets conditions of properties
			vector<Property*> props = currPlayer->getProperties();
			for (unsigned int i = 0; i < props.size(); i++) {
				props[i]->setOwner(-1);
				props[i]->setMonopoly(false);
				props[i]->setHouses(0);
			}
			players.erase(players.begin() + turn);
			nPlayers--;
		}

		// if 1 player left, end game
		if (players.size() == 1) {
			cout << "\nThe winner is " << players[0]->getName() << "!" << endl;
			exit(EXIT_SUCCESS);
		}

		// if landed on GO TO JAIL, then move to next player
		if (currPlayer->getJail()) {
			turn = (turn + 1) % nPlayers;
			continue;
		}

		// redo loop without moving on to next player
		if (doubles) {
			cout << "You rolled doubles. Roll Again!" << endl;
			continue;
		}

		// reset number of doubles of current player
		currPlayer->setDoubleTime(0);

		// next turn
		turn = (turn + 1) % nPlayers;

	}
}

// Method: handles the condition of player being in jail
// @param player pointer to current player, int reference to the dice
// @return true if still in jail, false if out of jail
bool jail(Player* player, int& dice1, int& dice2) {

	// if player is not currently in jail, ends method and turn continues normally
	if (!player->getJail()) return false;

	// if first or second turn in jail
	if (player->getJailTime() < 2) {

		// user input: choose to pay or roll
		cout << player->getName() << " is in jail. Would you like to pay $50 or roll for doubles? (pay/roll)" << endl;
		string input;
		do {
			cin >> input;
			transform(input.begin(), input.end(), input.begin(), ::toupper);

			// if invalid choice, reprompt
			if (input != "PAY" && input != "ROLL") cout << "Invalid choice. Please choose either pay or roll." << endl;
		} while (input != "PAY" && input != "ROLL");

		// roll the dice (no matter what, dice values must be retained)
		cout << "Press ENTER to roll dice." << endl;
		dice1 = rollDye();
		cin.ignore();
		cin.ignore();
		dice2 = rollDye();

		// if pay, deduct $50 and exit jail
		if (input == "PAY") {
			player->subtractMoney(50);
			player->setJailTime(0);
			return false;
		}

		cout << "You rolled a " << dice1 << " and a " << dice2 << "." << endl;

		// if roll and doubles, exit jail
		if (dice1 == dice2) {
			player->setJailTime(0);
			cout << player->getName() << " rolled doubles." << endl;
			return false;
		}

		// if not doubles, player is still in jail, move on to next player
		cout << "Doubles were not rolled. " << player->getName() << " remains in jail." << endl;
		player->setJailTime(player->getJailTime() + 1);
		return true;
	}

	// if third turn in jail, player must roll
	cout << player->getName() << " is in jail. Rolling dice." << endl;

	// roll the dice
	cout << "Press ENTER to roll dice." << endl;
	dice1 = rollDye();
	cin.ignore();
	cin.ignore();
	dice2 = rollDye();

	cout << "You rolled a " << dice1 << " and a " << dice2 << "." << endl;

	// if doubles rolled, exit jail
	if (dice1 == dice2) {
		player->setJailTime(0);
		cout << player->getName() << " rolled doubles." << endl;
		return false;
	}

	// if doubles not rolled, has to pay $50, exits jail
	cout << player->getName() <<
		" did not roll doubles and has spent 3 turns in jail. Prisoner fined $50. Releasing hardened convict." << endl;
	player->setJailTime(0);
	player->subtractMoney(50);
	return false;
}

// Method: handles landing on property
// if not owned, user can buy property or ignore it
// if owned by someone else, pay rent to that person
// @param Property pointer to current property, Player pointer to current player and his/her turn,
// and vector pointer of all the players
void landOnProperty(Property* property, Player* player, int turn, vector<Player*> players) {

	// gets the rent
	int rent = property->getRent();
	string choice;

	// if rent = 0, the property is not owned
	if (rent == 0) {

		// prompt to buy or ignore property
		cout << property->getName() << " is not owned. The price is $" << property->getPrice() <<
			". Would you like to buy " << property->getName() << "? (Y/N)" << endl;

		while (true) {

			cin >> choice;

			// if choice is yes, break out of while loop
			if (choice == "Y" || choice == "y") {

				// cost of property
				int cost = property->getPrice();

				// deduct cost from player's money
				player->subtractMoney(cost);

				// make the owner of the property the current player
				property->setOwner(turn);

				// add property to player's own property vector
				player->addProperty(property);
				cout << "You bought " << property->getName() << "!" << endl;
				break;
			}

			// if choice is no, do nothing
			else if (choice == "N" || choice == "n") {
				cout << property->getName() << " was not bought." << endl;
				break;
			}

			// checks input, reruns if neither
			else cout << "Invalid choice, choose either 'Y' or 'N'" << endl;
		}
	}

	// if the property does not belong to the current player
	else if (turn != property->getOwner()) {

		// essentially the "turn" of the opponent player
		int owner = property->getOwner();

		// if there are no houses on it...
		if (property->getHouses() == 0) {

			// ...and is part of a monopoly, print this statement
			if (property->getMonopoly()) {
				cout << players[owner]->getName() << " owns " << property->getName() << " in a monopoly. You pay " <<
					players[owner]->getName() << " $" << rent << "." << endl;
			}

			// ...and isn't part of a monopoly, print this
			else {
				cout << players[owner]->getName() << " owns " << property->getName() <<
					". You pay " << players[owner]->getName() << " $" << rent << "." << endl;
			}
		}

		// if one or more houses, print this
		else {
			cout << players[owner]->getName() << " owns " << property->getName() << " in a monopoly with " << property->getHouses() <<
				" house(s). You pay " << players[owner]->getName() << " $" << rent << "." << endl;
		}

		// give money from current player to opponent (owner)
		players[owner]->addMoney(rent);
		player->subtractMoney(rent);
	}

	// if current player lands on own property, do nothing
	else cout << "You landed on your own property..." << endl;
}

// Method: scans player's current properties, determines which are part of monopoly
// Determines which colors are monopolized
// @param player pointer to current player
void monopoly(Player* player) {

	// vector of player's properties
	vector<Property*> properties = player->getProperties();

	// declare counters for each color
	int purple = 0;
	int lblue = 0;
	int pink = 0;
	int orange = 0;
	int red = 0;
	int yellow = 0;
	int green = 0;
	int dblue = 0;

	// goes through player's properties, increments if they are of a specific color
	for (unsigned int i = 0; i < properties.size(); i++) {

		if (properties[i]->getColor() == "PURPLE") purple++;
		else if (properties[i]->getColor() == "L. BLUE") lblue++;
		else if (properties[i]->getColor() == "PINK") pink++;
		else if (properties[i]->getColor() == "ORANGE") orange++;
		else if (properties[i]->getColor() == "RED") red++;
		else if (properties[i]->getColor() == "YELLOW") yellow++;
		else if (properties[i]->getColor() == "GREEN") green++;
		else if (properties[i]->getColor() == "D. BLUE") dblue++;
	}

	// if at least one monopoly exists, set hasMonopoly to true for the player
	if (purple == 2 || lblue == 3 || pink == 3 || orange == 3 || red == 3 || yellow == 3 || green == 3 || dblue == 2)
		player->setMonopoly(true);

	// vector of the monopolized colors
	vector<string> colors = player->getColors();

	// if monopoly is true for a certain color and the colors vector doesn't already have it, add it to that vector
	if (purple == 2 && find(colors.begin(), colors.end(), "PURPLE") == colors.end()) player->addColors("PURPLE");
	if (lblue == 3 && find(colors.begin(), colors.end(), "L. BLUE") == colors.end()) player->addColors("L. BLUE");
	if (pink == 3 && find(colors.begin(), colors.end(), "PINK") == colors.end()) player->addColors("PINK");
	if (orange == 3 && find(colors.begin(), colors.end(), "ORANGE") == colors.end()) player->addColors("ORANGE");
	if (red == 3 && find(colors.begin(), colors.end(), "RED") == colors.end()) player->addColors("RED");
	if (yellow == 3 && find(colors.begin(), colors.end(), "YELLOW") == colors.end()) player->addColors("YELLOW");
	if (green == 3 && find(colors.begin(), colors.end(), "GREEN") == colors.end()) player->addColors("GREEN");
	if (dblue == 2 && find(colors.begin(), colors.end(), "D. BLUE") == colors.end()) player->addColors("D. BLUE");

	// sets the monopoly condition of each property to true if they are part of a monopolized color region
	for (unsigned int i = 0; i < properties.size(); i++) {
		if ((purple == 2 && properties[i]->getColor() == "PURPLE") ||
			(lblue == 3 && properties[i]->getColor() == "L. BLUE") ||
			(pink == 3 && properties[i]->getColor() == "PINK") ||
			(orange == 3 && properties[i]->getColor() == "ORANGE") ||
			(red == 3 && properties[i]->getColor() == "RED") ||
			(yellow == 3 && properties[i]->getColor() == "YELLOW") ||
			(green == 3 && properties[i]->getColor() == "GREEN") ||
			(dblue == 2 && properties[i]->getColor() == "D. BLUE")) {

			properties[i]->setMonopoly(true);
		}
	}
}

// Method: determines different outcomes of random community chest draw
// @param player pointer to current player
void communityChest(Player* player) {

	// chooses random number
	int randNum = rand() % 6;

	// text to display at index of random number
	string communityChest[6] = { "Advance to Go (Collect $200)", "Bank error in your favor – Collect $200",
		"Doctor's fees {fee} – Pay $50", "Income tax refund – Collect $20",
		"Pay hospital fees of $100",  "You have won second prize in a beauty contest – Collect $10" };

	cout << communityChest[randNum] << endl;

	// set location to GO and add $200
	if (randNum == 0) {
		player->setLocation(0);
		player->addMoney(200);
	}

	// collect $200
	else if (randNum == 1) player->addMoney(200);

	// decrease player's money by 50
	else if (randNum == 2) player->subtractMoney(50);

	// increase player's money by 20
	else if (randNum == 3) player->addMoney(20);

	// decrease player's money by 100
	else if (randNum == 4) player->subtractMoney(100);

	// increase player's money by 10
	else player->addMoney(10);
}

// Method: determines different outcomes of random chance draw
// @param player pointer to current player
void chance(Player* player) {

	// choose random number
	int randNum = rand() % 5;

	// text to display at index of random number
	string chance[5] = { "Advance to Go (Collect $200)", "Pay poor tax of $15",
		"Your building {and} loan matures – Collect $150",  "You have won a crossword competition - Collect $100",
		"Bank pays you dividend of $50" };

	cout << chance[randNum] << endl;

	// set location to GO and add $200
	if (randNum == 0) {
		player->setLocation(0);
		player->addMoney(200);
	}

	// decrease player's money by 15
	else if (randNum == 1) player->subtractMoney(15);

	// increase player's money by 150
	else if (randNum == 2) player->addMoney(150);

	// increase player's money by 100
	else if (randNum == 3) player->addMoney(100);

	// increase player's money by 50
	else player->addMoney(50);
}

// Method: Prints menu and looks for user input
// @param player pointer to current player, vector of Property pointers to all properties that exist
// @return true if proceed with turn, false if anything else
bool menu(Player* player, vector<Property*> allProps) {

	// vector of current player's properties
	vector<Property*> properties = player->getProperties();

	// print menu, options are integers
	cout << "1. Proceed with turn" << endl;
	cout << "2. Display player info" << endl;
	cout << "3. Buy/sell houses" << endl;
	cout << "4. Show visualization for properties held" << endl;
	cout << "5. Exit game" << endl;

	int choice;
	while (true) {
		// user input: choice
		cin >> choice;

		// if not an integer, clear buffer and reprompt
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n');
			choice = 0;
		}

		// if not between 1-5, reprompt
		if (choice > 5 || choice < 1) {
			cout << "Invalid input. Please try again: ";
		}
		else break;
	}
	cout << endl;

	// display information about the player
	if (choice == 2) {

		// print how much money player has
		cout << "You have $" << player->getMoney() << "." << endl;

		// use for loop to print which properties player owns
		cout << "You own ";
		if (!properties.empty()) {
			for (unsigned int i = 0; i < properties.size(); i++) {
				if (i != properties.size() - 1) cout << properties[i]->getName() << ", ";
				else cout << properties[i]->getName() << "." << endl;
			}
		}
		else cout << "no properties." << endl;

		// location of player
		cout << "You are located at location " << player->getLocation() << "." << endl;

		// prints current turn in jail if in jail
		if (player->getJail()) {
			cout << "You are in turn #" << player->getJailTime() + 1 << " in jail." << endl;
		}

		// prints current monopolies
		if (player->getMonopoly()) {
			cout << "MONOPOLIES: ";
			for (unsigned int i = 0; i < player->getColors().size(); i++) {
				if (i != player->getColors().size() - 1) cout << player->getColors()[i] << ", ";
				else cout << player->getColors()[i] << endl;
			}
		}
		cout << endl;
		return true;
	}

	// buy/sell houses
	else if (choice == 3) {

		// if they have a monopoly, they can buy/sell houses
		if (player->getMonopoly()) {

			// runs options for building/demolishing houses
			buildHouses(player, allProps);
		}

		// if they don't, exit method
		else {
			cout << "You do not have a monopoly. Unable to build houses." << endl;
		}
		cout << endl;
		return true;
	}

	// shows visualization for the properties that the player currently has
	// 'X' means that the property is not owned
	// a number indicates that how many houses are on the current property
	// the vertical lines separate properties of different colors/monopolies
	else if (choice == 4) {

		for (unsigned int i = 0; i < allProps.size(); i++) {
			if (find(properties.begin(), properties.end(), allProps[i]) != properties.end()) {
				cout << allProps[i]->getHouses() << " ";
			}
			else cout << "X ";
			if (i == 1 || i == 4 || i == 7 || i == 10 || i == 13 || i == 16 || i == 19) cout << "| ";
		}
		cout << endl << endl;
		return true;
	}

	// exits game
	else if (choice == 5) {
		exit(EXIT_SUCCESS);
	}

	// proceeds with the rest of the game
	return false;
}

// Method: build houses on a specific property
// @param player pointer to current player, vector of Property pointers to all possible properties
void buildHouses(Player* player, vector<Property*> allProps) {

	// vector of player's properties
	vector<Property*> properties = player->getProperties();

	// vector of monopolized colors for this player
	vector<string> colors = player->getColors();
	vector<Property*> monoProps;

	// prompt whether to buy/sell houses
	cout << "Would you like to buy or sell houses? (buy/sell)" << endl;
	string input;
	do {
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);

		// if invalid choice, reprompt
		if (input != "BUY" && input != "SELL") cout << "Invalid choice. Please choose either buy or sell." << endl;
	} while (input != "BUY" && input != "SELL");

	// if user wants to sell houses...
	if (input == "SELL") {

		// pick monopoly color for which to sell houses on
		cout << "In which monopoly would you like to sell houses? (Pick a color)" << endl;
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);

		// fixes potential entries for specific colors L. BLUE and D. BLUE
		if (input == "LIGHT BLUE" || input == "L BLUE" || input == "LBLUE" || input == "L.BLUE") input = "L. BLUE";
		if (input == "DARK BLUE" || input == "D BLUE" || input == "DBLUE" || input == "D.BLUE") input = "D. BLUE";

		// if the color is not in monopolized colors vector, return to main menu
		if (find(colors.begin(), colors.end(), input) == colors.end()) {
			cout << "Monopoly color not found. Returning to main menu." << endl;
			return;
		}

		// put all properties of that color in same property vector
		for (unsigned int i = 0; i < allProps.size(); i++) {
			if (input == allProps[i]->getColor()) {
				monoProps.push_back(allProps[i]);
			}
		}

		Property* temp;
		bool exists = false;

		// prompt which property player would like to sell houses on
		cout << "Which property do you want to sell houses on? (Must be sold evenly with other monopoly properties)" << endl;
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);

		// puts chosen property at front of vector
		for (unsigned int i = 0; i < monoProps.size(); i++) {
			if (input == monoProps[i]->getName()) {
				temp = monoProps[0];
				monoProps[0] = monoProps[i];
				monoProps[i] = temp;
				exists = true;
			}
		}

		// if invalid property or a property not in the monoProps vector, return to main menu
		if (!exists) {
			cout << "Property not found. Returning to main menu." << endl;
			return;
		}

		// if no houses on this property, then there's nothing to sell
		if (monoProps[0]->getHouses() == 0) {
			cout << "No houses on this property to sell. Returning to main menu." << endl;
			return;
		}

		// if there's at least one property in the same color group that has more houses, return to main menu
		for (unsigned int i = 1; i < monoProps.size(); i++) {
			if (monoProps[0]->getHouses() < monoProps[i]->getHouses()) exists = false;
		}
		if (exists) {
			cout << "Property has less houses than monopoly properties. Returning to main menu." << endl;
			return;
		}

		// decrease number of houses in chosen property by 1
		monoProps[0]->setHouses(monoProps[0]->getHouses() - 1);

		// give money to player, which is half of the house price for the property
		player->addMoney(monoProps[0]->getHousePrice() / 2);
		cout << "You earned $" << monoProps[0]->getHousePrice() / 2 << "." << endl;
	}
	else {

		// pick monopoly color for which to buy houses on
		cout << "Which monopoly would you like to develop on? (Pick a color)" << endl;
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);

		// fixes potential entries for specific colors L. BLUE and D. BLUE
		if (input == "LIGHT BLUE" || input == "L BLUE" || input == "LBLUE" || input == "L.BLUE") input = "L. BLUE";
		if (input == "DARK BLUE" || input == "D BLUE" || input == "DBLUE" || input == "D.BLUE") input = "D. BLUE";

		// if the color is not in monopolized colors vector, return to main menu
		if (find(colors.begin(), colors.end(), input) == colors.end()) {
			cout << "Monopoly color not found. Returning to main menu." << endl;
			return;
		}

		// put all properties of that color in same property vector
		for (unsigned int i = 0; i < allProps.size(); i++) {
			if (input == allProps[i]->getColor()) {
				monoProps.push_back(allProps[i]);
			}
		}

		Property* temp;
		bool exists = false;

		// prompt which property player would like to buy houses on
		cout << "Which property do you want to buy houses on? (Must be built evenly with other monopoly properties)" << endl;
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);

		// puts chosen property at front of vector
		for (unsigned int i = 0; i < monoProps.size(); i++) {
			if (input == monoProps[i]->getName()) {
				temp = monoProps[0];
				monoProps[0] = monoProps[i];
				monoProps[i] = temp;
				exists = true;
			}
		}

		// if invalid property or a property not in the monoProps vector, return to main menu
		if (!exists) {
			cout << "Property not found. Returning to main menu." << endl;
			return;
		}

		// if five houses on this property, then you can't buy anymore, returns to main menu
		if (monoProps[0]->getHouses() == 5) {
			cout << "Max number of houses already reached. Returning to main menu." << endl;
			return;
		}

		// if there's at least one property in the same color group that has less houses, return to main menu
		for (unsigned int i = 1; i < monoProps.size(); i++) {
			if (monoProps[0]->getHouses() > monoProps[i]->getHouses()) exists = false;
		}
		if (exists) {
			cout << "Property has more houses than monopoly properties. Returning to main menu." << endl;
			return;
		}

		// if player doesn't have enough money to buy house, return to main menu
		if (player->getMoney() < monoProps[0]->getHousePrice()) {
			cout << "Insufficient funds. Returning to main menu." << endl;
			return;
		}

		// add one house to chosen property
		monoProps[0]->setHouses(monoProps[0]->getHouses() + 1);

		// subtract player's money by the price of houses for this property
		player->subtractMoney(monoProps[0]->getHousePrice());
		cout << "You bought a house on " << monoProps[0]->getName() << "!" << endl;
	}
}