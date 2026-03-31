cmake_minimum_required(VERSION 3.15)

# 🔥 Proper cross-compilation setup
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Prevent CMake from trying to run binaries
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Compiler
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

project(stm32_baremetal C ASM)

# CPU options
set(CPU_OPTIONS -mcpu=cortex-m4 -mthumb)

# Linker script
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/linker.ld)

# Compiler flags
set(CMAKE_C_FLAGS
    "-mcpu=cortex-m4 -mthumb \
     -ffreestanding \
     -fdata-sections \
     -ffunction-sections \
     -fstrict-volatile-bitfields \
     -Wall \
     -O0 -g"
)

# Source directory
set(SRCDIR ${CMAKE_SOURCE_DIR}/src)

# Collect sources
file(GLOB_RECURSE SOURCE_FILES
    ${SRCDIR}/*.c
    ${SRCDIR}/*.s
)

# Target
add_executable(lab1 ${SOURCE_FILES})

# Include directories
target_include_directories(lab1 PRIVATE
    ${SRCDIR}
    ${SRCDIR}/CMSIS/Include
)

# Linker flags
target_link_options(lab1 PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -T${LINKER_SCRIPT}
    -nostartfiles
    -nostdlib
    -Wl,-Map=lab.map
    -Wl,--gc-sections
)