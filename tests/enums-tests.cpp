#include <iostream>

#include <accel/enums>

using namespace accel;

enum class test_enum
{
    value1,
    value2,
    value3
};

int main()
{
    ACC_ASSERT(enums::get_size<test_enum>() == 3);
    
    ACC_ASSERT(enums::get_name(test_enum::value1) == "value1");
    ACC_ASSERT(enums::get_name(test_enum::value2) == "value2");
    ACC_ASSERT(enums::get_name(test_enum::value3) == "value3");
    ACC_ASSERT_EXCEPTION(enums::get_name((test_enum)3), std::runtime_error);

    test_enum test = test_enum::value1;
    ACC_ASSERT(enums::get_name(test) == "value1");
    test = test_enum::value2;
    ACC_ASSERT(enums::get_name(test) == "value2");

    ACC_ASSERT(enums::get_value<test_enum>("value1") == test_enum::value1);
    ACC_ASSERT(enums::get_value<test_enum>("value2") == test_enum::value2);
    ACC_ASSERT(enums::get_value<test_enum>("value3") == test_enum::value3);
    ACC_ASSERT_EXCEPTION(enums::get_value<test_enum>("value4"), std::runtime_error);

    std::cout << "All tests ran successfully.\n";

    return 0;
}