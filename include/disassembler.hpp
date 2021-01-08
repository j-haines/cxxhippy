#pragma once

#include "mem.hpp"

namespace cxxhippy {

class disassembler {
public:
    void disassemble() const;
    void load(memory_space::shared_ptr_t);

protected:
    memory_space::weak_ptr_t membuffer_;

    void disassemble_word(memory_space::word_t) const;
    void disassemble_locked(memory_space::shared_ptr_t&&) const;
};

}
