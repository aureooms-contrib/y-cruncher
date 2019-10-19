/* BaseFile_Windows.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 12/30/2015
 * Last Modified    : 12/30/2015
 * 
 */

#pragma once
#ifndef ymp_FileIO_BaseFile_Windows_H
#define ymp_FileIO_BaseFile_Windows_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <string>
#include "PublicLibs/Types.h"
namespace ymp{
namespace FileIO{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class BaseFile{
    std::string m_path;
    void* m_filehandle;

public:
    BaseFile(const BaseFile&) = delete;
    void operator=(const BaseFile&) = delete;
    BaseFile::BaseFile(BaseFile&& x)
        : m_path(std::move(x.m_path))
        , m_filehandle(std::move(x.m_filehandle))
    {
        x.m_path.clear();
    }
    void BaseFile::operator=(BaseFile&& x){
        m_path = std::move(x.m_path);
        m_filehandle = std::move(x.m_filehandle);
        x.m_path.clear();
    }

public:
    BaseFile() = default;
    virtual ~BaseFile(){ close(); }

    bool is_open() const{
        return !m_path.empty();
    }
    const std::string& GetPath() const{
        return m_path;
    }

public:
    bool open(std::string path);
    bool create(std::string path, ufL_t bytes = 0);
    void close(bool delete_file = false);
    void rename(std::string path);

public:
    bool set_ptr(ufL_t offset);
    void flush();
    upL_t read(void* T, upL_t bytes);
    upL_t write(const void* T, upL_t bytes);
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
#endif