#include "../incs/Data.hpp"

Data::Data() : age(18), name("Bob"), job("Driver")
{}

Data::~Data(){}

Data::Data(int age, std::string name, std::string job) : age(age), name(name), job(job)
{}

Data::Data(const Data &to_copy) : age(to_copy.age), name(to_copy.name), job(to_copy.job)
{}

Data &Data::operator=(const Data &to_copy)
{
	if (this != &to_copy)
	{
		this->age = to_copy.age;
		this->name = to_copy.name;
		this->job = to_copy.job;
	}
    return *this;
}
