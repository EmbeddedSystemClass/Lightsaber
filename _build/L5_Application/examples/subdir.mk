################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../L5_Application/examples/examples.cpp \
../L5_Application/examples/rn_xv_task.cpp 

OBJS += \
./L5_Application/examples/examples.o \
./L5_Application/examples/rn_xv_task.o 

CPP_DEPS += \
./L5_Application/examples/examples.d \
./L5_Application/examples/rn_xv_task.d 


# Each subdirectory must supply rules for building sources it contributes
L5_Application/examples/%.o: ../L5_Application/examples/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -ffunction-sections -fdata-sections -Wall -Wshadow -Wlogical-op -Wfloat-equal -DBUILD_CFG_MPU=0 -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\newlib" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L0_LowLevel" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L1_FreeRTOS" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L1_FreeRTOS\include" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L1_FreeRTOS\portable" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L2_Drivers" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L2_Drivers\base" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L3_Utils" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L3_Utils\tlm" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L4_IO" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L4_IO\fat" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L4_IO\wireless" -I"D:\seeve\SJSUOne\SJSU_Dev\projects\lpc1758_helloworld\L5_Application" -std=gnu++11 -fabi-version=0 -fno-exceptions -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


