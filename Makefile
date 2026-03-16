BUILD_DIR = Build

ifeq ($(OS), Windows_NT)
	EXECUTABLE = .exe
else
	EXECUTABLE = 
endif

all: clean configure run

configure:
	cmake -B $(BUILD_DIR) -DBUILD_EXAMPLES=ON .
	cmake --build $(BUILD_DIR)

clean:
	cmake -E rm -rf $(BUILD_DIR)

run:
	$(BUILD_DIR)/Examples/Example$(EXECUTABLE)