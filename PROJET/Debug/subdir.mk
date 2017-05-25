################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Algorithm.cpp \
../Camera.cpp \
../Color.cpp \
../Light.cpp \
../Materiau.cpp \
../RayDataStructure.cpp \
../Scene.cpp \
../Sphere.cpp \
../Vector.cpp \
../main.cpp 

O_SRCS += \
../Vector.o \
../main.o 

OBJS += \
./Algorithm.o \
./Camera.o \
./Color.o \
./Light.o \
./Materiau.o \
./RayDataStructure.o \
./Scene.o \
./Sphere.o \
./Vector.o \
./main.o 

CPP_DEPS += \
./Algorithm.d \
./Camera.d \
./Color.d \
./Light.d \
./Materiau.d \
./RayDataStructure.d \
./Scene.d \
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


