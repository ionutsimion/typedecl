#pragma once

#include <wrapper.hxx>

namespace is
{
    template<typename WrappedType, typename UniqueTag>
    struct property_t;

    template<typename WrappedType, typename UniqueTag>
    auto set(property_t<WrappedType, UniqueTag> &, WrappedType) noexcept;

    template<typename WrappedType, typename UniqueTag>
    struct property_t: wrapper_t<WrappedType, UniqueTag>
    {
        using value_type = WrappedType;

        constexpr property_t() = default;
        explicit constexpr property_t(value_type value) : wrapper_t<WrappedType, UniqueTag>{ std::move(value) } {}

        auto constexpr get() const noexcept
        {
            return is::get(*this);
        }

        auto set(value_type value) noexcept -> void
        {
            is::set(*this, value);
        }

    protected:
        friend auto constexpr is::set<>(property_t<WrappedType, UniqueTag> &, WrappedType) noexcept;
    };

    template<typename WrappedType, typename UniqueTag>
    auto set(property_t<WrappedType, UniqueTag> &property, WrappedType value) noexcept
    {
        property._ = std::move(value);
    }
}
