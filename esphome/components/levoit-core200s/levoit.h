#pragma once

#include "esphome/core/component.h"
#include "esphome/core/defines.h"
#include "esphome/core/helpers.h"

namespace esphome {
namespace levoit {

class Levoit : public Component {
 public:
  float get_setup_priority() const override { return setup_priority::LATE; }
  void setup() override;
  

 protected:
  uint32_t current_state_ = 0;
};

}  // namespace levoit
}  // namespace esphome