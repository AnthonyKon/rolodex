//
// COMP2711,8801 Computer Programming 2
// Flinders University
//

#include "Rolodex.h"


Rolodex::Rolodex()
{
    _sen = new RolodexItem;
    _sen -> prev = _sen;
    _sen -> next = _sen;
    _current = _sen;
}

/**
 * Returns true if the Rolodex is positioned before the first card.
 */
bool Rolodex::isBeforeFirst() const
{
    return (_sen == _current);
}

/**
 * Returns true if the Rolodex is positioned after the last card.
 */
bool Rolodex::isAfterLast() const
{
    return (_sen == _current);
}

/**
 * Rotates the Rolodex one card forwards.
 */
void Rolodex::rotateForward()
{
    _current = _current->next;
}

/**
 * Rotates the Rolodex one card backwards.
 */
void Rolodex::rotateBackward()
{
    _current = _current->prev;
}

/**
 * Returns the value of the current card.
 */
const std::string& Rolodex::currentValue() const
{
    return _current->value;
}

/**
 * Inserts a new card after the current card and positions the Rolodex
 * at the newly inserted card.
 *
 * @param value The value to insert into a new card.
 */
void Rolodex::insertAfterCurrent(const std::string& value)
{
    RolodexItem* in = new RolodexItem;

    in -> value = value;
    in -> next = _current -> next;
    in -> prev = _current;

    _current -> next -> prev = in;
    _current -> next = in;
    _current = in;
}

/**
 * Inserts a new card before the current card and positions the Rolodex
 * at the newly inserted card.
 *
 * @param value The value to insert into a new card.
 */
void Rolodex::insertBeforeCurrent(const std::string& value)
{
    RolodexItem *out = new RolodexItem;

    out -> value = value;
    out -> next = _current;
    out -> prev = _current -> prev;

    _current -> prev -> next = out;
    _current -> prev = out;
    _current = out;
}
