################################################################################
# Information module
################################################################################
DEV_MODULE_NAME = Resource
DEV_PLATFORM_NAME = STM32F4XX

################################################################################
# BSW module ID (see 'AUTOSAR_BasicSoftwareModules.pdf' for details)
################################################################################
DEV_MODULE_ID_AUTOSAR = 0
M4_RESOURCE_PROPERTY_SUPPORT = 1
RESOURCE_MODULES = System Rte Os EcuC Det Dem Port Uart Spi
RESOURCE_PACKAGE = STM32F4XX_lqfp144 \
				   STM32F4XX_lqfp212

################################################################################
# List of files and directories to build the tresos plugin
################################################################################

# Get xdm file
DEV_SRC_FILES = $(MODULE_PATH)/specific/$(PLATFORM_NAME)/config/Resource.xdm@outdir=config

# Get docs files
DEV_SRC_FILES +=$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/RESOURCE_IM.pdf@outdir=doc \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/RESOURCE_UM.pdf@outdir=doc \