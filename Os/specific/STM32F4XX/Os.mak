################################################################################
# Information module
################################################################################
DEV_MODULE_NAME = Os
DEV_PLATFORM_NAME = STM32F4XX

################################################################################
# BSW module ID (see 'AUTOSAR_BasicSoftwareModules.pdf' for details)
################################################################################
DEV_MODULE_ID_AUTOSAR = 1

################################################################################
# List of files and directories to build the tresos plugin
################################################################################

# Get xdm file
DEV_SRC_FILES = $(MODULE_PATH)/specific/$(PLATFORM_NAME)/config/Os.xdm@outdir=config \

# Get docs files
DEV_SRC_FILES +=$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/OS_IM.pdf@outdir=doc \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/OS_UM.pdf@outdir=doc \

# Get source and include template files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/generate_PC/include/Os_cfg.h@outdir=generate_PC/include \


# Get source and include files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/include/Os.h@outdir=include \
				$(MODULE_PATH)/generic/src/Os.c@outdir=src \

# Get example folder
DEV_SRC_DIR =$(MODULE_PATH)/specific/$(PLATFORM_NAME)/examples
