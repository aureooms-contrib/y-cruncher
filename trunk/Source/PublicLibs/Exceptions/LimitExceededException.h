/* LimitExceededException.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 04/09/2017
 * Last Modified    : 04/09/2017
 * 
 */

#pragma once
#ifndef ymp_Exceptions_LimitExceededException_H
#define ymp_Exceptions_LimitExceededException_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <string>
#include "PublicLibs/CompilerSettings.h"
#include "PublicLibs/Types.h"
#include "Exception.h"
namespace ymp{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class LimitExceededException : public Exception{
public:
    static const char TYPENAME[];

    YM_NO_INLINE LimitExceededException(uiL_t attempted);
    YM_NO_INLINE LimitExceededException(const char* function, uiL_t limit, uiL_t attempted);

public:
    [[noreturn]] virtual void fire() const override{
        throw *this;
    }
    virtual const char* get_typename() const override{
        return TYPENAME;
    }
    virtual Exception* clone() const override{
        return new LimitExceededException(*this);
    }
    virtual void print() const override;

public:
    LimitExceededException(const DllSafeStream& data);
    virtual DllSafeStream serialize() const override;

private:
    std::string m_function;
    uiL_t m_limit;
    uiL_t m_attempted;
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
