# Переменные
CC       = gcc
CFLAGS   = -Wall -Wextra -Wpedantic -std=c23 -Iinclude
TARGET   = app
SRCDIR   = src
BUILDDIR = build
INCDIR   = include

# Автоматический поиск всех .c файлов в папке src
SOURCES  = $(wildcard $(SRCDIR)/*.c)
# Замена .c на .o и добавление пути build/
OBJECTS  = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))

# Цель по умолчанию
all: $(BUILDDIR)/$(TARGET)

run: all
	.\build\app.exe

# Линковка
$(BUILDDIR)/$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Паттерн-правило для компиляции .c -> .o
# | $(BUILDDIR) — это order-only prerequisite (папка build/ должна существовать)
$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Создание папки build/ (для Windows)
$(BUILDDIR):
	mkdir $(BUILDDIR)

# Очистка (для Windows)
clean:
	rmdir /S /Q $(BUILDDIR) 2>nul

# Фальшивые цели
.PHONY: all clean