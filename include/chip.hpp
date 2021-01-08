#pragma once

namespace cxxhippy {

class chip {
public:
  int start_pipeline();
  void stop_pipeline();

protected:
  void fetch();
  void decode();
  void execute();
};

}
