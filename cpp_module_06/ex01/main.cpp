#include "incs/Data.hpp"
#include "incs/Serializer.hpp"

int main()
{
    // Create a Data object with some values
    Data originalData(25, "Alice", "Engineer");

    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Address: " << &originalData << std::endl;
    std::cout << "Age: " << originalData.age << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << "Job: " << originalData.job << std::endl;

    // Serialize the pointer to the Data object
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "\n=== Serialization ===" << std::endl;
    std::cout << "Serialized value: " << serialized << std::endl;

    // Deserialize back to a Data pointer
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "\n=== Deserialization ===" << std::endl;
    std::cout << "Deserialized address: " << deserialized << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Job: " << deserialized->job << std::endl;

    // Test if the pointers are equal
    std::cout << "\n=== Verification ===" << std::endl;
    std::cout << "Original pointer == Deserialized pointer: " 
              << ((&originalData == deserialized) ? "TRUE" : "FALSE") << std::endl;

    // Additional test with default constructor
    std::cout << "\n=== Test with Default Constructor ===" << std::endl;
    Data defaultData;
    std::cout << "Default data - Age: " << defaultData.age 
              << ", Name: " << defaultData.name 
              << ", Job: " << defaultData.job << std::endl;

    uintptr_t serialized2 = Serializer::serialize(&defaultData);
    Data* deserialized2 = Serializer::deserialize(serialized2);

    std::cout << "Pointer equality test: " 
              << ((&defaultData == deserialized2) ? "PASS" : "FAIL") << std::endl;

    return 0;
}
