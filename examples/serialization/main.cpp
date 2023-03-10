#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class MyClass : public ntl::Serializable
{
public:
    int a, b;

public:
    ntl::Serialization serialize() override
    {
        return ntl::Serialization(ntl::StringUtils::to_string(a, ",", b));
    }

    ntl::Serialization serialize() const override
    {
        return ntl::Serialization(ntl::StringUtils::to_string(a, ",", b));
    }

    MyClass &deserialize(const ntl::Serialization &serialization) override
    {
        std::vector<ntl::String> result = ntl::StringUtils::split(serialization.get_serialization(), ",");
        a = std::stoi(result.at(0));
        b = std::stoi(result.at(1));
        return *this;
    }
};

int main()
{
    try
    {
        std::cout << "ntl::Deserializer::deserialize<int>(ntl::Serialization(\"123\")):" << ntl::Deserializer::deserialize<int>(ntl::Serialization("123")) << std::endl
                  << "ntl::Deserializer::deserialize<double>(ntl::Serialization(\"12.3d\")):" << ntl::Deserializer::deserialize<double>(ntl::Serialization("12.3d")) << std::endl;

        std::cout << std::endl;

        MyClass cls;
        cls.a = 123;
        cls.b = 456;
        ntl::Serialization ser = cls.serialize();
        std::cout << "ser.get_serialization():" << ser.get_serialization() << std::endl;
        MyClass cls2 = ntl::Deserializer::deserialize<MyClass>(ser);
        std::cout << "a:" << cls2.a << ",b:" << cls2.b << std::endl;

        std::cout << std::endl;

        ntl::Exception exception("what", "why", "where");
        std::cout << "exception:" << std::endl
                  << exception << std::endl;
        std::cout << "exception.serialize().get_serialization():" << std::endl
                  << exception.serialize().get_serialization() << std::endl;
        ntl::Exception exception2 = ntl::Deserializer::deserialize<ntl::Exception>(exception.serialize());
        std::cout << "exception2:" << std::endl
                  << exception2 << std::endl;

        std::cout << std::endl;

        ntl::Serialization ser1 = ntl::Serializer::serialize("\"abc\"");
        ntl::String result = ntl::Deserializer::deserialize<ntl::String>(ser1);
        std::cout << "result:" << result << std::endl;

        std::cout << std::endl;

        std::array<int, 1> arr = {147};
        std::initializer_list<int> lst = {951, 623};
        std::vector<int> vec = {123, 456, 789};

        ntl::Serialization ser2 = ntl::Serializer::serialize(arr);
        ntl::Serialization ser3 = ntl::Serializer::serialize(lst);
        ntl::Serialization ser4 = ntl::Serializer::serialize(vec);

        std::cout << "ser2.get_serialization():" << ser2.get_serialization() << std::endl;
        std::cout << "ser3.get_serialization():" << ser3.get_serialization() << std::endl;
        std::cout << "ser4.get_serialization():" << ser4.get_serialization() << std::endl;

        std::vector<int> vec2;
        std::vector<int> vec3;
        std::vector<int> vec4;

        ntl::Deserializer::deserialize(ser2, vec2);
        ntl::Deserializer::deserialize(ser3, vec3);
        ntl::Deserializer::deserialize(ser4, vec4);

        std::cout << "vec2:" << std::endl;
        ntl::PrintUtils::print_array(std::cout, vec2.cbegin(), vec2.cend());
        std::cout << std::endl;
        std::cout << "vec3:" << std::endl;
        ntl::PrintUtils::print_array(std::cout, vec3.cbegin(), vec3.cend());
        std::cout << std::endl;
        std::cout << "vec4:" << std::endl;
        ntl::PrintUtils::print_array(std::cout, vec4.cbegin(), vec4.cend());
        std::cout << std::endl;
    }
    catch (const ntl::Exception &exception)
    {
        std::cout << exception << std::endl;
    }

    return 0;
}