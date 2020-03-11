#include <typedecl.hxx>
#include <tag.hxx>
#include <wrappers_config.hxx>

#include <iostream>

using is::get;

int main(int const number_of_arguments, char *arguments[])
{
    std::cout
        << arguments[0]
        << " v" << is::wrappers::version::major
        << '.' << is::wrappers::version::minor
        << '.' << is::wrappers::version::patch
        << std::endl;

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

    // auto const ca = is::typedecl_t<char *, AUTO_TAG>{};

    return 0;
}
