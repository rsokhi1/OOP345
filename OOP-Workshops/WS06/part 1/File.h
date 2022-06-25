#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds{
    class File : public Resource{
        // std::string m_filename{};
        std::string m_contents{};
    public:
        File(std::string& filename, std::string& contents);
        void update_parent_path(const std::string& path);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
    };
}


#endif // !SDDS_FILE_H_