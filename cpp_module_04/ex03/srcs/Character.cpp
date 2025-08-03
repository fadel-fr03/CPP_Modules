#include "../incs/Character.hpp"

Character::Character() : name("default")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &to_copy) : name(to_copy.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (to_copy.inventory[i])
            this->inventory[i] = to_copy.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}

Character &Character::operator=(const Character &to_copy)
{
    if (this != &to_copy)
    {
        this->name = to_copy.name;
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
                delete this->inventory[i];
            if (to_copy.inventory[i])
                this->inventory[i] = to_copy.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}


const std::string &Character::getName(void) const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            break;
        }
    }
}


void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
