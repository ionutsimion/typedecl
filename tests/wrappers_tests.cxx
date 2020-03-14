#include <typedecl.hxx>
#include <tag.hxx>
#include <wrappers_config.hxx>

#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

using is::get;

auto typedecl_tests()
{
    auto constexpr const n1 = is::typedecl_t<int64_t, AUTO_TAG>{};
    auto constexpr const n2 = is::typedecl_t<int64_t, AUTO_TAG>{ 1 };
    auto constexpr const n3 = is::typedecl_t<int64_t const, AUTO_TAG>{ 2 };
    std::cout
            << "constexpr default initialized integer: " << n1 << std::endl
            << "constexpr value initialized integer:   " << n2 << std::endl
            << "constexpr constant integer:            " << n3 << std::endl;
    auto constexpr const n4 = get(n1);
    auto n5 = n1;
    auto n6 = n3;
    std::cout
            << "default initialized integer: " << n4 << std::endl
            << "value initialized integer:   " << n5 << std::endl
            << "integer:                     " << n6 << std::endl;
    // is::typedecl_t<int64_t, AUTO_TAG> x = 1; -> cannot automatically convert from built-in types

    // auto const ca = is::typedecl_t<char *, AUTO_TAG>{}; -> does not allow raw pointers

    using doubles_vec_t = is::typedecl_t<std::vector<double>, AUTO_TAG>;
    doubles_vec_t const doubles{};
    std::cout << "doubles vector:" << (doubles.empty() ? " " : " not ") << "empty" << std::endl;

    using ints_vec_t = is::typedecl_t<std::vector<int>, AUTO_TAG>;
    ints_vec_t const ints{{1, 3, 5 } };
    std::cout << "ints vector: ";
    for (const auto &n : ints)
        std::cout << n << ' ';
    std::cout << std::endl;

    using strings_vec_t = is::typedecl_t<std::vector<std::string>, TAG(StringsVector)>;
    strings_vec_t const strings{ { "This", "is", "a", "vector", "of", "strings" } };
    std::cout << "strings vector: ";
    for (const auto &s : strings)
        std::cout << s << ' ';
    std::cout << std::endl;

    // is::typedecl_t<std::vector<std::string>, AUTO_TAG> other_strings = strings; -> cannot convert between types
    is::typedecl_t<std::vector<std::string>, TAG(StringsVector)> other_strings = strings;
    std::reverse(std::begin(other_strings), std::end(other_strings));
    std::cout << "other strings vector: ";
    for (const auto &s : other_strings)
        std::cout << s << ' ';
    std::cout << std::endl;

    using first_name_t = is::typedecl_t<std::string, TAG(FirstName)>;
    using last_name_t = is::typedecl_t<std::string, TAG(LastName)>;
    first_name_t const name{ "John" };
    last_name_t const surname{ "Smith" };
    auto f = [](first_name_t const &f, last_name_t const &l) { return l + ", " + f; };
    std::cout << name << ' ' << surname << " <=> " << f(name, surname) << std::endl;
    // std::cout << f(surname, name) -> cannot automatically convert between the two types
    // std::cout << f("First", "Last") << std::endl; -> cannot automatically convert from std::string (or similar)
    [[maybe_unused]] auto f_test = f(first_name_t{"First" }, last_name_t{"Last" });
    auto fp = [](std::string const &f, std::string const &l) { return l + ", " + f; };
    [[maybe_unused]] auto fp_test_1 = fp(name, surname );
    [[maybe_unused]] auto fp_test_2 = fp(surname, name );
}

auto property_tests()
{
}

int main(int const number_of_arguments, char *arguments[])
{
    std::cout
        << arguments[0]
        << " v" << is::wrappers::version::major
        << '.' << is::wrappers::version::minor
        << '.' << is::wrappers::version::patch
        << std::endl;

    std::cout << std::endl << "=== typedecl_t tests ===" << std::endl;
    typedecl_tests();
    std::cout << "=== done ===" << std::endl;

    std::cout << std::endl << "=== property_t tests ===" << std::endl;
    property_tests();
    std::cout << "=== done ===" << std::endl;

    return 0;
}
