from esphome import pins
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import fan
from esphome.const import (
    CONF_OUTPUT_ID
)

from .. import levoit_ns, CONF_LEVOIT_ID, Levoit

DEPENDENCIES = ["levoit-core200s"]
CODEOWNERS = ["@hiteule"]

CONF_PIN_NIGHT = "pin_night"
CONF_PIN_LOW = "pin_low"
CONF_PIN_MEDIUM = "pin_medium"
CONF_PIN_HIGH = "pin_high"
CONF_PIN_LED_NIGHT = "pin_led_night"
CONF_PIN_LED_LOW = "pin_led_low"
CONF_PIN_LED_MEDIUM = "pin_led_medium"
CONF_PIN_LED_HIGH = "pin_led_high"

LevoitFan = levoit_ns.class_("LevoitFan", cg.Component, fan.Fan)

CONFIG_SCHEMA = fan.fan_schema(LevoitFan).extend(
    {
        cv.GenerateID(CONF_OUTPUT_ID): cv.declare_id(LevoitFan),
        cv.GenerateID(CONF_LEVOIT_ID): cv.use_id(Levoit),
        cv.Required(CONF_PIN_NIGHT): pins.gpio_input_pin_schema,
        cv.Required(CONF_PIN_LOW): pins.gpio_input_pin_schema,
        cv.Required(CONF_PIN_MEDIUM): pins.gpio_input_pin_schema,
        cv.Required(CONF_PIN_HIGH): pins.gpio_input_pin_schema,
        cv.Required(CONF_PIN_LED_NIGHT): pins.gpio_input_pin_schema,
        cv.Required(CONF_PIN_LED_LOW): pins.gpio_input_pin_schema,
        cv.Required(CONF_PIN_LED_MEDIUM): pins.gpio_input_pin_schema,
        cv.Required(CONF_PIN_LED_HIGH): pins.gpio_input_pin_schema,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    parent = await cg.get_variable(config[CONF_LEVOIT_ID])

    var = cg.new_Pvariable(config[CONF_OUTPUT_ID], parent)
    await cg.register_component(var, config)
    await fan.register_fan(var, config)

    pin_night = await cg.gpio_pin_expression(config[CONF_PIN_NIGHT])
    cg.add(var.set_pin_night(pin_night))

    pin_low = await cg.gpio_pin_expression(config[CONF_PIN_LOW])
    cg.add(var.set_pin_low(pin_low))

    pin_medium = await cg.gpio_pin_expression(config[CONF_PIN_MEDIUM])
    cg.add(var.set_pin_medium(pin_medium))

    pin_high = await cg.gpio_pin_expression(config[CONF_PIN_HIGH])
    cg.add(var.set_pin_high(pin_high))

    pin_led_night = await cg.gpio_pin_expression(config[CONF_PIN_LED_NIGHT])
    cg.add(var.set_pin_led_night(pin_led_night))

    pin_led_low = await cg.gpio_pin_expression(config[CONF_PIN_LED_LOW])
    cg.add(var.set_pin_led_low(pin_led_low))

    pin_led_medium = await cg.gpio_pin_expression(config[CONF_PIN_LED_MEDIUM])
    cg.add(var.set_pin_led_medium(pin_led_medium))

    pin_led_high = await cg.gpio_pin_expression(config[CONF_PIN_LED_HIGH])
    cg.add(var.set_pin_led_high(pin_led_high))
