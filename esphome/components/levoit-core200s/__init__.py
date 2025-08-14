from esphome.components import time
from esphome import automation
from esphome import pins
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID

CODEOWNERS = ["@hiteule"]
CONF_LEVOIT_ID = "levoit-core200s"


levoit_ns = cg.esphome_ns.namespace("levoit")
Levoit = levoit_ns.class_("Levoit", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(Levoit),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
