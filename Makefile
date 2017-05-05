bin = conta-caminhos

# All Target
all: $(bin)

# Tool invocations
$(bin): $(bin).o
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "$(bin)"  ./src/$(bin).o   -lcgraph
	@echo 'Finished building target: $@'
	@echo ' '

$(bin).o:
	g++ -O3 -Wall -Wextra -c -fmessage-length=0 -std=c++11 -MMD -MP \
	-MF"src/$(bin).d" \
	-MT"src/$(bin).o" \
	-o "src/$(bin).o" \
	"src/$(bin).cpp"

clean:
	rm -rf  ./src/*.o  ./src/*.d  $(bin)
