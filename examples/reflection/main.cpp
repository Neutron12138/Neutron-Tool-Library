#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"
#include "MyClass.hpp"

__attribute__((constructor)) void prepare()
{
    ntl::reflector.register_class<MyClass>("MyClass");
}

void f(int) {}

int main()
{
    try
    {
        /*{
            ntl::StaticMethod m(&f,
                                1,
                                ntl::MethodSign(
                                    ntl::get_type<void>(),
                                    std::vector<ntl::Type>{
                                        ntl::get_type<int>()}));
            m.call<void>("123");
        }*/

        {
            ntl::NonStaticMethod method(&MyClass::func, 1);
            ntl::NonStaticField field(&MyClass::var);
            ntl::StaticMethod method2(&MyClass::func2, 1);
            ntl::StaticField field2(&MyClass::var2);

            MyClass object;
            field.of<int>(&object) = 666;
            method.call<void>(&object, 999);
            field2.of<int>() = 123;
            method2.call<void>(456);
        }

        std::cout << "----------" << std::endl;

        {
            ntl::BasicObject *object2 = ntl::reflector.get_class("MyClass")->get_static_methods().at(ntl::Details::construction_name).call<ntl::BasicObject *>();
            ntl::reflector.get_class("MyClass")->get_nonstatic_fields().at("var").of<int>(object2) = 1;
            ntl::reflector.get_class("MyClass")->get_nonstatic_methods().at("func(int)").call<void>(object2, 10);
            ntl::reflector.get_class("MyClass")->get_static_fields().at("var2").of<int>() = 100;
            ntl::reflector.get_class("MyClass")->get_static_methods().at("func2(int)").call<void>(1000);
            ntl::reflector.get_class("MyClass")->get_static_methods().at(ntl::Details::destruction_name).call<void>(object2);
        }
    }
    catch (const ntl::Exception &exception)
    {
        std::cout << exception << std::endl;
    }

    return 0;
}