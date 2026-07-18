################################################################################
# Information module
################################################################################
DEV_MODULE_NAME = Dem
DEV_PLATFORM_NAME = STM32F4XX

################################################################################
# BSW module ID (see 'AUTOSAR_BasicSoftwareModules.pdf' for details)
################################################################################
DEV_MODULE_ID_AUTOSAR = 54

# Get docs files
DEV_SRC_FILES +=$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/DEM_IM.pdf@outdir=doc \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/DEM_UM.pdf@outdir=doc \

# Get example folder
DEV_SRC_DIR =$(MODULE_PATH)/specific/$(PLATFORM_NAME)/examples

################################################################################
# List of files and directories to build the tresos plugin
################################################################################

# Get xdm file
DEV_SRC_FILES = $(MODULE_PATH)/specific/$(PLATFORM_NAME)/config/Dem.xdm@outdir=config \

# Get source and include template files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/generate_PC/include/Dem_IntErrId.h@outdir=generate_PC/include \   

# Get source and include files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/include/Dem_Stub.h@outdir=include \
				$(MODULE_PATH)/generic/include/Dem.h@outdir=include \
				$(MODULE_PATH)/generic/src/Dem_Stub.c@outdir=src \
				$(MODULE_PATH)/generic/src/Dem.c@outdir=src
