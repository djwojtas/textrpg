#include "DiceSerie.h"
#include "WriteOut.h"
#include "AskPlayer.h"
#include <algorithm>
#include <iostream>

using namespace std;

DiceSerie::DiceSerie()
{
    for(int i=0; i<5; i++)
    {
        Dice new_dice;
        dice_serie.push_back(new_dice);
    }

    int die_combination_value = 0;

    counters.resize(6);
    fill(counters.begin(), counters.end(), 0);
}

DiceSerie::DiceSerie(int one, int two, int three, int four, int five)
{
    Dice Done(one);
    Dice Dtwo(two);
    Dice Dthree(three);
    Dice Dfour(four);
    Dice Dfive(five);

    dice_serie.push_back(Done);
    dice_serie.push_back(Dtwo);
    dice_serie.push_back(Dthree);
    dice_serie.push_back(Dfour);
    dice_serie.push_back(Dfive);

    int die_combination_value = 0;

    counters.resize(6);
    fill(counters.begin(), counters.end(), 0);
}

void DiceSerie::roll()
{
    for(int i=0; i<5; i++)
    {
        dice_serie[i].rollDice();
    }

    std::sort (dice_serie.begin(), dice_serie.end());
}

void DiceSerie::printDie()
{
    cout<<endl;
    cout<<'|';

    for(int i=0; i<5; i++)
    {
        cout<<dice_serie[i].getAmountOfPips()<<'|';
    }
    cout<<endl;
}

void DiceSerie::rollChosen(vector<bool>& dieToReRoll)
{
    for(int i=0; i<5; i++)
    {
        if(dieToReRoll[i])
            dice_serie[i].rollDice();
    }

    std::sort (dice_serie.begin(), dice_serie.end());
}

void DiceSerie::rollChosenUserInput()
{
    vector<bool> user_re_roll_mask;

    for(int i=0; i<5; i++)
    {
        string user_choice;

        string message_to_print="";
        message_to_print+="[";
        message_to_print+=to_string(i+1);
        message_to_print+="]";
        message_to_print+=" Do you want to re-roll dice nr. ";
        message_to_print+=to_string(i+1);
        message_to_print+=" (Y/N) ?: ";

        user_choice = ask.askForString(message_to_print, "Try again!");

        transform(user_choice.begin(), user_choice.end(), user_choice.begin(), ::tolower);

        if(user_choice == "y")
        {
            user_re_roll_mask.push_back(true);
        }
        else
        {
            user_re_roll_mask.push_back(false);
        }
    }

    rollChosen(user_re_roll_mask);
}

void DiceSerie::computerReRoll()
{
    vector<bool> computer_re_roll_mask;

    std::vector<int>::iterator result;
    result = std::max_element(counters.begin(), counters.end());

    int most_frequent_amount_of_pips = std::distance(counters.begin(), result);

    for(int i=0; i<5; i++)
    {
        if(dice_serie[i].getAmountOfPips()-1 == most_frequent_amount_of_pips)
        {
            computer_re_roll_mask.push_back(false);
        }
        else
        {
            computer_re_roll_mask.push_back(true);
        }
    }

    rollChosen(computer_re_roll_mask);
}

void DiceSerie::refreshValue()
{
    if      ( isPoker() )          { die_combination_value = 1000000000; }
    else if ( isFourOfAKind() )    { die_combination_value = 100000000; }
    else if ( isFullHouse() )      { die_combination_value = 10000000; }
    else if ( isGreatStraight() )  { die_combination_value = 1000000; }
    else if ( isLittleStraight() ) { die_combination_value = 100000; }
    else if ( isThreeOfAKind() )   { die_combination_value = 10000; }
    else if ( isTwoPair() )        { die_combination_value = 1000; }
    else if ( isOnePair() )        { die_combination_value = 100; }
    else if ( isHighCard() )       { die_combination_value = 10; }

    for(int i=0; i<5; i++)
    {
        die_combination_value += dice_serie[i].getAmountOfPips();
    }
}

int DiceSerie::getValue()
{
    return die_combination_value;
}

void DiceSerie::countAmountsOfPips()
{
    fill(counters.begin(), counters.end(), 0);
    for(int i=0; i<5; i++)
    {
        counters[ dice_serie[i].getAmountOfPips()-1 ]++;
    }
}

bool DiceSerie::isPoker()
{
    bool is_poker = false;

    for(int i=0; i<6; i++)
    {
        if(counters[i]==5)
            is_poker = true;
    }

    return is_poker;
}

bool DiceSerie::isFourOfAKind()
{
    bool is_four_of_a_kind = false;

    for(int i=0; i<6; i++)
    {
        if(counters[i]==4)
            is_four_of_a_kind = true;
    }

    return is_four_of_a_kind;
}

bool DiceSerie::isFullHouse()
{
    bool is_pair = false;
    bool is_three_of_a_kind = false;

    for(int i=0; i<6; i++)
    {
        if(counters[i]==3)
            is_three_of_a_kind = true;
        else if (counters[i]==2)
            is_pair = true;
    }

    return (is_pair && is_three_of_a_kind);
}

bool DiceSerie::isGreatStraight()
{
    return ( (dice_serie[0]==2) && (dice_serie[1]==3) && (dice_serie[2]==4) && (dice_serie[3]==5) && (dice_serie[4]==6) );
}

bool DiceSerie::isLittleStraight()
{
    return ( (dice_serie[0]==1) && (dice_serie[1]==2) && (dice_serie[2]==3) && (dice_serie[3]==4) && (dice_serie[4]==5) );
}

bool DiceSerie::isThreeOfAKind()
{
    bool is_three_of_a_kind = false;

    for(int i=0; i<6; i++)
    {
        if(counters[i]==3)
            is_three_of_a_kind = true;
    }

    return is_three_of_a_kind;
}

bool DiceSerie::isTwoPair()
{
    int pair_counter = 0;

    for(int i=0; i<6; i++)
    {
        if(counters[i]==2)
            pair_counter++;
    }

    return ( pair_counter == 2 );
}

bool DiceSerie::isOnePair()
{
    int pair_counter = 0;

    for(int i=0; i<6; i++)
    {
        if(counters[i]==2)
            pair_counter++;
    }

    return ( pair_counter == 1 );
}

bool DiceSerie::isHighCard()
{
    int one_counter = 0;

    for(int i=0; i<6; i++)
    {
        if(counters[i]==1)
            one_counter++;
    }

    return (( one_counter == 5 ) && ( !isGreatStraight() ) && ( !isLittleStraight() ));
}

bool DiceSerie::operator < (DiceSerie& ex)
{
    return this->getValue() < ex.getValue();
}

bool DiceSerie::operator > (DiceSerie& ex)
{
    return this->getValue() > ex.getValue();
}

bool DiceSerie::operator == (DiceSerie& ex)
{
    return this->getValue() == ex.getValue();
}
