#pragma once

#include <wrapper.hxx>

namespace is
{
    template<typename WrappedType, typename UniqueTag>
    using typedecl_base_t
        = std::conditional_t<std::is_class<WrappedType>::value, WrappedType, wrapper_t<WrappedType, UniqueTag>>;

    template<typename WrappedType, typename UniqueTag>
    struct typedecl_t: public typedecl_base_t<WrappedType, UniqueTag>
    {
        using value_type = WrappedType;
        using base_type = typedecl_base_t<WrappedType, UniqueTag>;

        constexpr typedecl_t() = default;
        explicit constexpr typedecl_t(value_type value) : base_type{ std::move(value) } {}

        constexpr operator WrappedType() const noexcept // NOLINT(google-explicit-constructor,hicpp-explicit-conversions)
        {
            return get(*this);
        }
    };
}
