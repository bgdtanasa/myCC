SRC_DIR=src
SOURCES=$(shell find $(SRC_DIR) -name "*.c")
OBJECTS=$(SOURCES:%.c=%.o)
DEPS=$(OBJECTS:%.o=%.d)
TARGET=myCC

INC_DIR=inc
INC_SUBDIRS=$(shell find $(INC_DIR) -type d)
INC_FLAGS=$(addprefix -I,$(INC_SUBDIRS))

CXX=gcc
CFLAGS=$(INC_FLAGS) -Wall -Wextra -O3 -ggdb -std=gnu99 -MMD -MP

-include $(DEPS)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK.cc) $^ -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)
