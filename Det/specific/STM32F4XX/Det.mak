################################################################################
# Information module
################################################################################
DEV_MODULE_NAME = Det
DEV_PLATFORM_NAME = STM32F4XX

################################################################################
# BSW module ID (see 'AUTOSAR_BasicSoftwareModules.pdf' for details)
################################################################################
DEV_MODULE_ID_AUTOSAR = 15

# Get docs files
DEV_SRC_FILES +=$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/DET_IM.pdf@outdir=doc \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/DET_UM.pdf@outdir=doc \

# Get example folder
DEV_SRC_DIR =$(MODULE_PATH)/specific/$(PLATFORM_NAME)/examples

################################################################################
# List of files and directories to build the tresos plugin
################################################################################

# Get xdm file
DEV_SRC_FILES = $(MODULE_PATH)/specific/$(PLATFORM_NAME)/config/Det.xdm@outdir=config \

# Get source and include files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/include/Det_Stub.h@outdir=include \
				$(MODULE_PATH)/generic/include/Det.h@outdir=include \
				$(MODULE_PATH)/generic/src/Det_Stub.c@outdir=src \
				$(MODULE_PATH)/generic/src/Det.c@outdir=src \
				
