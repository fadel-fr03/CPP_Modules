#include "../incs/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &to_copy)
{
    for (int i = 0; i < 4; i++)
    {
        if (to_copy.materia[i])
            this->materia[i] = to_copy.materia[i]->clone();
        else
            this->materia[i] = NULL;
    }
}


MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->materia[i])
			delete this->materia[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &to_copy)
{
    if (this != &to_copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->materia[i])
                delete this->materia[i];
            if (to_copy.materia[i])
                this->materia[i] = to_copy.materia[i]->clone();
            else
                this->materia[i] = NULL;
        }
    }
    return *this;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();
	return NULL;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!materia[i])
        {
            materia[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
}
