BUILD_DIR = Build

all: clean configure run

configure:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -G "MinGW Makefiles" -DBUILD_EXAMPLES=ON .. && mingw32-make

clean:
	rm -rf $(BUILD_DIR)

run:
	$(BUILD_DIR)/Examples/Example.exe