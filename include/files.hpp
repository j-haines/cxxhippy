#pragma once

#include <fstream>
#include <sstream>
#include <string>

#include <fmt/core.h>

namespace cxxhippy {
namespace details {

class file_handle {
public:
    file_handle(std::string const& fp, std::string const& mode)
        : fd_{fopen(fp.c_str(), mode.c_str())} {}
    
    ~file_handle() {
        if (fd_ != nullptr) {
            fclose(fd_);
        }
    }

    FILE* fd() const { return fd_; }

protected:
    FILE* fd_;
};

}


template <typename Callable>
void with_file_contents(std::string fp, Callable fn) {
    auto handle = std::make_unique<details::file_handle>(std::move(fp), "r");
    auto fd = handle->fd();
    if (fd == nullptr) {
        exit(EXIT_FAILURE);
    }

    char* line = nullptr;
    size_t len = 0;
    std::stringstream buffer;

    fmt::print("reading line\n");
    while (getline(&line, &len, fd) != -1) {
        buffer << line;
    }

    fmt::print("calling fn\n");
    fn(buffer.str());
}

}
