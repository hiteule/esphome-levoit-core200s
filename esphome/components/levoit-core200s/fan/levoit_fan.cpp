#include "esphome/core/log.h"
#include "levoit_fan.h"

namespace esphome {
namespace levoit {

static const char *const TAG = "levoit-core200s.fan";

void LevoitFan::setup() {
  this->pin_night_->setup();
  this->pin_night_->pin_mode(gpio::FLAG_OUTPUT);
  this->pin_night_->digital_write(false);
  this->pin_low_->setup();
  this->pin_low_->pin_mode(gpio::FLAG_OUTPUT);
  this->pin_low_->digital_write(false);
  this->pin_medium_->setup();
  this->pin_medium_->pin_mode(gpio::FLAG_OUTPUT);
  this->pin_medium_->digital_write(false);
  this->pin_high_->setup();
  this->pin_high_->pin_mode(gpio::FLAG_OUTPUT);
  this->pin_high_->digital_write(false);
  this->pin_led_night_->setup();
  this->pin_led_night_->pin_mode(gpio::FLAG_OUTPUT);
  this->pin_led_night_->digital_write(false);
  this->pin_led_low_->setup();
  this->pin_led_low_->pin_mode(gpio::FLAG_OUTPUT);
  this->pin_led_low_->digital_write(false);
  this->pin_led_medium_->setup();
  this->pin_led_medium_->pin_mode(gpio::FLAG_OUTPUT);
  this->pin_led_medium_->digital_write(false);
  this->pin_led_high_->setup();
  this->pin_led_high_->pin_mode(gpio::FLAG_OUTPUT);
  this->pin_led_high_->digital_write(false);

  this->state = false;
  this->speed = 0;
  this->publish_state();
}

void LevoitFan::dump_config() { LOG_FAN("", "Levoit Fan", this); }

fan::FanTraits LevoitFan::get_traits() {
  // 200s has 4 speeds (night, low, medium, high)
  return fan::FanTraits(false, true, false, 4);
}

void LevoitFan::control(const fan::FanCall &call) {
  bool newPowerState = this->state;

  if (call.get_state().has_value()) {
    newPowerState = *call.get_state();
    
    if (newPowerState) {
      // power on
      this->setFanOff();
      this->pin_low_->digital_write(true);
      this->state = true;
      this->speed = 1;
    } else {
      // power off
      this->setFanOff();
      this->state = false;
      this->speed = 0;
    }
  }

  if (call.get_speed().has_value()) {
    uint8_t targetSpeed = *call.get_speed();

    switch (targetSpeed) {
      case 0:
        // send power off
        this->setFanOff();
        this->state = false;
        this->speed = 0;
        break;
      case 1:
        // speed 1
        this->setFanOff();
        this->pin_night_->digital_write(true);
        this->pin_led_night_->digital_write(true);
        this->state = true;
        this->speed = 1;
        break;
      case 2:
        // speed 2
        this->setFanOff();
        this->pin_low_->digital_write(true);
        this->pin_led_low_->digital_write(true);
        this->state = true;
        this->speed = 2;
        break;
      case 3:
        // speed 3
        this->setFanOff();
        this->pin_medium_->digital_write(true);
        this->pin_led_medium_->digital_write(true);
        this->state = true;
        this->speed = 3;
        break;
      case 4:
        // speed 4
        this->setFanOff();
        this->pin_high_->digital_write(true);
        this->pin_led_high_->digital_write(true);
        this->state = true;
        this->speed = 4;
        break;
    }
  }

  this->publish_state();
}

void LevoitFan::setFanOff() {
  this->pin_night_->digital_write(false);
  this->pin_low_->digital_write(false);
  this->pin_medium_->digital_write(false);
  this->pin_high_->digital_write(false);
  this->pin_led_night_->digital_write(false);
  this->pin_led_low_->digital_write(false);
  this->pin_led_medium_->digital_write(false);
  this->pin_led_high_->digital_write(false);
}

}  // namespace levoit
}  // namespace esphome
