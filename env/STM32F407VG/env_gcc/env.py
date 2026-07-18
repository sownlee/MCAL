LINKER_FILE = f'{FOLDER_FRAMEWORK_PRODIR}/env/{SILICON_NAME}/env_{TEST_COMPILER}/linker/ThoNV_linker_{LINKER_FILE_FLASH_OR_RAM}_C0.ld'
LK_FILE = CC_FILE = AC_FILE = f'{FOLDER_GCC}/bin/arm-none-eabi-gcc.exe'
POST_COMPILE = f'{FOLDER_GCC}/arm-none-eabi/bin/objcopy.exe'

POST_BIN_COMPILE_OPTS= [
    '-O',
    'binary'
]

POST_HEX_COMPILE_OPTS = [
    '-O',
    'ihex'
]

CC_OPTS = [
    '-c',
    '-mcpu=cortex-m4',
    '-mthumb',
    '-mlittle-endian',
    '-O0',
    '-fstack-usage',
    '-g',
    # '-Wall',
    '-D_GCC_HULA_',
    '-DDEBUGGER_OZONE',
    '-DGET_LINE_FAILED',
    '-Werror=implicit-function-declaration',
    '-DAUTOSAR_OS_NOT_USED'
]

LK_OPTS = [
    f'-Wl,-Map,MAP_FILE_REPLACE',
    '--entry=Reset_Handler',
    '-specs=nano.specs',
    '-specs=nosys.specs',
    '-mcpu=cortex-m4',
    '-mlittle-endian',
    '-nostdlib',
    '-n',
    '-T',
    f'{LINKER_FILE}'
]
AC_OPTS = [
    '-c',
    '-mthumb',
    '-mcpu=cortex-m4',
    '-x',
    'assembler-with-cpp'
]

# ID: gcc
# Name: GCC Compiler
# Vendor: GCC Systems
# Version: GCC 10.3.0 20211010

# Compiler Option                        | Description
# ---------------                        | -----------
# -mcpu=cortex-m7                        | Selects target processor: Arm Cortex M7
# -Os                                    | Use optimization for size
# -c                                     | Generate code for a processor running in little-endian mode
# -DAUTOSAR_OS_NOT_USED                  | Specifies the AUTOSAR OS is not used
# -ggdb3                                 | Produce debugging information for use by GDB. Level 3 includes extra information, such as all the macro definitions present in the program.
# -mthumb                                | Selects generating code that executes in Thumb state.
# -mlittle-endian                        | Optimize for size. Enables all -O2 optimizations except those that often increase code size
# -fomit-frame-pointer                   | Removes the frame pointer for all functions, which might make debugging harder.
# -mfloat-abi=softfp                     | Specifies which floating-point ABI to use. Use ‘softfp’ allows the generation of code using hardware floating-point instructions, but still uses the soft-float calling conventions
# -fno-common                            | Specifies that the compiler should place uninitialized global variables in the data section of the object file, rather than generating them as common blocks.
# -Wall                                  | Enables all the warnings about constructions that some users consider questionable, and that are easy to avoid even in conjunction with macros.
# -Wextra                                | Enables some extra warning flags that are not enabled by ‘-Wall’.
# -Wstrict-prototypes                    | Warn if a function is declared or defined without specifying the argument types.
# -Wno-sign-compare                      | Do not warn when a comparison between signed and unsigned values could produce an incorrect result when the signed value is converted to unsigned
# -fstack-usage                          | Geneates an extra file that specifies the maximum amount of stack used, on a per-function basis.
# -fdump-ipa-all                         | Enables all inter-procedural analysis dumps.
# -Werror=implicit-function-declaration  | An error is generated whenever a function is used before being declared


# # GCC Assembler Options
# Assembler Option                       | Description
# -------------                          | -----------
# -mcpu=cortex-m7                        | Targeted ARM processor for which GCC should tune the performance of the code
# -mthumb                                | Generates code that executes in Thumb state
# -c                                     | Stop after assembly and produce an object file for each source file
# -x assembler-with-cpp                  | Specifies the language for the following input files (rather than letting the compiler choose a default based on the file name suffix)


# # GCC Linker Options
# Linker Option                          | Description
# ----------------                       | -----------
# -mcpu=cortex-m7                        | Selects target processor: Arm Cortex M7
# -mthumb                                | Selects generating code that executes in Thumb state.
# -nostartfiles                          | Generates code that executes in Thumb state
# -mlittle-endian                        | Stop after assembly and produce an object file for each source file
# -Wl,-Map,MAP_FILE_REPLACE              | Produces a map file
# -T                                     | Use script as the linker script
# f'{LINKER_FILE}'                       | Use linkerfile as the linker script. This script replaces the default linker script (rather than adding to it)
