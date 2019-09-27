OS=$(shell $(CXX) -dumpmachine)
ifneq (,$(findstring mingw,$(OS)))
SOEXT?=dll
BINEXT?=exe
else
SOEXT?=so
BINEXT?=out
endif
ifneq (,$(findstring mingw,$(OS)))
RUNENV=PYTHONHOME=/usr
else
RUNENV=
endif

ifeq ($(PREFIX),)
PREFIX := /usr/local
endif
CC=gcc
CXX=g++
AR=ar
BUILDDIR=./bin/build
BIN=./bin/a.$(BINEXT)
SRCDIR=src
SRC:=$(shell find $(SRCDIR) -name '*.cpp')
OBJS:=$(addprefix $(BUILDDIR)/,$(SRC:%.cpp=%.o))
CFLAGS=\
	-I./include
LDFLAGS=\
	-lboost_atomic-mt\
	-lboost_chrono-mt\
	-lboost_container-mt\
	-lboost_context-mt\
	-lboost_contract-mt\
	-lboost_coroutine-mt\
	-lboost_date_time-mt\
	-lboost_exception-mt\
	-lboost_filesystem-mt\
	-lboost_graph-mt\
	-lboost_iostreams-mt\
	-lboost_locale-mt\
	-lboost_log_setup-mt\
	-lboost_log-mt\
	-lboost_math_c99f-mt\
	-lboost_math_c99l-mt\
	-lboost_math_c99-mt\
	-lboost_math_tr1f-mt\
	-lboost_math_tr1l-mt\
	-lboost_math_tr1-mt\
	-lboost_numpy27-mt\
	-lboost_numpy37-mt\
	-lboost_prg_exec_monitor-mt\
	-lboost_program_options-mt\
	-lboost_python27-mt\
	-lboost_python37-mt\
	-lboost_random-mt\
	-lboost_regex-mt\
	-lboost_serialization-mt\
	-lboost_stacktrace_noop-mt\
	-lboost_stacktrace_windbg-mt\
	-lboost_system-mt\
	-lboost_test_exec_monitor-mt\
	-lboost_thread-mt\
	-lboost_timer-mt\
	-lboost_type_erasure-mt\
	-lboost_unit_test_framework-mt\
	-lboost_wave-mt\
	-lboost_wserialization-mt
all:\
	$(BIN)
$(BIN):$(OBJS)
	@$(CXX)\
		$(CFLAGS)\
		$(OBJS)\
		$(LDFLAGS)\
		-o $(BIN)
$(BUILDDIR)/%.o: %.cpp
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	@$(CXX)\
		$(CFLAGS)\
		-c $<\
		$(LDFLAGS)\
		-o $@
.phony:\
	run\
	clean\
	lsvar
clean:
	@rm -r ./bin
run: $(BIN)
	$(RUNENV) $(BIN)
lsvar:
	@echo $(BIN)
	@echo $(OBJS)
	@echo $(SRC)
	@echo $(SRCDIR)
	@echo $(PREFIX)




