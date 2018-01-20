################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Consumer.cpp \
../src/Main.cpp \
../src/Operation.cpp \
../src/Producer.cpp 

OBJS += \
./src/Consumer.o \
./src/Main.o \
./src/Operation.o \
./src/Producer.o 

CPP_DEPS += \
./src/Consumer.d \
./src/Main.d \
./src/Operation.d \
./src/Producer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


