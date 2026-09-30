# Makefile for pediatric-icu-drug-calculator

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCDIR = src
OBJDIR = obj
BUILDDIR = build
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
TESTSRCS = $(wildcard tests/*.c)
TESTOBJS = $(patsubst tests/%.c,obj/%.o,$(TESTSRCS))

all: $(BUILDDIR)/main

$(BUILDDIR)/main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/test_runner: $(TESTOBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

check-unit: $(BUILDDIR)/test_runner
	./$(BUILDDIR)/test_runner

check-integration: $(BUILDDIR)/test_runner
	./$(BUILDDIR)/test_runner

.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(BUILDDIR)/main $(BUILDDIR)/test_runner