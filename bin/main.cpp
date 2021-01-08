#include <array>
#include <memory>

#include <fmt/core.h>

#include "disassembler.hpp"
#include "mem.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        fmt::print("usage: {} <imgfile>\n", argv[0]);
        return 1;
    }

    auto memspace = std::shared_ptr<cxxhippy::memory_space>(cxxhippy::read_img_file(argv[0]));
    auto disassembler = std::make_unique<cxxhippy::disassembler>();
    disassembler->load(memspace);
    disassembler->disassemble();

    return 0;
}
