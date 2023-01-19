#include "Player.h"

#include "Person.h"

// Constructor
Player::Player() {
    std::cout << "Default coustructor of Player called...:" << std::endl;
}
Player::Player(const std::string_view& game)
    : _m_game(game) {
}
Player::Player(std::string first, std::string second, const std::string_view& game)
    : _m_game(game) {
    // // Aproach for private variables
    // this->setFirstName(first);
    // this->setLastName(second);

    // Aproach for protected variables
    _first_name = first;
    _last_name = second;
}
Player::~Player() {
}

// Function
void Player::Play() {
    _full_name = "John Snow";
    _age = 55;
    setAddress("White wall");
};

// Friend
std::ostream& operator<<(std::ostream& out, const Player& person) {
    out << "Player [ Full name: " << person.getFullName() << " "
        << ", Age: " << person.getAge() << " "
        << ", Adress: " << person.getAdress() << "]";
    return out;
}
