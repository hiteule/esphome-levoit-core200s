#pragma once

#include "esphome/core/component.h"
#include "esphome/components/levoit-core200s/levoit.h"
#include "esphome/components/fan/fan.h"
#include "esphome/core/hal.h"

namespace esphome {
namespace levoit {

class LevoitFan : public Component, public fan::Fan {
 public:
  LevoitFan(Levoit *parent) : parent_(parent) {}
  void setup() override;
  void dump_config() override;

  fan::FanTraits get_traits() override;

  void set_pin_night(GPIOPin *pin_night) { pin_night_ = pin_night; }
  void set_pin_low(GPIOPin *pin_low) { pin_low_ = pin_low; }
  void set_pin_medium(GPIOPin *pin_medium) { pin_medium_ = pin_medium; }
  void set_pin_high(GPIOPin *pin_high) { pin_high_ = pin_high; }
  void set_pin_led_night(GPIOPin *pin_led_night) { pin_led_night_ = pin_led_night; }
  void set_pin_led_low(GPIOPin *pin_led_low) { pin_led_low_ = pin_led_low; }
  void set_pin_led_medium(GPIOPin *pin_led_medium) { pin_led_medium_ = pin_led_medium; }
  void set_pin_led_high(GPIOPin *pin_led_high) { pin_led_high_ = pin_led_high; }

 protected:
  void control(const fan::FanCall &call) override;
  Levoit *parent_;
  GPIOPin *pin_night_;
  GPIOPin *pin_low_;
  GPIOPin *pin_medium_;
  GPIOPin *pin_high_;
  GPIOPin *pin_led_night_;
  GPIOPin *pin_led_low_;
  GPIOPin *pin_led_medium_;
  GPIOPin *pin_led_high_;

 private:
  void setFanOff();
};

}  // namespace levoit
}  // namespace esphome
