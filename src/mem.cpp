#include "mem.hpp"

#include <array>
#include <memory>
#include <string>
#include <math.h>

#include "files.hpp"

using std::array;
using std::make_unique;
using std::string;
using std::unique_ptr;

namespace cxxhippy {

memory_space::memory_space() :
    buffer_{} {
}

memory_space::memory_space(buffer_t&& other) :
    buffer_{std::move(other)} {
}

memory_space::buffer_t::value_type memory_space::read_byte(word_t index) const {
    return buffer_[index];
}

memory_space::word_t memory_space::read_word(word_t index) const {
    auto msb = buffer_[index];
    auto lsb = buffer_[index+1];

    return (msb << 8) | (lsb & 0xff);
}

void memory_space::write_byte(word_t index, buffer_t::value_type value) {
    buffer_[index] = value;
}

void memory_space::write_word(word_t index, word_t value) {
    buffer_[index] = (value >> 8);
    buffer_[index+1] = (value & 0xff);
}

memory_space::unique_ptr_t read_img_file(string fp) {
    auto memspace = make_unique<memory_space>();

    with_file_contents(std::move(fp), [&memspace](auto&& contents) {
        auto max = std::min(contents.size(), memspace->capacity());
        for (auto index = 0; index < max; ++index) {
            memspace->write_byte(index, contents[index]);
        }
    });

    return memspace;
}

}
