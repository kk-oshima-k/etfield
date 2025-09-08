mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_CXXOBJS += \
	DriveController.o \
	ColorSensorController.o \
	UltrasonicSensorController.o \
	Driver.o \
	LineTracer.o \
	StraightDriver.o \
	RotationDriver.o \
	Detector.o \
	ColorDetector.o \
	UltrasonicDetector.o \
	DistanceDetector.o \
	AngleDetector.o \
	Scene.o \
	StraightScene.o \
	FindBottleWithLineTraceScene.o \
	LineTraceScene.o \
	RotationScene.o \
	Scenario.o \
	ETRobo.o \
	Scenario1.o \
	Scenario2.o \
	Scenario3.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-spike/Makefile

endif

APPL_DIRS += $(mkfile_path)ETRobo $(mkfile_path)ETRobo/Scenario1 $(mkfile_path)ETRobo/Scenario2 $(mkfile_path)ETRobo/Scenario3 $(mkfile_path)Device $(mkfile_path)Driver $(mkfile_path)Detector $(mkfile_path)Scene $(mkfile_path)Scenario

INCLUDES += \
	-I$(mkfile_path)Common \
	-I$(mkfile_path)Device \
	-I$(mkfile_path)Driver \
	-I$(mkfile_path)Detector \
	-I$(mkfile_path)Scene \
	-I$(mkfile_path)Scenario \
	-I$(mkfile_path)ETRobo \
	-I$(mkfile_path)ETRobo/Scenario1 \
	-I$(mkfile_path)ETRobo/Scenario2 \
	-I$(mkfile_path)ETRobo/Scenario3
