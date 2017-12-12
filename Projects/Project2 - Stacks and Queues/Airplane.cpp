//Kyle Curry - CS250

#include "Airplane.hpp"

//! Move traveller onto airplane
/**
    For the traveller passed in, push it into the airplane's stack.

    @param <Traveller*> traveller
    @return <void>
*/
void Airplane::Board(Traveller* traveller)
{
	m_passengers.Push(traveller);
}

//! Pull traveller off airplane
/**
    Get the next (top-most) traveller from the airplane stack,
    remove them from the stack and return the traveller.

    @return <Traveller*>
*/
Traveller* Airplane::Disembark()
{
	Traveller* top = m_passengers.Top();
	m_passengers.Pop();
	return top;
}

//! Return whether the airplane is empty (no passengers)
/**
    If the size of the stack is 0, then the airplane is empty.

    @return <bool>
*/
bool Airplane::IsEmpty()
{
	if (m_passengers.Size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

