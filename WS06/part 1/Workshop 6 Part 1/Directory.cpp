#include<iostream>
#include "Directory.h"
using namespace std;

namespace sdds {
   Directory::Directory(const string& name) {
      m_name = name;
   }

   void Directory::update_parent_path(const string& path) {
      m_parent_path = path;
      for (auto i = m_contents.begin(); i != m_contents.end(); i++) {
         (*i)->update_parent_path(this->path());
      }
   }

   NodeType Directory::type() const {
      return NodeType::DIR;
   }

   string Directory::path() const {
      return m_parent_path + m_name;
   }

   string Directory::name() const {
      return m_name;
   }

   int Directory::count() const {
      return m_contents.size();
   }


   size_t Directory::size() const {
      size_t sum = 0u;
      if (!m_contents.empty()) {
         for (auto i = m_contents.begin(); i != m_contents.end(); i++) {
            sum += (*i)->size();
         }
      }
      return sum;
   }

   Directory& Directory::operator+=(Resource* R) {
      bool flag = false;
      for (auto i = m_contents.begin(); i != m_contents.end() && !flag; i++) {
         if ((*i)->name() == R->name()) {
            flag = true;
         }
      }

      if (flag) {
         throw  std::invalid_argument("Resource already exists");
      }
      else {
         R->update_parent_path(path());
         m_contents.emplace_back(R);
      }
      return *this;
   }

   Resource* Directory::find(const std::string& str, const std::vector<OpFlags>& flag) {
      Resource* r_element{};
      bool r_flag = false;
      for (auto i = flag.begin(); i != flag.end() && r_flag == false; i++) {
         if ((*i) == OpFlags::RECURSIVE) {
            r_flag = true;
         }
      }

      for (auto i = m_contents.begin(); i != m_contents.end(); i++) {
         if ((*i)->name() == str) {
            r_element = *i;
         }
         else if (r_flag && (*i)->type() == NodeType::DIR) {
            Directory* temp = dynamic_cast<Directory*>(*i);
            r_element = temp->find(str, flag);
         }
      }

      return r_element;
   }

   Directory::~Directory() {
      for (auto i = m_contents.begin(); i != m_contents.end(); i++) {
         delete* i;
      }
   }
}