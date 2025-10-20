#include "Serializer.hpp"

int main(void){
    
    // Test 1: Basic functionality
    std::cout << "\n=== Test 1: Basic ===" << std::endl;
    Data a;
    a.hello = "First test";
    uintptr_t rawA = Serializer::serialize(&a);
    Data* ptrA = Serializer::deserialize(rawA);
    std::cout << "Original: " << a.hello << " | After deserialize: " << ptrA->hello << std::endl;

    // Test 2: Multiple objects
    std::cout << "\n=== Test 2: Multiple objects ===" << std::endl;
    Data b, c;
    b.hello = "Hello from b";
    c.hello = "Hello from c";
    uintptr_t rawB = Serializer::serialize(&b);
    uintptr_t rawC = Serializer::serialize(&c);
    Data* ptrB = Serializer::deserialize(rawB);
    Data* ptrC = Serializer::deserialize(rawC);
    std::cout << "B says: " << ptrB->hello << std::endl;
    std::cout << "C says: " << ptrC->hello << std::endl;


    // Test 3: Pointer identity
    std::cout << "\n=== Test 3: Pointer identity (same address?) ===" << std::endl;
    std::cout << "Address of a: " << &a << " | Deserialized: " << ptrA << std::endl;


    // Test 4: Modify after deserialize
    std::cout << "\n=== Test 4: Modify through deserialized pointer ===" << std::endl;
    ptrA->hello = "Changed via ptr";
    std::cout << "Original a.hello now: " << a.hello << std::endl;


    // Test 5: Null safety
    std::cout << "\n=== Test 5: Null pointer ===" << std::endl;
    Data* nullData = nullptr;
    uintptr_t rawNull = Serializer::serialize(nullData);
    Data* ptrNull = Serializer::deserialize(rawNull);
    std::cout << "Null serialize -> " << rawNull << " | Deserialize -> " << ptrNull << std::endl;

    return 0;
}