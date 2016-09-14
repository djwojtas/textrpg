#include "City.h"
#include "Suburbs.h"
#include "MainSquare.h"
#include "LeftDistrict.h"
#include "RightDistrict.h"
#include "../../API/AskPlayer.h"
#include "../../API/WriteOut.h"

using namespace std;

void City::setChoice(int choice_)
{
    choice=choice_;
}

int City::getChoice() const
{
    return choice;
}

void City::play(Heroe& subject)
{
    ask.say("(#SOMEWHERE IN THE CITY) You stop for a moment and take a look.\nAll around you, there is a lot of people.\nThey are talking with each other, screaming, running, selling some stuff...");

    int user_choice=ask.askForInt(
                        "Where do you want to go?",
                        "You do not like sticking to rules, huh?",
                        1,4,
                        "Type 1 to head towards Suburbs\n2 to head towards Main Square\n3 to head towards Left District\n4 to head towards Right District:"
                    );
    ask.endSection();

    this->setChoice(user_choice);
}

GameStep* City::getNext()
{
    if(getChoice()==1)
    {
        Suburbs* suburbs_after_city = new Suburbs();
        return suburbs_after_city;
    }
    else if(getChoice()==2)
    {
        MainSquare* main_square_after_city = new MainSquare();
        return main_square_after_city;
    }
    else if (getChoice()==3)
    {
        LeftDistrict* left_district_after_city = new LeftDistrict();
        return left_district_after_city;
    }
    else if (getChoice()==4)
    {
        RightDistrict* right_district_after_city = new RightDistrict();
        return right_district_after_city;
    }
}
