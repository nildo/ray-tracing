TARGET   = ray-tracing

CC       = g++
CFLAGS   = -Wall -I.

LINKER   = g++ -o
LFLAGS   = -Wall -I. -lm

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
DIRS     = $(SRCDIR) $(OBJDIR) $(BINDIR)

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f
rmdir    = rm -rf


$(BINDIR)/$(TARGET): $(DIRS) $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(DIRS):
	@mkdir -p $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@$(rmdir) $(OBJDIR)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@$(rmdir) $(BINDIR)
	@echo "Executable removed!"

.PHONY: run
run: $(BINDIR)/$(TARGET)
	@cd $(BINDIR) &&	./$(TARGET)
