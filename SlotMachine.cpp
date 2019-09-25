#include "SlotMachine.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"
#include "Shape.h"

#include <random>
#include <algorithm>
#include <ctime>

void SlotMachine::make_shapes()
{
	//generate shapes randomly for each section of the reel
	for (auto& i : reel)
	{
		//generate shape randomly
		int shape = rand() % 4;
		int width = rand() % 25 + 1;
		
		//set the pointer to the correct shape
		if (shape == 0)
		{
			i.reset(new Rhombus(width));
		}
		else if (shape == 1)
		{
			i.reset(new AcuteTriangle(width));
		}
		else if (shape == 2)
		{
			i.reset(new RightTriangle(width));
		}
		else
		{
			int height = rand() % 25 + 1;
			i.reset(new Rectangle(width, height));
		}
	}
}

void SlotMachine::display()
{
	//graphics display here

	Grid box_0 = reel[0]->draw();
	Grid box_1 = reel[1]->draw();
	Grid box_2 = reel[2]->draw();

	//calculating dimensions of the big holding box
	int box_all_width = 2 + reel[0]->boundingBoxWidth() + 3 
		+ reel[1]->boundingBoxWidth() + 3 + reel[2]->boundingBoxWidth() + 2;

	int box_all_height = 2 + max (reel[2]->boundingBoxHeight(), 
								max	(reel[0]->boundingBoxHeight(), reel[1]->boundingBoxHeight()));

	//setting up the big box
	Grid box_all(box_all_height, vector<char>(box_all_width));

	//initialize the big box with spaces
	for (auto& i : box_all)
	{
		for (auto& j : i)
		{
			j = ' ';
		}
	}
	
	//FRAME
	//adding all '-'
	for (size_t i = 0; i < box_all_width; ++i)
	{
		box_all[0][i] = '-';
		box_all[box_all_height - 1][i] = '-';
	}

	//adding all '|'
	for (size_t j = 0; j < box_all_height; ++j)
	{
		box_all[j][0] = '|';
		box_all[j][2 + reel[0]->boundingBoxWidth() + 1] = '|';
		box_all[j][2 + reel[0]->boundingBoxWidth() + 3 + reel[1]->boundingBoxWidth() + 1] = '|';
		box_all[j][box_all_width - 1] = '|';
	}

	//adding all '+'
	
	//---corners
	box_all[0][0] = '+';
	box_all[box_all_height - 1][0] = '+';
	box_all[0][box_all_width - 1] = '+';
	box_all[box_all_height - 1][box_all_width - 1] = '+';
	
	//---intersections
	box_all[0][2 + reel[0]->boundingBoxWidth() + 1] = '+';
	box_all[0][2 + reel[0]->boundingBoxWidth() + 3 + reel[1]->boundingBoxWidth() + 1] = '+';
	box_all[box_all_height - 1][2 + reel[0]->boundingBoxWidth() + 1] = '+';
	box_all[box_all_height - 1][2 + reel[0]->boundingBoxWidth() + 3 + reel[1]->boundingBoxWidth() + 1] = '+';
	
	//SHAPES
	//copying smaller boxes into the big box
	int offset_j = 2;
	int offset_i = 1;
	
	for (size_t i = 0; i < reel[0]->boundingBoxHeight(); ++i)
	{
		for (size_t j = 0; j < reel[0]->boundingBoxWidth(); ++j)
		{
			box_all[i+offset_i][j+offset_j] = box_0[i][j];
		}
	}
	offset_j += reel[0]->boundingBoxWidth() + 3;
	
	for (size_t i = 0; i < reel[1]->boundingBoxHeight(); ++i)
	{
		for (size_t j = 0; j < reel[1]->boundingBoxWidth(); j++)
		{
			box_all[i + offset_i][j + offset_j] = box_1[i][j];
		}
	}
	offset_j += reel[1]->boundingBoxWidth() + 3;

	
	for (size_t i = 0; i < reel[2]->boundingBoxHeight(); ++i)
	{
		for (size_t j = 0; j < reel[2]->boundingBoxWidth(); j++)
		{
			box_all[i + offset_i][j + offset_j] = box_2[i][j];
		}
	}
	

	//displaying the big box 
	//as the operator << for Grid is overloaded in the driver, it is not used here
	
	for (const auto& row : box_all) // for each row vector in the grid
	{
		for (const auto& element : row) // for each element (char) in the row vector
		{
			cout << element;
		}
		cout << endl; // line break
	}

	//text displays here
	for (auto& i : reel)
	{
		cout << "(" << i->getShapeName() << ", " << i->boundingBoxHeight() << ", "
			<< i->boundingBoxWidth() << ") ";
	}
	cout << endl;
	
}

bool SlotMachine::any_two_similar_in_shape()
{
	return (reel[0]->getShapeName() == reel[1]->getShapeName()
		|| reel[1]->getShapeName() == reel[2]->getShapeName()
		|| reel[0]->getShapeName() == reel[2]->getShapeName());
}

bool SlotMachine::all_three_similar_in_shape()
{
	return (reel[0]->getShapeName() == reel[1]->getShapeName()
		&& reel[1]->getShapeName() == reel[2]->getShapeName());
}

bool SlotMachine::any_two_match_screen_areas()
{
	return (reel[0]->screenArea() == reel[1]->screenArea()
		|| reel[1]->screenArea() == reel[2]->screenArea()
		|| reel[0]->screenArea() == reel[2]->screenArea());
}

bool SlotMachine::middle_more_left_right()
{
	return (reel[1]->screenArea() > (reel[0]->screenArea() + reel[2]->screenArea()));
}

bool SlotMachine::left_right_similar_in_shape()
{
	return (reel[0]->getShapeName() == reel[2]->getShapeName());
}


void SlotMachine::run()
{
	srand(time(0));
	
	cout << "\nWelcome to 3-Reel Lucky Slot Machine Game!" << endl;
	cout << "Each reel will randomly display one of four shapes, each in 25 sizes." << endl;
	cout << "To win 3 x bet Get 2 similar shapes AND 2 shapes with equal Scr Areas" << endl;
	cout << "To win 2 x bet Get 3 similar shapes" << endl;
	cout << "To win 1 x bet Get (Middle) Scr Area > (Left + Right) Scr Areas" << endl;
	cout << "To win or lose nothing Get the same Left and Right shapes" << endl;
	cout << "Otherwise, you lose your bet." << endl;
	cout << "You start with 10 free slot tokens!" << endl;

	int userTokens = 10;
	while (userTokens > 0)
	{
		int bet;
		cout << "\nHow much would you like to bet (enter 0 to quit)? ";
		cin >> bet;

		//guards
		if (bet == 0) //user wants to quit 
			break;
		if (bet > userTokens) //user does not have enough tokens
		{
			cout << "You can't bet more than " << userTokens << ", try again!" << endl;
			continue;
		}
		if (bet < 0) //negative values are not possible
		{
			cout << "No negative bets, try again!" << endl;
			continue;
		}
		
		//shapes generation
		make_shapes();
		display();
		
		//game logic
		int win = 0;
		
		if (any_two_similar_in_shape() && any_two_match_screen_areas()) //+3
		{
			win = bet * 3;
			cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas" << endl;
			cout << "Congratulations! you win 3 times your bet: " << win << endl;
		}
		else if (all_three_similar_in_shape()) //+3
		{
			win = bet * 2;
			cout << "Three similar shapes" << endl;
			cout << "Congratulations! you win 2 times your bet: " << win << endl;			
		}
		else if (middle_more_left_right())
		{
			win = bet * 1;
			cout << "Middle > Left + Right, in Screen Areas" << endl;
			cout << "Congratulations! you win your bet: " << win << endl;
		}
		else if (left_right_similar_in_shape())
		{
			win = 0;
			cout << "Lucky this time!" << endl;
			cout << "You don't win, you don't lose, you are safe!" << endl;
		}
		else
		{
			win = bet * -1;
			cout << "Oh No!" << endl;
			cout << "You lose your bet" << endl;
		}

		userTokens += win;
		cout << "You now have " << userTokens << " tokens" << endl;
	}
	
	//ending credits
	cout << "Thank you for playing, come back soon!" << endl;
	if (userTokens > 0)
	{
		cout << "Be sure you cash in your remaining " << userTokens << " tokens at the bar!" << endl;
	}
	cout << "Game Over." << endl;
}