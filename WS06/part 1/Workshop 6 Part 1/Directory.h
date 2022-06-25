#ifndef SDDS_DIRECTORY_H_
#define SDDS_DIRECTORY_H_
#include <vector>
#include "Resource.h"
#include "Flags.h"
namespace sdds {
   class Directory : public Resource
   {
      std::vector<Resource*> m_contents{};
   public:
      Directory(const std::string& name);
      void update_parent_path(const std::string& path);
      NodeType type() const;
      std::string path() const;
      std::string name() const;
      int count() const;
      size_t size() const;
      Directory& operator+=(Resource* R);
      Resource* find(const std::string& str, const std::vector<OpFlags>& flag = {});
      ~Directory();
      Directory& operator=(const Directory& D) = delete;
      Directory& operator=(Directory&& D) = delete;
   };
}

#endif // !SDDS_DIRECTORY_H_