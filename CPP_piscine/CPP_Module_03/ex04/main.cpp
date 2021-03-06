
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"


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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cycle_FR4GTP(FragTrap& robot, std::string& enemy)
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
					std::cout << " 🤖💬 \e[0;36mClapTrap \e[1;32m" << robot.get_Name() << "\e[0;36m: \e[0;32mcrack-crack-crack... crack...\e[0m" << std::endl;
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
		robot.vaulthunter_dot_exe(enemy);												//способность (атака случайная)
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


int FR4GTP(std::string enemy)
{
	int type;

	std::cout << std::endl <<  " 👮 \e[0;34mCaptain Malloc: 💬 \e[0;36m\"The enemy is already near! Which robot will you use?\"" << std::endl 
	<< "(1)\e[1;34m NoName " << std::setw(68) << "\e[0;34m(🏥: 100; 🔋: 100; 🛡: 5; 🏹: 20; 🥊: 30;)" << std::endl 	// (hit-points: 100; points of energy: 100; armor: 5)
	<< "\e[0;36m(2)\e[1;34m MadCat " << std::setw(68) << "\e[0;34m(🏥: 100; 🔋: 100; 🛡: 5; 🏹: 20; 🥊: 30;)" << std::endl
	<< "\e[0;36m(3)\e[1;34m CopyOfMadCat " << std::setw(62) << "\e[0;34m(🏥: 100; 🔋: 100; 🛡: 5; 🏹: 20; 🥊: 30;)" << std::endl
	<< "\e[0;34menter the number (1-3) > \e[0m";
	std::cin >> type;
	if (type != 1 && type != 2 && type != 3)
	{
		std::cout << "\e[0;33mYou entered an invalid value ... Bye\e[0m!" << std::endl;
		return 1;
	}
		
	std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
	if (type == 1)
	{
		FragTrap robot1;
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_FR4GTP(robot1, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	if (type == 2)
	{
		FragTrap robot2("MadCat");
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_FR4GTP(robot2, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	if (type == 3)
	{
		FragTrap robot2("MadCat");
		FragTrap robot3 = robot2;
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_FR4GTP(robot3, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cycle_CL4GTP(ScavTrap& robot, std::string& enemy)
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
		<< "(1)\e[1;34m rangedAttack\e[0;34m 🏹 (damage: 15; points of energy: 5)" << std::endl
		<< "\e[0;36m(2)\e[1;34m meleeAttack?\e[0;34m 🥊 (damage: 20; points of energy: 10)" << std::endl
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
					std::cout << " 🤖💬 \e[0;36mClapTrap \e[1;32m" << robot.get_Name() << "\e[0;36m: \e[0;32mcrack-crack-crack... crack...\e[0m" << std::endl;
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
		// robot.vaulthunter_dot_exe(enemy);
		robot.challengeNewcomer(enemy);												//спосбоность
		// if (robot.get_Energy_for_vaulthunter() == 1) //проверяем остались ли поинты на случайную атаку
		// {
			std::cout << "press ENTER to continue" << std::endl;
			enter(string);
		// }
		while(1)																	//восстановление хит-поинтов и поинтов энергии
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




int CL4GTP(std::string enemy)
{
	int type;

	std::cout << std::endl <<  " 👮 \e[0;34mCaptain Moulinette: 💬 \e[0;36m\"The enemy is already near! Which robot will you use?\"" << std::endl 
	<< "(1)\e[1;34m NoName " << std::setw(67) << "\e[0;34m(🏥: 100; 🔋:  50; 🛡: 3; 🏹: 15; 🥊: 20;)" << std::endl 	// (hit-points: 100; points of energy: 100; armor: 5)
	<< "\e[0;36m(2)\e[1;34m Daddy " << std::setw(68) << "\e[0;34m(🏥: 100; 🔋:  50; 🛡: 3; 🏹: 15; 🥊: 20;)" << std::endl
	<< "\e[0;36m(3)\e[1;34m CopyOfDaddy " << std::setw(62) << "\e[0;34m(🏥: 100; 🔋:  50; 🛡: 3; 🏹: 15; 🥊: 20;)" << std::endl
	<< "\e[0;34menter the number (1-3) > \e[0m";
	std::cin >> type;
	if (type != 1 && type != 2 && type != 3)
	{
		std::cout << "\e[0;33mYou entered an invalid value ... Bye\e[0m!" << std::endl;
		return 1;
	}
		
	std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
	if (type == 1)
	{
		ScavTrap robot1;
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_CL4GTP(robot1, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	if (type == 2)
	{
		ScavTrap robot2("Daddy");
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_CL4GTP(robot2, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	if (type == 3)
	{
		ScavTrap robot2("Daddy");
		ScavTrap robot3 = robot2;
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_CL4GTP(robot3, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int cycle_NinjaTP(NinjaTrap& robot, std::string& enemy)
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
		<< "(1)\e[1;34m rangedAttack\e[0;34m 🏹 (damage: 15; points of energy: 5)" << std::endl
		<< "\e[0;36m(2)\e[1;34m meleeAttack?\e[0;34m 🥊 (damage: 20; points of energy: 10)" << std::endl
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
					std::cout << " 🤖💬 \e[0;36mClapTrap \e[1;32m" << robot.get_Name() << "\e[0;36m: \e[0;32mcrack-crack-crack... crack...\e[0m" << std::endl;
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
	
		{																					//спосбоность		
			std::cout << "\e[1;33m---------SUPERPOWER----------\e[0m" <<std::endl;															
			std::cout << "\e[0;36m...suddenly run out friends of \e[1;32m" << robot.get_Name() << ", and trying to protect their comrade...\e[0m" << std::endl;
			FragTrap *friend1 = new FragTrap("FragTrap Paul");
			ScavTrap *friend2 = new ScavTrap("ScavTrap Raul");
			NinjaTrap *friend3 = new NinjaTrap("NinjaTrap Carmen");
			robot.ninjaShoebox(*friend1);
			robot.ninjaShoebox(*friend2);
			robot.ninjaShoebox(*friend3);
			std::cout << "\e[0;36m...but \e[1;35m" << robot.get_Name_of_enemy() << "\e[0;36m destroys them mercilessly...\e[0m" << std::endl;
			delete(friend1);
			delete(friend2);
			delete(friend3);
			std::cout << "\e[1;33m---------SUPERPOWER-is-over--\e[0m" <<std::endl;
			std::cout << "press ENTER to continue" << std::endl;
			enter(string);
		}

		while(1)																	//восстановление хит-поинтов и поинтов энергии
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


int NinjaTP(std::string enemy)
{
	int type;

	std::cout << std::endl <<  " 👮 \e[0;34mCaptain Norminette: 💬 \e[0;36m\"The enemy is already near! Which robot will you use?\"" << std::endl 
	<< "(1)\e[1;34m NoName " << std::setw(71) << "\e[0;34m(🏥: 60; 🔋:  120; 🛡: 0; 🏹:  5; 🥊: 60;)" << std::endl
	<< "\e[0;36m(2)\e[1;34m DarkNinja " << std::setw(68) << "\e[0;34m(🏥: 60; 🔋:  120; 🛡: 0; 🏹:  5; 🥊: 60;)" << std::endl
	<< "\e[0;36m(3)\e[1;34m CopyOfDarkNinja " << std::setw(62) << "\e[0;34m(🏥: 60; 🔋:  120; 🛡: 0; 🏹:  5; 🥊: 60;)" << std::endl
	<< "\e[0;34menter the number (1-3) > \e[0m";
	std::cin >> type;
	if (type != 1 && type != 2 && type != 3)
	{
		std::cout << "\e[0;33mYou entered an invalid value ... Bye\e[0m!" << std::endl;
		return 1;
	}
		
	std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
	if (type == 1)
	{
		NinjaTrap robot1;
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_NinjaTP(robot1, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	if (type == 2)
	{
		NinjaTrap robot2("DarkNinja");
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_NinjaTP(robot2, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	if (type == 3)
	{
		NinjaTrap robot2("DarkNinja");
		NinjaTrap robot3 = robot2;
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_NinjaTP(robot3, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int cycle_SuperTP(SuperTrap& robot, std::string& enemy)
{
	std::string cmd;
	char *string = new char;
	int num;

	robot.FragTrap::set_Name_of_enemy(enemy);

	std::cout << "press ENTER to continue" << std::endl;
	cmd = std::cin.get();
	enter(string);

	while (1)
	{
		std::cout << " 💬 \e[0;36mWhat type of attack do you want to use:" << std::endl
		<< "(1)\e[1;34m rangedAttack\e[0;34m 🏹 (damage: 15; points of energy: 5)" << std::endl
		<< "\e[0;36m(2)\e[1;34m meleeAttack?\e[0;34m 🥊 (damage: 20; points of energy: 10)" << std::endl
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
				robot.FragTrap::takeDamage(num);												//полученный урон от противника
				if (robot.FragTrap::get_Destroyed() == 1)
				{
					std::cout << " 🤖💬 \e[0;36mClapTrap \e[1;32m" << robot.FragTrap::get_Name() << "\e[0;36m: \e[0;32mcrack-crack-crack... crack...\e[0m" << std::endl;
					break ;
				}
				std::cout << "press ENTER to continue" << std::endl;
				cmd = std::cin.get();
				enter(string);
				break;
		}
		if (robot.FragTrap::get_Destroyed() == 1)   //проверяем уничтожен ли робот
		{
			break ;
		}


		{																					//спосбоность		
			std::cout << "\e[1;33m---------SUPERPOWER-of-NinjaTrap-\e[0m" <<std::endl;															
			std::cout << "\e[0;36m...suddenly run out friends of \e[1;32m" << robot.get_Name() << ", and trying to protect their comrade...\e[0m" << std::endl;
			FragTrap *friend1 = new FragTrap("FragTrap Paul");
			ScavTrap *friend2 = new ScavTrap("ScavTrap Raul");
			NinjaTrap *friend3 = new NinjaTrap("NinjaTrap Carmen");

			robot.ninjaShoebox(*friend1);
			robot.ninjaShoebox(*friend2);
			robot.ninjaShoebox(*friend3);
			std::cout << "\e[0;36m...but \e[1;35m" << robot.get_Name_of_enemy() << "\e[0;36m destroys them mercilessly...\e[0m" << std::endl;
			delete(friend1);
			delete(friend2);
			delete(friend3);
			std::cout << "\e[1;33m---------SUPERPOWER-is-over------\e[0m" <<std::endl;
			std::cout << "press ENTER to continue" << std::endl;
			enter(string);
		}
		{																					//спосбоность
			std::cout << "\e[1;33m---------SUPERPOWER-of-FragTrap--\e[0m" <<std::endl;	
					robot.vaulthunter_dot_exe(enemy);
			std::cout << "\e[1;33m---------SUPERPOWER-is-over------\e[0m" <<std::endl;
			if (robot.get_Energy_for_vaulthunter() == 1)
			{
				std::cout << "press ENTER to continue" << std::endl;
				enter(string);
			}
		}
		while(1)																				//восстановление хит-поинтов и поинтов энергии
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
			robot.FragTrap::beRepaired(num);
			std::cout << "press ENTER to continue" << std::endl;
			cmd = std::cin.get();
			enter(string);
			break;
		}
	}
	return (0);
}

int SuperTP(std::string enemy)
{

	int type;

	std::cout << std::endl <<  " 👮 \e[0;34mCaptain Array: 💬 \e[0;36m\"The enemy is already near! Which robot will you use?\"" << std::endl 
	<< "(1)\e[1;34m NoName " << std::setw(73) << "\e[0;34m(🏥: 100; 🔋:  120; 🛡: 5; 🏹:  20; 🥊: 60;)" << std::endl 
	<< "\e[0;36m(2)\e[1;34m SuperRanger " << std::setw(68) << "\e[0;34m(🏥: 100; 🔋:  120; 🛡: 5; 🏹:  20; 🥊: 60;)" << std::endl
	<< "\e[0;36m(3)\e[1;34m CopyOfSuperRanger " << std::setw(62) << "\e[0;34m(🏥: 100; 🔋:  120; 🛡: 5; 🏹:  20; 🥊: 60;)" << std::endl
	<< "\e[0;34menter the number (1-3) > \e[0m";
	std::cin >> type;
	if (type != 1 && type != 2 && type != 3)
	{
		std::cout << "\e[0;33mYou entered an invalid value ... Bye\e[0m!" << std::endl;
		return 1;
	}
		
	std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
	if (type == 1)
	{
		SuperTrap robot1;
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_SuperTP(robot1, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	if (type == 2)
	{
		SuperTrap robot2("SuperRanger");
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_SuperTP(robot2, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	if (type == 3)
	{
		SuperTrap robot2("SuperRanger");
		SuperTrap robot3 = robot2;
		std::cout << "\e[0;33m-----creating-----\e[0m" << std::endl;
		cycle_SuperTP(robot3, enemy);
		std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{
	std::string model_of_robot;
	std::string enemy = new (char);

	std::cout << std::endl <<  "\e[0;34mChoose the name of your enemy (enter the name) " << std::endl <<  "> \e[0m";
	std::cin >> enemy;

	while (1)
	{
		std::cout << std::endl <<  "\e[0;34mChoose the model of robot" << std::endl
		<< "\e[0;34m(1)\e[1;34mFR4GTP " << std::setw(63) << "\e[0;34m(🏥: 100; 🔋: 100; 🛡: 5; 🏹: 20; 🥊: 30;)" << std::endl
		<< "\e[0;34m(2)\e[1;34mCL4GTP " << std::setw(63) << "\e[0;34m(🏥: 100; 🔋:  50; 🛡: 3; 🏹: 15; 🥊: 20;)" << std::endl
		<< "\e[0;34m(3)\e[1;34mNinjaTP " << std::setw(60) << "\e[0;34m(🏥: 60; 🔋: 120; 🛡: 3; 🏹: 5; 🥊: 60;)" << std::endl
		<< "\e[0;34m(4)\e[1;34mSuperTrap " << std::setw(60) << "\e[0;34m(🏥: 100; 🔋: 120; 🛡: 5; 🏹: 20; 🥊: 60;)" << std::endl
		<<  "enter the number > \e[0m";
		std::cin >> model_of_robot;

		if (model_of_robot == "1")
		{
			if(FR4GTP(enemy))
				return 0;
			break ;
		}
		else if (model_of_robot == "2")
		{
			if(CL4GTP(enemy))
				return 0;
			break ;
		}
		else if (model_of_robot == "3")
		{
			if(NinjaTP(enemy))
				return 0;
			break ;
		}
		else if (model_of_robot == "4")
		{
			if(SuperTP(enemy))
				return 0;
			break ;
		}
		else 
		{
			std::cout << "value is incorrect" << std::endl;
			continue ;
		}
	}

	std::cout << "\e[0;33m-----destruction-----\e[0m" << std::endl;
	std::cout << "\e[1;33mGAME OVER!\e[0m" << std::endl;
	return 0;
}
