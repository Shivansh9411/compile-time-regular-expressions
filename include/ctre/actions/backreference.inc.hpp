#ifndef CTRE__ACTIONS__BACKREFERENCE__HPP
#define CTRE__ACTIONS__BACKREFERENCE__HPP

// backreference with name
template <auto... Str, auto V, typename... Ts, size_t Counter> static constexpr auto apply(pcre::make_back_reference, ctll::term<V>, pcre_context<ctll::list<id<Str...>, Ts...>, pcre_parameters<Counter>>) { return {}; }

// with just a number
template <auto V, size_t Id, typename... Ts, size_t Counter> static constexpr auto apply(pcre::make_back_reference, ctll::term<V>, pcre_context<ctll::list<number<Id>, Ts...>, pcre_parameters<Counter>>) { return {}; }

// relative backreference
template <auto V, size_t Id, typename... Ts, size_t Counter> static constexpr auto apply(pcre::make_relative_back_reference, ctll::term<V>, [[maybe_unused]] pcre_context<ctll::list<number<Id>, Ts...>, pcre_parameters<Counter>>) { return {}; }

#endif
