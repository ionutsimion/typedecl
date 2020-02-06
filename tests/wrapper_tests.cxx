#include <wrapper.hxx>
#include <wrappers_config.hxx>

#include <iostream>

int main(int const number_of_arguments, char *arguments[])
{
    std::cout
        << arguments[0]
        << " Version " << is::wrappers::version::major
        << '.' << is::wrappers::version::minor
        << '.' << is::wrappers::version::patch
        << std::endl;

    return 0;
}
