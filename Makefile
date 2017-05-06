SRC = src/

bin = conta-caminhos
Path = Path

OBJS = $(SRC)$(Path).o $(SRC)$(bin).o

LIBS = -lcgraph

# All Target
all: $(bin)

# Tool invocations
$(bin): $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "conta-caminhos" $(OBJS) $(LIBS) -std=c++11
	@echo 'Finished building target: $@'
	@echo ' '

$(SRC)$(bin).o:
	g++ -O3 -Wall -Wextra -c -fmessage-length=0 -std=c++11 -MMD -MP \
	-MF"$(SRC)$(bin).d" -MT"$(SRC)$(bin).o" -o "$(SRC)$(bin).o" \
	"$(SRC)$(bin).cpp"

$(SRC)$(Path).o:
	g++ -O3 -Wall -Wextra -c -fmessage-length=0 -std=c++11 -MMD -MP \
	-MF"$(SRC)$(Path).d" -MT"$(SRC)$(Path).o" -o "$(SRC)$(Path).o" \
	"$(SRC)$(Path).cpp"

clean:
	rm -rf  ./$(SRC)*.o  ./$(SRC)*.d  $(bin)
