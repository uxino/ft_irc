#include "Libraries.hpp"

User::User() {}

std::string User::getName() { return (this->name); }

std::string User::getNickname() { return (this->n_name); }

std::string User::getMessage(){ return (this->message); }

std::string User::getPass(){ return (this->pass); }

std::string User::getIp() { return (this->ip); }

int User::getSocket(){ return (this->socket); }

void User::setName(std::string str) { this->name = str; }

void User::setNickname(std::string str) { this->n_name = str; }

void User::setSocket(int socket) { this->socket = socket; }

void User::setMessage(std::string str) { this->message = str; }

void User::setPass(std::string str) { this->pass = str; }

void User::setIp(std::string str) { this->ip = str; }

User::~User() { }