#include <iostream>
#include <map>
#include <string>
#include <vector>


bool correctN(std::string number)
{
	if (number.length() != 8 ||
		number[2] != '-' || number[5] != '-')
		return false;

	int block1 = std::stoi(number.substr(0, 2));
	int block2 = std::stoi(number.substr(3, 2));
	int block3 = std::stoi(number.substr(6, 2));

	if (block1 >= 10 && block1 <= 99 && block2 >= 10 && block2 <= 99 && block3 >= 10 && block3 <= 99)
	{
        return true;
	}
		
	return false;
}

int main()
{
	std::map <std::string, std::string> phoneName;
	std::map <std::string, std::vector<std::string>> namePhone;
    std::string name;
	std::string number;

	int request = 1;
	
	while (true)
	{
		int request = -1;
		std::cout << "Enter 0 to terminate the program" << std::endl;
		std::cout << "Enter 1 to add a subscriber" << std::endl;
		std::cout << "Enter 2 to search for a subscriber by number" << std::endl;
		std::cout << "Enter 3 to find out the subscriber's number by name" << std::endl;
		
		while (request < 0 || request > 3)
		{
			std::cin >> request;
			if (request == 0) return 0;
		}

		std::cout << std::endl;

		if (request == 1)
		{
            system("cls");
		    std::cout << "Enter name person" << std::endl;
		    std::cin >> name;
			do
			{
                std::cout << "Enter number telephon" << std::endl;
                std::cin >> number;
			} while (!correctN(number));
		    
			std::vector<std::string> tmp;
			tmp.push_back(number);

			phoneName.insert(std::pair<std::string, std::string>(number, name));

			std::map<std::string, std::vector<std::string>>::iterator itnp;

			itnp = namePhone.find(name);
			if (itnp == namePhone.end())
			{
				namePhone.insert(std::pair<std::string, std::vector<std::string>>(name,
					tmp));
			}
			else
			{
				itnp->second.push_back(number);
				std::cout << "The phone number to the subscriber " << name << " has been added" << std::endl;
			}
		}
		else if (request == 2)
		{	
            system("cls");
            std::cout << "Find a subscriber by number: " << std::endl;
			std::cout << "Enter a number: " << std::endl;
	        std::cin >> number;
			
	        auto it = phoneName.find(number);
			if (it != phoneName.end())
			{
				std::cout << it->second << std::endl;
			}
			else
			{
				std::cout << "Element not found" << std::endl;
			}		
		}
		else if (request == 3)
		{
			system("cls");
			std::cout << "Search for a phone number by subscriber name: " << std::endl;
			std::cout << "Enter a name: " << std::endl;
			std::cin >> name;

			auto personName = namePhone.find(name);
            if (personName != namePhone.end())
			{
				int countNumbers = personName->second.size();
				for (int i = 0; i < countNumbers; ++i)
				{
					std::cout << personName->second[i] << std::endl;
				}
			}
			else
			{
				std::cout << "Element not found" << std::endl;
			}	
		}
	} 		
}