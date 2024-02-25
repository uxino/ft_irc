#include "User.hpp"

User::User(std::string name, std::string n_name, std::string r_name) : name(name), n_name(n_name), r_name(r_name) {}

std::string User::getName() { return (this->name); }

std::string User::getNickname() { return (this->n_name); }

std::string User::getRealName() { return (this->r_name); }

std::string User::getIp(){ return (this->ip); }

std::string User::getMessage(){ return (this->message); }

User::~User() { }