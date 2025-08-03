#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materia[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &to_copy);
		virtual ~MateriaSource();

		MateriaSource &operator=(const MateriaSource &to_copy);

		AMateria *createMateria(std::string const &type);
		void learnMateria(AMateria *);
};

#endif
