/**
* \file AskPlayer.h
* \author RPGteam
* \date 21.06.2016
* \version 1.0
* \brief File contains the definition of AskPlayer class
*/
// -------------------------------------------------------------------------

#ifndef ASKPLAYER_H
#define ASKPLAYER_H

#include "../Characters/Heroe.h"
#include "../Characters/Monster.h"

using namespace std;

/**
* \class AskPlayer
* \author RPGteam
* \date 21.06.2016
* \brief AskPlayer class gives API for communication with player
*   AskPlayer handles mostly two things. It takes care of formating output, like when to add endline or insert some signs.
*   Also, it can be used for getting information from player and assuring that data is (probably) valid.
*   Class should be used by calling "ask" global object. Eg. ask.say("Hello");
*/
class AskPlayer
{
  int state = 0; ///< State is 1 when last message was from computer and 0 when from user
public:
  /// \brief State setter, can be used to override default class settings
  /** State setter can be used to override default class settings */
  /// \param state_ - 0 or anything - it's used as boolean in case there are need to use more states
  void setState(int state_);

  /// \brief Makes space between sections, smaller than chapter's spacing
  void endSection();

  /// \brief Makes space between chapters, bigger than section's spacing
  void endChapter();

  /// \brief Print's message as Player
  /** Method will try to separate sentence from NPC and computer sentences. It should look like player is filling cin*/
  /// \param message - message that player should say
  void playerSay(string message);

  /// \brief Print's message as NPC
  /** Method will try to separate sentence from player's.*/
  /// \param message - message that computer should say
  void say(string message);

  /// \brief Print's message as Narrator
  /** Method will try to separate sentence from player's.*/
  /// \param message - message that narrator should say
  void narrate(string message);

  /// \brief Asks player for INT from certain range and validates it
  /** Method will write message as NPC than player will have to write answer. If answer was correct (from specified range
  * and same INT type) function will return. If not - fail_message will be written and process starts again */
  /// \param message - question that computer should ask
  /// \param fail_message - sentence that computer should say after invalid answer
  /// \param minimum - minimum of range that INT should be from (more or equal)
  /// \param maximum - maximum of range that INT should be from (less or equal)
  /// \param narrate_message - message in which you should explain what to do, for example "type 1-4"
  /// \return Returns int that player provided
  int askForInt(string message, string fail_message, int minimum, int maximum, string narrate_message = "");

  /// \brief Asks player for double from certain range and validates it
  /** Method will write message as NPC than player will have to write answer. If answer was correct (from specified range
  * and same double type) function will return. If not - fail_message will be written and process starts again */
  /// \param message - question that computer should ask
  /// \param fail_message - sentence that computer should say after invalid answer
  /// \param minimum - minimum of range that double should be from (more or equal)
  /// \param maximum - maximum of range that double should be from (less or equal)
  /// \param narrate_message - message in which you should explain what to do, for example "type 1-4"
  /// \return Returns double that player provided
  double askForDouble(string message, string fail_message, double minimum, double maximum, string narrate_message = "");

  /// \brief Asks player for string.
  /** Method will write message as NPC than player will have to write answer. If answer was correct (if cin won't produce
  * error) function will return. If not - fail_message will be written and process starts again */
  /// \param message - question that computer should ask
  /// \param fail_message - sentence that computer should say after invalid answer
  /// \param narrate_message - message in which you should explain what to do, for example "if you type x then y, otherwise z"
  /// \return Returns string that player provided
  string askForString(string message, string fail_message, string narrate_message = "");

  /// \brief Prints actual fight - names and stats
  /// \param subject - Heroe object that will be used to get stats from
  /// \param monster_to_print - Monster object that will be used to get stats from
  /// \param subject_agility_boost - heroe agility received from defending
  /// \param monster_agility_boost - monster agility received from defending
  /// \param subject_agility_boost - heroe def received from defending
  /// \param monster_agility_boost - monster def received from defending
  void printFight(Heroe& subject, Monster& monster_to_print, int subject_agility_boost, int monster_agility_boost, int subject_def_boost, int monster_def_boost);
};

/** \brief Only one existing AskPlayer object, used to interact with player */
extern AskPlayer ask ;

#endif
