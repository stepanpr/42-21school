
#include "FragTrap.hpp"

void enter(char *string)
{
	int i;

	i = -1;
	while (string)
	{
		string[i] = std::cin.get();
		if (string[i] == 0x0A)
			break ;
		++i;
	}
	string[i] = 0;
}

int cycle(FragTrap& robot, std::string& enemy)
{
	std::string cmd;
	char *string = new char;
	int num;

	robot.set_Name_of_enemy(enemy);

	std::cout << "press ENTER to continue" << std::endl;
	cmd = std::cin.get();
	enter(string);

	while (1)
	{
		std::cout << " 💬 \e[0;36mWhat type of attack do you want to use:" << std::endl
		<< "(1)\e[1;34m rangedAttack\e[0;34m 🏹 (damage: 20; points of energy: 5)" << std::endl
		<< "\e[0;36m(2)\e[1;34m meleeAttack?\e[0;34m 🥊 (damage: 30; points of energy: 10)" << std::endl
		<< "enter the number of type >\e[0m "; 
		std::cin >> cmd;
		if (cmd != "1" && cmd != "2")
		{
			continue ; 
		}
		cmd == "1" ? robot.rangedAttack(enemy) : robot.meleeAttack(enemy);			//атака на дистанции и в "врукопашную"
		std::cout << "press ENTER to continue" << std::endl;
		cmd = std::cin.get();
		enter(string);

		while(1)
		{
			std::cout << " ❗ \e[0;36mNow \e[1;35m" << enemy << "\e[0;36m is attacking!\e[0m" << std::endl;
			while(1)
			{
					std::cout << "\e[0;34menter the damage from enemy, it will do between 1 and 200 > \e[0m";
					std::cin >> num;
				if (std::cin.fail() || num < 1 || num > 200)
				{
					std::cin.clear();
					std::cin.ignore(32767,'\n');
					std::cout << "number is incorrect" << std::endl;
					continue ;
				}
				else 
					break ;
			}
				robot.takeDamage(num);												//полученный урон от противника
				if (robot.get_Destroyed() == 1)
				{
					std::cout << " 🤖💬 \e[0;36mFR4G-TP \e[1;32m" << robot.get_Name() << "\e[0;36m: \e[0;32mcrack-crack-crack... crack...\e[0m" << std::endl;
					break ;
				}
				std::cout << "press ENTER to continue" << std::endl;
				cmd = std::cin.get();
				enter(string);
				break;
		}
		if (robot.get_Destroyed() == 1)   //проверяем уничтожен ли робот
		{
			break ;
		}
		robot.vaulthunter_dot_exe(enemy);												//атака случайная
		if (robot.get_Energy_for_vaulthunter() == 1) //проверяем остались ли поинты на случайную атаку
		{
			std::cout << "press ENTER to continue" << std::endl;
			enter(string);
		}
		while(1)																		//восстановление хит-поинтов и поинтов энергии
		{
			std::cout << " 💬 \e[0;36m\e[0;36mFinally you got to the repair station! How many points do you want to charge?\e[0m 🔌" << std::endl;

			while(1)
			{
					std::cout << "\e[0;34menter the number of points between 1 and 100 > \e[0m";
					std::cin >> num;
				if (std::cin.fail() || num < 1 || num > 100)
				{
					std::cin.clear();
					std::cin.ignore(32767,'\n');
					std::cout << "number is incorrect" << std::endl;
					continue ;
				}
				else 
					break ;
			}
			robot.beRepaired(num);
			std::cout << "press ENTER to continue" << std::endl;
			cmd = std::cin.get();
			enter(string);
			break;
		}
	}
	return (0);
}

int main()
{
	int type;
	std::string enemy = new (char);
	std::cout << std::endl <<  "\e[0;34mChoose the name of your enemy (enter the name) > \e[0m" << std::endl;
	std::cin >> enemy;

	std::cout << std::endl <<  " 👮 \e[0;34mCaptain Malloc: 💬 \e[0;36m\"The enemy is already near! Which robot will you use?\"" << std::endl 
	<< "(1)\e[1;34m NoName \e[0;34m(🏥: 100; 🔋: 100; 🛡: 5)" << std::endl 	// (hit-points: 100; points of energy: 100; armor: 5)
	<< "\e[0;36m(2)\e[1;34m MadCat \e[0;34m(🏥: 100; 🔋: 100; 🛡: 5)" << std::endl
	<< "\e[0;36m(3)\e[1;34m CopyOfMadCat \e[0;34m(🏥: 100; 🔋: 100; 🛡: 5)" << std::endl
	<< "\e[0;34menter the number (1-3) > \e[0m";
	std::cin >> type;
	if (type != 1 && type != 2 && type != 3)
	{
		std::cout << "\e[0;33mYou entered an invalid value ... Bye\e[0m!" << std::endl;
		return (0);
	}
		
	std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
	if (type == 1)
	{
		FragTrap robot1;
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle(robot1, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	if (type == 2)
	{
		FragTrap robot2("MadCat");
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle(robot2, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	if (type == 3)
	{
		FragTrap robot2("MadCat");
		FragTrap robot3 = robot2;
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle(robot3, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}

	std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	std::cout << "\e[1;33mGAME OVER!\e[0m" << std::endl;
	return 0;
}
