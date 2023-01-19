#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <string_view>

#include "Person.h"

class Player : public Person {
   private:
    std::string _m_game{"None"};
    int _career_start_year{0};
    double _salary{0.0};
    int _health_factor{0};  // Let's say that is 0~10

   private:
    friend std::ostream& operator<<(std::ostream& out, const Player& person);

   public:
    void Play();
    // Constructor
    Player();
    Player(const std::string_view& game);
    Player(std::string first, std::string second, const std::string_view& game);
    ~Player();
};

#endif