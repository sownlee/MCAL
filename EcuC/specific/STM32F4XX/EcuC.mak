################################################################################
# Information module
################################################################################
DEV_MODULE_NAME = EcuC
DEV_PLATFORM_NAME = STM32F4XX

################################################################################
# BSW module ID (see 'AUTOSAR_BasicSoftwareModules.pdf' for details)
################################################################################
DEV_MODULE_ID_AUTOSAR = 0
M4_POSTBUILD_SETUP_SUPPORT = 1
################################################################################
# List of files and directories to build the tresos plugin
################################################################################

# Get xdm file
DEV_SRC_FILES = $(MODULE_PATH)/specific/$(PLATFORM_NAME)/config/EcuC.xdm@outdir=config \

# Get docs files
DEV_SRC_FILES +=$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/ECUC_IM.pdf@outdir=doc \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/ECUC_UM.pdf@outdir=doc \

# Get example folder
DEV_SRC_DIR =$(MODULE_PATH)/specific/$(PLATFORM_NAME)/examples
