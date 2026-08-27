#ifndef CTRE__ACTIONS__CHARACTERS__HPP
#define CTRE__ACTIONS__CHARACTERS__HPP

// push character
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_character, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// push_any_character
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_character_anything, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// character_alarm
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_character_alarm, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// character_escape
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_character_escape, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// character_formfeed
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_character_formfeed, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// push_character_newline
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_character_newline, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// push_character_null
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_character_null, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// push_character_return_carriage
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_character_return_carriage, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// push_character_tab
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_character_tab, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

#endif
