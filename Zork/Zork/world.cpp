#include "world.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include "person.h"
#include "utilities.h"

#include <iostream>

World::World()
{
	//Rooms
	Room* bedroom1 = new Room("Bedroom 101", "You are in the bedroom of Room 101.");
	Room* bathroom1 = new Room("Bathroom 101", "You are in the bathroom of Room 101. There is a body in the bath.");
	Room* bedroom2 = new Room("Bedroom 102", "You are in the bedroom of Room 102.");
	Room* bathroom2 = new Room("Bathroom 102", "You are in the bathroom of Room 102.");
	Room* hall = new Room("Hall", "You are in the hall between the rooms 101 and 102.");
	Room* reception = new Room("Reception", "You are in the reception of the hotel.");
	Room* bar = new Room("Bar", "You are in the bar. Take a drink.");
	entities.push_back(bedroom1);
	entities.push_back(bathroom1);
	entities.push_back(bedroom2);
	entities.push_back(bathroom2);
	entities.push_back(hall);
	entities.push_back(reception);
	entities.push_back(bar);

	//Exits
	Exit* exit1 = new Exit("South", "Door to go form the bedroom to the bathroom.", bedroom1, bathroom1);
	bedroom1->container.push_back(exit1);
	Exit* exit2 = new Exit("North", "Door to go from the bathroom to the bedroom.", bathroom1, bedroom1);
	bathroom1->container.push_back(exit2);
	Exit* exit3 = new Exit("West", "Door to get out from the room 101.", bedroom1, hall);
	bedroom1->container.push_back(exit3);
	Exit* exit4 = new Exit("East", "Door to go to the room 101.", hall, bedroom1);
	hall->container.push_back(exit4);
	Exit* exit5 = new Exit("West", "Door to go to the room 102.", hall, bedroom2);
	hall->container.push_back(exit5);
	Exit* exit6 = new Exit("Down", "Stairs to go down.", hall, reception);
	hall->container.push_back(exit6);
	Exit* exit7 = new Exit("South", "Door to go form the bedroom to the bathroom.", bedroom2, bathroom2);
	bedroom2->container.push_back(exit7);
	Exit* exit8 = new Exit("North", "Door to go from the bathroom to the bedroom.", bathroom2, bedroom2);
	bathroom2->container.push_back(exit8);
	Exit* exit9 = new Exit("East", "Door to get out from the room 102.", bedroom2, hall);
	bedroom2->container.push_back(exit9);
	Exit* exit10 = new Exit("East", "Door to go to the bar.", reception, bar);
	reception->container.push_back(exit10);
	Exit* exit11 = new Exit("Up", "Stairs to go up.", reception, hall);
	reception->container.push_back(exit11);
	Exit* exit12 = new Exit("West", "Door to go to the reception.", bar, reception);
	bar->container.push_back(exit12);

	entities.push_back(exit1);
	entities.push_back(exit2);
	entities.push_back(exit3);
	entities.push_back(exit4);
	entities.push_back(exit5);
	entities.push_back(exit6);
	entities.push_back(exit7);
	entities.push_back(exit8);
	entities.push_back(exit9);
	entities.push_back(exit10);
	entities.push_back(exit11);
	entities.push_back(exit12);

	//Persons
	vector<Answers> answers = vector<Answers>();
	Answers answer = Answers();
	answer.key = "Hair";
	answer.answer = "This hair belongs to Susan Queen";
	answers.push_back(answer);
	answer.key = "Knife";
	answer.answer = "This knife has a couple of fingerprints on it, one belongs to Mrs. Susan Queen and the other to Mr. Albert Queen";
	answers.push_back(answer);
	Person* forensic = new Person("Eduardo", "Eduardo Garcia the forensic", bathroom1, false, false, "Hi I am the forensic, if you bring me evidence I can analyze it for you", answers);
	bathroom1->container.push_back(forensic);
	answers.clear();
	answer.key = "Video";
	answer.answer = "If you pay, I will give it to you";
	answers.push_back(answer);
	Person* security = new Person("Security", "Miguel Velasquez Security Man", hall, false, true, "I did not see anything strange last night", answers);
	hall->container.push_back(security);
	answers.clear();
	answer.key = "Robert";
	answer.answer = "He was my partner, we were good friends";
	answers.push_back(answer);
	answer.key = "Susan";
	answer.answer = "She is my wife, I was with her all night";
	answers.push_back(answer);
	answer.key = "Hair";
	answer.answer = "It could be my wife's hair";
	answers.push_back(answer);
	answer.key = "Photo";
	answer.answer = "She is my wife!!!!!! Why did he have this photo in his wallet?";
	answers.push_back(answer);
	answer.key = "Knife";
	answer.answer = "Ok. I confess, I killed Robert. I saw him with my wife and we had a figth. And I killed him";
	answers.push_back(answer);
	Person* albert = new Person("Albert", "Albert Queen a wealthy man", bedroom2, true, false, "Yesterday I was all nigth with my wife", answers);
	bedroom2->container.push_back(albert);
	answers.clear();
	answer.key = "Robert";
	answer.answer = "He was my husband's partner. I did not have much relationship with him";
	answers.push_back(answer);
	answer.key = "Albert";
	answer.answer = "He is my husband, and I love him";
	answers.push_back(answer);
	answer.key = "Hair";
	answer.answer = "It is my hair. Are you saying that it was in Robert's bathdroom. I do not know it got there";
	answers.push_back(answer);
	answer.key = "Photo";
	answer.answer = "Ok. I admit, Robert and I were lovers. Last night we took a bath together in his room. But I left before 21:00";
	answers.push_back(answer);
	answer.key = "Knife";
	answer.answer = "This is mi knife, where did you find it? I lost it yesterday. I use it to cook, as I am a chef";
	answers.push_back(answer);
	Person* susan = new Person("Susan", "Susan Queen a sexy lady with red hair an blue eyes", reception, true, false, "Yesterday I was in the bar until 00:00, and them I went to my room to sleep.", answers);
	reception->container.push_back(susan);
	answers.clear();
	Person* receptionist = new Person("Receptionist", "Kelly Danvers receptionist", reception, false, true, "I call Mr. Lewis's room this morning to wake him up and as I did not get an answer, I went to the room and saw him. Then I call the police. I do not know anything more, this is my first day", answers);
	reception->container.push_back(receptionist);
	answers.clear();
	answer.key = "Robert";
	answer.answer = "He arrived with Susan at about 9:00 p.m and left at 10:30 p.m";
	answers.push_back(answer);
	answer.key = "Albert";
	answer.answer = "He was drinking at the bar since 7:00 p.m. and left with Robert. He was very drunk";
	answers.push_back(answer);
	answer.key = "Susan";
	answer.answer = "She arrived with Robert, and she was here drinking until 00:00";
	answers.push_back(answer);
	Person* bartender = new Person("Bartender", "Jhon Smock", bar, false, true, "Last nigh Robert, Albert and Susan were dinking togheder here", answers);
	bar->container.push_back(bartender);

	entities.push_back(forensic);
	entities.push_back(security);
	entities.push_back(albert);
	entities.push_back(susan);
	entities.push_back(receptionist);
	entities.push_back(bartender);

	//Items
	Item* item1 = new Item("Desk", "A big desk in the room 101", false, true, false);
	bedroom1->container.push_back(item1);
	Item* item2 = new Item("Report", "FORENSIC REPORT\nThe body belongs to a man, between 30 and 40 years old.\nThe time of death is placed between 22:00 and 00:00 yesterday.\nThe cause of death was a stab in the abdominal area.", true, false, true);
	item1->container.push_back(item2);
	Item* item3 = new Item("Wallet", "A black leather wallet", true, true, true);
	item1->container.push_back(item3);
	Item* item4 = new Item("Money", "124 american dolars", true, false, true);
	item3->container.push_back(item4);
	Item* item5 = new Item("DNI", "Robert K. Lewis\n48331-23998", true, false, true);
	item3->container.push_back(item5);
	Item* item6 = new Item("CreditCard", "An international visa credit card", true, false, true);
	item3->container.push_back(item6);
	Item* item7 = new Item("Photo", "A photo of a red-haired woman with blue eyes.", true, false, true);
	item3->container.push_back(item7);
	Item* item8 = new Item("Cooler", "An old cooler with ice.", false, true, false);
	hall->container.push_back(item8);
	Item* item9 = new Item("Knife", "A bloody knife.", true, false, true);
	item8->container.push_back(item9);
	Item* item10 = new Item("Hair", "A long red hair", true, false, true);
	bathroom1->container.push_back(item10);
	Item* item11 = new Item("Pouch", "A pink pouch.", true, true, true);
	bathroom2->container.push_back(item11);
	Item* item12 = new Item("Brush", "A hair brush with long red hairs.", true, true, true);
	item11->container.push_back(item12);
	Item* item13 = new Item("Lipstik", "A red lipstik.", true, true, true);
	item11->container.push_back(item13);
	Item* item14 = new Item("Video", "In the video you can see how Robert and Albert got into Robert's room toghether at 10:30 p.m. and Albert got out 40 minutes later with a knife and he hid it in the cooler", true, false, true);
	security->container.push_back(item14);

	entities.push_back(item1);
	entities.push_back(item2);
	entities.push_back(item3);
	entities.push_back(item4); 
	entities.push_back(item5);
	entities.push_back(item6);
	entities.push_back(item7);
	entities.push_back(item8);
	entities.push_back(item9);
	entities.push_back(item10);
	entities.push_back(item11);
	entities.push_back(item12);
	entities.push_back(item13);
	entities.push_back(item14);

	//Player
	player = new Player("Player", "Player", bathroom1);
	entities.push_back(player);

}


World::~World()
{
}

bool World::ExecuteCommand(const vector<string>& arguments)
{
	
	return ParceCommand(arguments);
}

bool World::ParceCommand(const vector<string>& arguments)
{
	bool result = true;
	if (Equal(arguments[0], "look"))
	{
		if (arguments.size() <= 2)
			player->Look(arguments);
		else
			cout << "The command look only accept 1 or 0 parameters.\n";
	}
	else if (Equal(arguments[0], "go"))
	{
		if (arguments.size() == 2) {
			player->Go(arguments[1]);
			player->location->Look();
		}
		else
			cout << "The command go only accept 1 parameter.\n";
	}
	else if (Equal(arguments[0], "take"))
	{
		if (arguments.size() == 2 || (arguments.size() == 4 && Equal(arguments[2], "from")))
			player->Take(arguments);
		else
			cout << "The command take only accept 1 or 3 parameters.\n";
	}
	else if (Equal(arguments[0], "drop"))
	{
		if (arguments.size() == 2 || (arguments.size() == 4 && Equal(arguments[2], "into")))
			player->Drop(arguments);
		else
			cout << "The command drop only accept 1 or 3 parameters.\n";
	}
	else if (Equal(arguments[0], "inventory"))
	{
		if (arguments.size() == 1)
			player->Inventory();
		else
			cout << "The command inventory does not accept parameters.\n";
	}
	else if (Equal(arguments[0], "ask"))
	{
		if (arguments.size() == 2 || (arguments.size() == 4 && Equal(arguments[2], "about")))
			player->Ask(arguments);
		else
			cout << "The command ask only accept 1 or 3 parameters.\n";
	}
	else if (Equal(arguments[0], "pay"))
	{
		if (arguments.size() == 4 && Equal(arguments[2], "for"))
			player->Pay(arguments);

		else
			cout << "The command pay only accept  3 parameters.\n";
	}
	else
	{
		result = false;
	}
	return result;
}
