

#include <iostream>
#include <map>
#include <string>
#include <vector>

bool inCorrectPhone(std::string);
void expectation();

int main()
{
    std::map <std::string, std::string> name;
    std::map <std::string, std::vector<std::string>> number;
    while (true)
    {
        std::string answer;
        int spacePos = -1;
        bool err = true;

        while (err)
        {
            system("cls");
            err = false;
            std::cout << "Enter your request: ";
            std::getline(std::cin, answer);

            for (int i = 0; (i < answer.length()) && !err; ++i)
                if (answer[i] == ' ')
                    spacePos == -1 ? spacePos = i : err = true;

            if (!err && spacePos != -1 &&
                !inCorrectPhone(answer.substr(0, spacePos)))
                err = true;
            if (err)
            {
                system("cls");
                std::cout << "Incorrect request" << std::endl << std::endl;

                expectation();
            }
        }

        system("cls");
        if (spacePos == -1)
            if (inCorrectPhone(answer))
            {
                std::cout << "Phone number: " << answer << std::endl;
                std::cout << "  Subscriber: " << name.find(answer)->second << std::endl;

                expectation();
            }
            else
            {
                std::cout << "  Subscriber: " << answer << std::endl;
                std::cout << "Phone number: ";

                auto person = number.find(answer);
                int countNumbers = person->second.size();
                for (int i = 0; i < countNumbers; ++i)
                    std::cout << person->second[i] << ' ';
                expectation();
            }
        else
        {
            std::string phone = answer.substr(0, 8);
            std::string namePerson = answer.substr(9, answer.length() - 9);
            std::vector<std::string> tmp;
            tmp.push_back(phone);

            name.insert(std::pair<std::string, std::string>(phone, namePerson));

            std::map<std::string, std::vector<std::string>>::iterator itN;
            itN = number.find(namePerson);
            if (itN == number.end())
                number.insert(std::pair<std::string, std::vector<std::string>>(namePerson, tmp));
            else
                itN->second.push_back(phone);
            std::cout << "Information added" << std::endl;

            expectation();
        }
    }
}

void expectation()
{
    std::string answer = "";
    std::cout << std::endl << "Enter 0 to continue" << std::endl;
    while (answer != "0")
        std::getline(std::cin, answer);
}

bool inCorrectPhone(std::string number)
{
    if (number.length() != 8 ||
        number[2] != '-' || number[5] != '-')
        return false;

    int block1 = std::stoi(number.substr(0, 2));
    int block2 = std::stoi(number.substr(3, 2));
    int block3 = std::stoi(number.substr(6, 2));

    if (block1 >= 10 && block1 <= 99 &&
        block2 >= 10 && block2 <= 99 &&
        block3 >= 10 && block3 <= 99)
        return true;

    return false;
}