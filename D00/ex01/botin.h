#ifndef BOTIN_H
# define BOTIN_H

# include "Contact.class.hpp"

typedef struct  s_botin {
    std::string     str;
    std::string     (Contact::*f)(void) const;
}               t_botin;

#endif