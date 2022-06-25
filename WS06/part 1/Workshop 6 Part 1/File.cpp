#include<iostream>
#include "File.h"
using namespace std;

namespace sdds{
    File::File(std::string filename, std::string contents) : m_contents(contents)
    {
       m_name = filename;
    }

    void File::update_parent_path(const string& path) {
       m_parent_path = path;
    }

    NodeType File::type() const {
       return NodeType::FILE;
    }

    string File::path() const {
       return m_parent_path + m_name;
    }

    string File::name() const {
       return m_name;
    }

    int File::count() const {
       return -1;
    }

    size_t File::size() const {
       return m_contents.length();
    }

}
