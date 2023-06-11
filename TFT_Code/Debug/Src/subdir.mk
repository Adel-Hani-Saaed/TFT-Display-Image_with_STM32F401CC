################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MGPIO_Program.c \
../Src/MRCC_Program.c \
../Src/SPI_program.c \
../Src/SYSTICK_program.c \
../Src/TFT_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/MGPIO_Program.o \
./Src/MRCC_Program.o \
./Src/SPI_program.o \
./Src/SYSTICK_program.o \
./Src/TFT_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/MGPIO_Program.d \
./Src/MRCC_Program.d \
./Src/SPI_program.d \
./Src/SYSTICK_program.d \
./Src/TFT_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/MGPIO_Program.cyclo ./Src/MGPIO_Program.d ./Src/MGPIO_Program.o ./Src/MGPIO_Program.su ./Src/MRCC_Program.cyclo ./Src/MRCC_Program.d ./Src/MRCC_Program.o ./Src/MRCC_Program.su ./Src/SPI_program.cyclo ./Src/SPI_program.d ./Src/SPI_program.o ./Src/SPI_program.su ./Src/SYSTICK_program.cyclo ./Src/SYSTICK_program.d ./Src/SYSTICK_program.o ./Src/SYSTICK_program.su ./Src/TFT_program.cyclo ./Src/TFT_program.d ./Src/TFT_program.o ./Src/TFT_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

