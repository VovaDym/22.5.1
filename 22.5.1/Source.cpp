#include <iostream>
#include <map>
#include <string>
#include <vector>

int requestDeterminant(std::string enterRequest)
{
	int request;
	if (enterRequest.length() == 8 && enterRequest[2] == '-' && enterRequest[5] == '-') 
	{
		request = 2;
	}
	else if (enterRequest.length() > 8 && enterRequest[9] >= 'A' && enterRequest[9] <= 'Z')
	{
		request = 1;
	}
	else if (enterRequest[0] >= 'A' && enterRequest[0] <= 'Z' && enterRequest[1] >= 'a' && enterRequest[1] <= 'z')
	{
		request = 3;
	}
	else
	{
		std::cout << "Error!Incorrect input";
		request = -1;
	}
	return request;
}

int main()
{
	std::map <std::string, std::string> phoneName;
	std::map <std::string, std::vector<std::string>> namePhone;
	std::vector<std::string> tmp;
    std::string name;
	std::string number;
    int request = 0;
	std::string enterRequest;
	
	while (true)
	{
		do
		{
			std::getline(std::cin,enterRequest);
			request = requestDeterminant(enterRequest);
		} 
		while (request < 1 || request > 3);
		

		std::cout << std::endl;

		if (request == 1)
		{
			for (int i = 0; i < enterRequest.length(); ++i)
			{
				if (i < 8)
				{
					number += enterRequest[i];
				}
				else if (i >= 9)
				{
					name += enterRequest[i];
				}
			}
		    			
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
			name.clear();
			number.clear();
		}
		else if (request == 2)
		{	
            system("cls");
			number = enterRequest;
			
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
			name = enterRequest;

			auto personName = namePhone.find(name);
            if (personName != namePhone.end())
			{
				int countNumbers = personName->second.size();
				for (int i = 0; i < countNumbers; ++i)
				{
					std::cout << personName->second[i] << " ";
				}
			}
			else
			{
				std::cout << "Element not found" << std::endl;
			}	
		}
	} 		
}