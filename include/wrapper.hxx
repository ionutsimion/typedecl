#pragma once

#include <type_traits>
#include <utility>
#include "typedecl.hxx"

namespace is
{
    template<typename WrappedType, typename UniqueTag>
    struct wrapper_t;

    template<typename WrappedType, typename UniqueTag>
    auto constexpr get(wrapper_t<WrappedType, UniqueTag> const &wrapper) noexcept -> WrappedType;

    template<typename WrappedType, typename UniqueTag>
    struct wrapper_t
    {
        using value_type = WrappedType;
        static_assert(!std::is_pointer<value_type>::value, "wrapper_t does not support raw pointers!");

        constexpr wrapper_t() = default;
        explicit constexpr wrapper_t(value_type value) : _{ std::move(value) } {}

    protected:
        friend auto constexpr get<>(wrapper_t<WrappedType, UniqueTag> const &wrapper) noexcept -> WrappedType;

        value_type _{};
    };

    template<typename WrappedType, typename UniqueTag>
    auto constexpr get(wrapper_t<WrappedType, UniqueTag> const &wrapper) noexcept -> WrappedType
    {
        return wrapper._;
    }
}
