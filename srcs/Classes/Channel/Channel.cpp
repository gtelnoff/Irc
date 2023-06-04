#include "Channel.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Channel::Channel() {}

Channel::Channel(const Channel& src)
{
	*this = src;
}

Channel::Channel(const std::string& name): _name(name), _limit(-1), _isKeyProtected(false), _isTopicProtected(false), _isInviteOnly(false) {}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Channel::~Channel()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Channel& Channel::operator=(Channel const& rhs)
{
	if (this != &rhs)
	{
		std::set<std::string> usersCopy(rhs.getUsers());
		std::set<std::string> operatorsCopy(rhs.getOperators());
		this->_name = rhs._name;
		this->_users = usersCopy;
		this->_operators = operatorsCopy;
		this->_isKeyProtected = rhs._isKeyProtected;
		this->_isTopicProtected = rhs._isTopicProtected;
		this->_isInviteOnly = rhs._isInviteOnly;
		this->_key = rhs._key;
		this->_topic = rhs._topic;
		this->_limit = rhs._limit;
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

////// REGULAR USERS FUNCTIONS ///////

const std::string& Channel::getName() const {
	return _name;
}

void Channel::join(const std::string& user) {
	_users.insert(user);
}

void Channel::leave(const std::string& user, const bool isOperator) {
	_users.erase(user);
	if (isOperator)
		_operators.erase(user);
}

bool Channel::hasUser(const std::string& user) const {
	return _users.find(user) != _users.end();
}

const std::set<std::string>& Channel::getUsers() const {
	return _users;
}

/////// OPERATORS ///////

void Channel::setOperator(const std::string& user) {
	_operators.insert(user);
}

void Channel::unsetOperator(const std::string& user) {
	_operators.erase(user);
}

bool Channel::isOperator(const std::string& user) const {
	return _operators.find(user) != _operators.end();
}

size_t Channel::operatorCount() const {
	return _operators.size();
}

const std::set<std::string>& Channel::getOperators() const {
	return _operators;
}

/////// KEY ///////

void Channel::setKey(const std::string& key) {
	_key = key;
	_isKeyProtected = true;
}

void Channel::unsetKey() {
	_isKeyProtected = false;
}

bool Channel::isKeyProtected() const {
	return _isKeyProtected;
}

std::string Channel::getKey() const {
	return _key;
}


/// LIMIT /////
void Channel::setLimit(int limit) {
	_limit = limit;
}

int Channel::getLimit() const {
	return _limit;
}

void Channel::unsetLimit() {
	_limit = -1;
}

/////// TOPIC ///////

void Channel::setTopic(const std::string& topic) {
	_topic = topic;
}

const std::string& Channel::getTopic() const {
	return _topic;
}

void Channel::setTopicProtection() {
	_isTopicProtected = true;
}

bool Channel::isTopicProtected() const {
	return _isTopicProtected;
}

void Channel::unsetTopicProtection() {
	_isTopicProtected = false;
}

////// INVITE //////

void Channel::invite(const std::string& user) {
	_invitedUsers.insert(user);
}

void Channel::setInviteOnly() {
	_isInviteOnly = true;
}

bool Channel::isInviteOnly() const {
	return _isInviteOnly;
}

void Channel::unsetInviteOnly() {
	_isInviteOnly = false;
}

bool Channel::isInvited(const std::string& user) const {
	return _invitedUsers.find(user) != _invitedUsers.end();
}

void Channel::uninvite(const std::string& user) {
	_invitedUsers.erase(user);
}

////// KICK USERS //////

void Channel::clearUsers()
{
	_users.clear();
}

void Channel::kickUser(const std::string& user) {
	_users.erase(user);
}


/* ************************************************************************** */