#include "ft_irc.hpp"

void trimInput(std::string &s)
{
    s.erase(s.find('\n'));
}
