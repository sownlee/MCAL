#======================================= Begin User Config ============================
TEST_NAME = 'Port_TS_001'
TEST_MODULE = 'Port'
TEST_COMPILER = 'gcc'   # gcc/iar/ghs/ghs_c/keilC
GET_LINE_FAILED = 'True' # True
TEST_PC_COM_PORT = 'COM1' # Open device manager to get
TEST_CORE_LIST = '' # M7_CORE0/M4_CORE1/M7_CORE0_and_M4_CORE1. If TEST_CORE_LIST = '' then default run on M7_CORE0
SILICON_NAME = 'STM32F407VG' # S32K144/STM32F407VG/STM32H755ZI/   DEVICE =STM32H755ZI_M7/STM32H755ZI_M4   DEVICE = SILICON_NAME + '_' + TEST_CORE_LIST.split("_")[0]
SILICON_FAMILY = 'STM32F4XX' # STM32H7XX/STM32F4XX
DEBUGGER_JLINK_INTERFACE = 'USB' # IP  USB
DEBUGGER_SERIAL_NUMBER = '59768862' # (621000000/ 59768862)  If DEBUGGER_JLINK_INTERFACE = USB
DEBUGGER_JLINK_IP = '192.168.1.6' # If JLINK_INTERFACE = IP 192.168.1.6   tunnel:59768862::jlink-asia.segger.com
FOLDER_T32_INSTALL = 'H:/00_Compiler/TRACE32_R_2023_02_000159199/files'
DEBUGGER_T32_EXE = 'H:/00_Compiler/TRACE32_R_2023_02_000159199/files/bin/windows64/t32marm.exe'
FOLDER_PYTHON = 'H:/02_Python310'
FOLDER_GCC = 'H:/00_Compiler/GCC_102'
FOLDER_IAR = 'H:/00_Compiler/IAR Systems/Embedded Workbench 8.4/arm'
FOLDER_GENERATOR = 'C:/EB/tresos'
FOLDER_OZONE = 'H:/01_SEGGER/Ozone/Ozone.exe'
FOLDER_JLINK = 'H:/01_SEGGER/JLink/JLink.exe'
PRO_DIR = 'H:/Classic_Autosar_01/02_hfw'
FOLDER_TEST_PRODIR = f'{PRO_DIR}/tests_new/{SILICON_NAME}'
FOLDER_FRAMEWORK_PRODIR = f'{PRO_DIR}'
FOLDER_PLUGIN = f'{FOLDER_GENERATOR}/plugins'
FOLDER_OUTPUT = f'{PRO_DIR}/zOutput'
#======================================= End User Config ==============================
#======================================= Begin Read Only ==============================
PLUGIN_COMMON_NAME = 'HULA15440090'
TEST_PROJECT = "EbProject"
TEST_GENERATER = 'Eb_Tresos'
TEST_DEBUGGER = 'ozone'  # ozone/lauterbach
TEST_EPD_TYPE = 'epd@asc:4.4.0' # epd@asc:4.4.0
DEBUGGER_INTERFACE = 'JTAG'  # JTAG/ SWD
FOLDER_EB_TESTPROJECT = f'{FOLDER_TEST_PRODIR}/build_env/{TEST_PROJECT}'
LINKER_FILE_FLASH_OR_RAM = 'flash'  # flash/ram
GEN_EPD_BY_RESOURCE = 'STM32H7XX_lqfp144' # STM32H7XX_lqfp144/STM32F4XX_lqfp144
PRE_EXECUTE_CMD = None
POST_EXECUTE_CMD = None
#======================================= End Read Only ===============================
#======================================= Begin M4 Replace ============================
M4_TARGET_ARCHITECTURE = 'CORTEXM' # CORTEXM
M4_HW_SILICON_NAME = f'{SILICON_NAME}'
M4_EB_VERSION = '28.2.0' # 28.2.0     29.3.0
M4_SOFTWARE_VERSION = '0.9.0 BETA' # 0.9.0 BETA
M4_HW_RELEASE_NAME = f'{PLUGIN_COMMON_NAME}'
M4_TEST_PROJECT = f'{TEST_PROJECT}'
#======================================= End M4 Replace ==============================