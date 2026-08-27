#ifndef CTRE__ACTIONS__FUSION__HPP
#define CTRE__ACTIONS__FUSION__HPP

static constexpr size_t combine_max_repeat_length(size_t A, size_t B) { return {}; }

template <size_t MinA, size_t MaxA, size_t MinB, size_t MaxB, typename... Content> static constexpr auto combine_repeat(repeat<MinA, MaxA, Content...>, repeat<MinB, MaxB, Content...>) { return {}; }

template <size_t MinA, size_t MaxA, size_t MinB, size_t MaxB, typename... Content> static constexpr auto combine_repeat(lazy_repeat<MinA, MaxA, Content...>, lazy_repeat<MinB, MaxB, Content...>) { return {}; }

template <size_t MinA, size_t MaxA, size_t MinB, size_t MaxB, typename... Content> static constexpr auto combine_repeat(possessive_repeat<MinA, MaxA, Content...>, possessive_repeat<MinB, MaxB, Content...>) { return {}; }

// concat repeat sequences
template <auto V, size_t MinA, size_t MaxA, size_t MinB, size_t MaxB, typename... Content, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_sequence, ctll::term<V>, pcre_context<ctll::list<repeat<MinB, MaxB, Content...>, repeat<MinA, MaxA, Content...>, Ts...>, Parameters> subject) { return {}; }

// concat lazy repeat sequences
template <auto V, size_t MinA, size_t MaxA, size_t MinB, size_t MaxB, typename... Content, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_sequence, ctll::term<V>, pcre_context<ctll::list<lazy_repeat<MinB, MaxB, Content...>, lazy_repeat<MinA, MaxA, Content...>, Ts...>, Parameters> subject) { return {}; }

// concat possessive repeat seqeunces
template <auto V, size_t MinA, size_t MaxA, size_t MinB, size_t MaxB, typename... Content, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_sequence, ctll::term<V>, pcre_context<ctll::list<possessive_repeat<MinB, MaxB, Content...>, possessive_repeat<MinA, MaxA, Content...>, Ts...>, Parameters> subject) { return {}; }

// concat repeat sequences into sequence
template <auto V, size_t MinA, size_t MaxA, size_t MinB, size_t MaxB, typename... Content, typename... As, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_sequence, ctll::term<V>, pcre_context<ctll::list<sequence<repeat<MinB, MaxB, Content...>, As...>,repeat<MinA, MaxA, Content...>,Ts...>, Parameters> subject) { return {}; }

// concat lazy repeat sequences into sequence
template <auto V, size_t MinA, size_t MaxA, size_t MinB, size_t MaxB, typename... Content, typename... As, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_sequence, ctll::term<V>, pcre_context<ctll::list<sequence<lazy_repeat<MinB, MaxB, Content...>, As...>,lazy_repeat<MinA, MaxA, Content...>,Ts...>, Parameters> subject) { return {}; }

// concat possessive repeat sequences into sequence
template <auto V, size_t MinA, size_t MaxA, size_t MinB, size_t MaxB, typename... Content, typename... As, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_sequence, ctll::term<V>, pcre_context<ctll::list<sequence<possessive_repeat<MinB, MaxB, Content...>, As...>,possessive_repeat<MinA, MaxA, Content...>,Ts...>, Parameters> subject) { return {}; }

#endif
