#include "Data.h"


Data::Data()
{
	for(int i = 0; i < 41; i++)
	{
		tex_terrBlueVec.push_back(sf::Texture());
		tex_terrRedVec.push_back(sf::Texture());
		tex_terrYellVec.push_back(sf::Texture());

		spr_terrBlueVec.push_back(sf::Sprite());
		spr_terrRedVec.push_back(sf::Sprite());
		spr_terrYellVec.push_back(sf::Sprite());
	}


	std::ifstream	input_blue_txt,
					input_red_txt,
					input_yell_txt;

	// Load Shapes for blue Territoy-Color
	input_blue_txt.open("data/terr_shapes_blue.txt");

	if(!input_blue_txt.fail())
	{
		std::string temp_str_blue;
		int i = 0;

		while(std::getline(input_blue_txt, temp_str_blue))
		{
			if(!tex_terrBlueVec.at(i).loadFromFile(temp_str_blue))
			{
				std::cout << "FAILED TO LOAD shape_blue!" << std::endl;
			}

			spr_terrBlueVec.at(i).setTexture(tex_terrBlueVec.at(i));
			i++;
		}
	}
	input_blue_txt.close();


	// Load Shapes for red Territoy-Color
	input_red_txt.open("data/terr_shapes_red.txt");

	if(!input_red_txt.fail())
	{
		std::string temp_str_red;
		int i = 0;

		while(std::getline(input_red_txt, temp_str_red))
		{
			if(!tex_terrRedVec.at(i).loadFromFile(temp_str_red))
			{
				std::cout << "FAILED TO LOAD shape_red!" << std::endl;
			}

			spr_terrRedVec.at(i).setTexture(tex_terrRedVec.at(i));
			i++;
		}
	}
	input_red_txt.close();

	// Load Shapes for yellow Territoy-Color
	input_yell_txt.open("data/terr_shapes_yell.txt");

	if(!input_yell_txt.fail())
	{
		std::string temp_str_yell;
		int i = 0;

		while(std::getline(input_yell_txt, temp_str_yell))
		{
			if(!tex_terrYellVec.at(i).loadFromFile(temp_str_yell))
			{
				std::cout << "FAILED TO LOAD shape_neutral!" << std::endl;
			}

			spr_terrYellVec.at(i).setTexture(tex_terrYellVec.at(i));
			i++;
		}
	}
	input_yell_txt.close();

	
	font.loadFromFile("data/font_CreatureOfDarkness.ttf"); // "data/font_AllStarResort.ttf" // "data/font_JoeJack.ttf"

	for(int i = 0; i < 41; ++i)
	{
		text_UnitCountVec.push_back(sf::Text("0", font, 24));
		text_UnitCountVec.at(i).setColor(sf::Color::Color(0, 0, 0, 255));
	}


	// Terr[1]_Units
	text_UnitCountVec.at(0).setPosition(110, 30);
	text_UnitCountVec.at(0).setString("1");

	// Terr[2]
	text_UnitCountVec.at(1).setPosition(168, 290);
	text_UnitCountVec.at(1).setString("1");

	// Terr[3]
	text_UnitCountVec.at(2).setPosition(218, 300);

	// Terr[4]
	text_UnitCountVec.at(3).setPosition(322, 156);

	// Terr[5]
	text_UnitCountVec.at(4).setPosition(380, 170);

	// Terr[6]
	text_UnitCountVec.at(5).setPosition(510, 340);
	
	// Terr[7]
	text_UnitCountVec.at(6).setPosition(196, 410);
	
	// Terr[8]
	text_UnitCountVec.at(7).setPosition(100, 416);
	
	// Terr[9]
	text_UnitCountVec.at(8).setPosition(276, 506);
	text_UnitCountVec.at(8).setString("1");
	
	// Terr[10]
	text_UnitCountVec.at(9).setPosition(390, 474);
	text_UnitCountVec.at(9).setString("1");
	
	// Terr[11]
	text_UnitCountVec.at(10).setPosition(76, 608);
	
	// Terr[12]
	text_UnitCountVec.at(11).setPosition(218, 664);
	text_UnitCountVec.at(11).setString("1");
	
	// Terr[13]
	text_UnitCountVec.at(12).setPosition(334, 654);
	
	// Terr[14]
	text_UnitCountVec.at(13).setPosition(56, 770);
	
	// Terr[15]
	text_UnitCountVec.at(14).setPosition(264, 754);
	
	// Terr[16]
	text_UnitCountVec.at(15).setPosition(90, 862);
	
	// Terr[17]
	text_UnitCountVec.at(16).setPosition(232, 892);
	
	// Terr[18]
	text_UnitCountVec.at(17).setPosition(330, 940);
	
	// Terr[19]
	text_UnitCountVec.at(18).setPosition(130, 980);
	
	// Terr[20]
	text_UnitCountVec.at(19).setPosition(680, 200);
	text_UnitCountVec.at(19).setString("1");
	
	// Terr[21]
	text_UnitCountVec.at(20).setPosition(856, 140);
	
	// Terr[22]
	text_UnitCountVec.at(21).setPosition(940, 100);
	
	// Terr[23]
	text_UnitCountVec.at(22).setPosition(720, 300);
	text_UnitCountVec.at(22).setString("1");
	
	// Terr[24]
	text_UnitCountVec.at(23).setPosition(770, 326);
	
	// Terr[25]
	text_UnitCountVec.at(24).setPosition(954, 244);
	
	// Terr[26]
	text_UnitCountVec.at(25).setPosition(866, 358);
	
	// Terr[27]
	text_UnitCountVec.at(26).setPosition(958, 460);
	text_UnitCountVec.at(26).setString("1");
	
	// Terr[28]
	text_UnitCountVec.at(27).setPosition(732, 590);
	text_UnitCountVec.at(27).setString("1");
	
	// Terr[29]
	text_UnitCountVec.at(28).setPosition(1000, 506);
	text_UnitCountVec.at(28).setString("1");
	
	// Terr[30]
	text_UnitCountVec.at(29).setPosition(798, 582);
	
	// Terr[31]
	text_UnitCountVec.at(30).setPosition(990, 600);
	
	// Terr[32]
	text_UnitCountVec.at(31).setPosition(738, 668);
	text_UnitCountVec.at(31).setString("1");
	
	// Terr[33]
	text_UnitCountVec.at(32).setPosition(954, 660);
	
	// Terr[34]
	text_UnitCountVec.at(33).setPosition(1150, 700);
	text_UnitCountVec.at(33).setString("1");
	
	// Terr[35]
	text_UnitCountVec.at(34).setPosition(706, 748);
	text_UnitCountVec.at(34).setString("1");
	
	// Terr[36]
	text_UnitCountVec.at(35).setPosition(1150, 730);
	text_UnitCountVec.at(35).setString("1");
	
	// Terr[37]
	text_UnitCountVec.at(36).setPosition(1150, 760);
	
	// Terr[38]
	text_UnitCountVec.at(37).setPosition(912, 762);
	
	// Terr[39]
	text_UnitCountVec.at(38).setPosition(762, 930);

	// Terr[40]
	text_UnitCountVec.at(39).setPosition(1150, 790);
	
	// Terr[41]
	text_UnitCountVec.at(40).setPosition(1150, 820);
}

Data::~Data()
{

}

std::vector <sf::Text>& Data::getText_UnitCountVec()
{
	return text_UnitCountVec;
}

void Data::text_updateUnitCount(const int& terrNumber, const int& new_UnitCount)
{
	std::ostringstream strStream;
	strStream << new_UnitCount;

	text_UnitCountVec.at(terrNumber -1).setString(strStream.str().c_str());
}

sf::Sprite Data::getSpecificTerrSpriteColor(const int& terrNumber, const char& color)
{
	switch (color)
	{
	case 'b':
		{
			return spr_terrBlueVec.at(terrNumber);
			break;
		}
	case 'r':
		{
			return spr_terrRedVec.at(terrNumber);
			break;
		}
	case 'y':
		{
			return spr_terrYellVec.at(terrNumber);
			break;
		}
	default:
		{
			std::cout << "ERROR laoding Color_Sprites!" << std::endl << std::endl;
			break;
		}
	}
}