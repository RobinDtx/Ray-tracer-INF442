################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../RayDataStructure.cpp \
../Sphere.cpp \
../Vector.cpp \
../main.cpp 

O_SRCS += \
../Vector.o \
../main.o 

OBJS += \
./RayDataStructure.o \
./Sphere.o \
./Vector.o \
./main.o 

CPP_DEPS += \
./RayDataStructure.d \
./Sphere.d \
./Vector.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


