#ifndef CTRE__ACTIONS__PROPERTIES__HPP
#define CTRE__ACTIONS__PROPERTIES__HPP

// push_property_name
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_property_name, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// push_property_name (concat)
template <auto... Str, auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_property_name, ctll::term<V>, pcre_context<ctll::list<property_name<Str...>, Ts...>, Parameters> subject) { return {}; }

// push_property_value
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_property_value, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// push_property_value (concat)
template <auto... Str, auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_property_value, ctll::term<V>, pcre_context<ctll::list<property_value<Str...>, Ts...>, Parameters> subject) { return {}; }

// make_property
template <auto V, auto... Name, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_property, ctll::term<V>, [[maybe_unused]] pcre_context<ctll::list<property_name<Name...>, Ts...>, Parameters> subject) { return {}; }

// make_property
template <auto V, auto... Value, auto... Name, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_property, ctll::term<V>, [[maybe_unused]] pcre_context<ctll::list<property_value<Value...>, property_name<Name...>, Ts...>, Parameters> subject) { return {}; }


// make_property_negative
template <auto V, auto... Name, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_property_negative, ctll::term<V>, [[maybe_unused]] pcre_context<ctll::list<property_name<Name...>, Ts...>, Parameters> subject) { return {}; }

// make_property_negative
template <auto V, auto... Value, auto... Name, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_property_negative, ctll::term<V>, [[maybe_unused]] pcre_context<ctll::list<property_value<Value...>, property_name<Name...>, Ts...>, Parameters> subject) { return {}; }

#endif
