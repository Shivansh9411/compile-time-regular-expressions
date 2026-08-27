#ifndef CTRE__ACTIONS__HEXDEC__HPP
#define CTRE__ACTIONS__HEXDEC__HPP

// hexdec character support (seed)
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::create_hexdec, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// hexdec character support (push value)
template <auto V, size_t N, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_hexdec, ctll::term<V>, pcre_context<ctll::list<number<N>, Ts...>, Parameters> subject) { return {}; }
// hexdec character support (convert to character)
template <auto V, size_t N, typename... Ts, typename Parameters> static constexpr auto apply(pcre::finish_hexdec, ctll::term<V>, pcre_context<ctll::list<number<N>, Ts...>, Parameters> subject) { return {}; }	

#endif
