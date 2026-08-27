#ifndef CTRE__ACTIONS__BOUNDARIES__HPP
#define CTRE__ACTIONS__BOUNDARIES__HPP

// push_word_boundary
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_word_boundary, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

// push_not_word_boundary
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_not_word_boundary, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

#endif
