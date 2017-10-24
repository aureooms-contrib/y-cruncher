/* WordTraits.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 11/20/2014
 * Last Modified    : 04/08/2017
 * 
 */

#pragma once
#ifndef ymp_TemplateTools_WordTraits_H
#define ymp_TemplateTools_WordTraits_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <limits.h>
#include <cstddef>
#include <type_traits>
namespace ymp{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#define YMP_ASSERT_VALID_WORD(wtype) static_assert(WordTraits<wtype>::is_valid, "wtype must be an unsigned 32 or 64-bit integer");
////////////////////////////////////////////////////////////////////////////////
template <typename wtype>
struct WordTraits{
    static const size_t BITS = CHAR_BIT * sizeof(wtype);
    static const size_t MAG  = BITS == 32 ? 5 : 6;
    static const bool is_valid =
        std::is_integral<wtype>::value &&
        std::is_unsigned<wtype>::value &&
        (BITS == 32 || BITS == 64);
    YMP_ASSERT_VALID_WORD(wtype);
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
