#ifndef CTRE_V2__CTRE__FLAGS_AND_MODES__HPP
#define CTRE_V2__CTRE__FLAGS_AND_MODES__HPP

namespace ctre {

struct singleline { };
struct multiline { };

struct case_sensitive { };
struct case_insensitive { };

using ci = case_insensitive;
using cs = case_sensitive;

template <typename... Flags> struct flag_list { };

struct flags {
	bool block_empty_match = false;
	bool multiline = false;
	bool case_insensitive = false;
	
	constexpr flags() = default;
	constexpr flags(const flags &) = default;
	constexpr flags(flags &&) = default;
	
	constexpr CTRE_FORCE_INLINE flags(ctre::singleline v) noexcept { return {}; }
	constexpr CTRE_FORCE_INLINE flags(ctre::multiline v) noexcept { return {}; }
	constexpr CTRE_FORCE_INLINE flags(ctre::case_sensitive v) noexcept { return {}; }
	constexpr CTRE_FORCE_INLINE flags(ctre::case_insensitive v) noexcept { return {}; }
	
	
	template <typename... Args> constexpr CTRE_FORCE_INLINE flags(ctll::list<Args...>) noexcept { return {}; }
	
	constexpr friend CTRE_FORCE_INLINE auto operator+(flags f, pcre::mode_case_insensitive) noexcept { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr friend CTRE_FORCE_INLINE auto operator+(flags f, pcre::mode_case_sensitive) noexcept { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr friend CTRE_FORCE_INLINE auto operator+(flags f, pcre::mode_singleline) noexcept { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr friend CTRE_FORCE_INLINE auto operator+(flags f, pcre::mode_multiline) noexcept { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr CTRE_FORCE_INLINE void set_flag(ctre::singleline) noexcept { }
	
	constexpr CTRE_FORCE_INLINE void set_flag(ctre::multiline) noexcept { }
	
	constexpr CTRE_FORCE_INLINE void set_flag(ctre::case_insensitive) noexcept { }
	
	constexpr CTRE_FORCE_INLINE void set_flag(ctre::case_sensitive) noexcept { }
};

constexpr CTRE_FORCE_INLINE auto not_empty_match(flags f) { return {}; }

constexpr CTRE_FORCE_INLINE auto consumed_something(flags f, bool condition = true) { return {}; }

constexpr CTRE_FORCE_INLINE bool cannot_be_empty_match(flags f) { return {}; }

constexpr CTRE_FORCE_INLINE bool multiline_mode(flags f) { return {}; }

constexpr CTRE_FORCE_INLINE bool is_case_insensitive(flags f) { return {}; }

} // namespace ctre

#endif