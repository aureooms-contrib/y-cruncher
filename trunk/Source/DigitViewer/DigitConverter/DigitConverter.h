/* DigitConverter.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 11/09/2011
 * Last Modified    : 01/24/2016
 * 
 */

#pragma once
#ifndef ydv_DigitViewer_headers_H
#define ydv_DigitViewer_headers_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include "PublicLibs/Types.h"
#include "rawhex/rawhex.h"
#include "rawdec/rawdec.h"
#include "u32h8/u32h8.h"
#include "u32d9/u32d9.h"
#include "u64h16/u64h16.h"
#include "u64d19/u64d19.h"
namespace DigitViewer{
    using namespace ymp;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void CompileOptions_DigitConverter();
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Wrap these with overloads for template deduction. (used by y-cruncher)
inline void words_to_hex(char* T, const u32_t* A, upL_t AL){
    u32r_to_h8r(T, A, AL);
}
inline void words_to_hex(char* T, const u64_t* A, upL_t AL){
    u64r_to_h16r(T, A, AL);
}
inline void words_to_dec(char* T, const u32_t* A, upL_t AL){
    u32r_to_d9r(T, A, AL);
}
inline void words_to_dec(char* T, const u64_t* A, upL_t AL){
    u64r_to_d19r(T, A, AL);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
