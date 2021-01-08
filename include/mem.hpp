#pragma once

#include <array>
#include <memory>
#include <string>

namespace cxxhippy {

auto constexpr kMaxMemoryBytes = 4096;

class memory_space {
public:
    using buffer_t = std::array<char, kMaxMemoryBytes>;
    using shared_ptr_t = std::shared_ptr<memory_space>;
    using unique_ptr_t = std::unique_ptr<memory_space>;
    using weak_ptr_t = std::weak_ptr<memory_space>;
    using word_t = uint16_t;

    memory_space();
    memory_space(buffer_t&&);

    buffer_t::size_type capacity() const {
        return buffer_.max_size();
    }

    buffer_t::value_type read_byte(word_t) const;
    word_t read_word(word_t) const;

    void write_byte(word_t, buffer_t::value_type);
    void write_word(word_t, word_t);

private:
    buffer_t buffer_;
};

memory_space::unique_ptr_t read_img_file(std::string);

}
