build_type ?= Release
build_type_lower = ${shell echo ${build_type} | tr "[:upper:]" "[:lower:]"}

build_dir ?= build/${build_type_lower}
cmake_dir := $(CURDIR)


all:
	@echo "Usage:"
	@echo -e "\tmake build"
	@echo -e "\tmake clean"
.PHONY: all

build:
	mkdir -p $(build_dir) && cd $(build_dir) && \
		cmake \
		-D CMAKE_BUILD_TYPE=$(build_type) \
		$(cmake_dir) && make
.PHONY: build

clean:
	rm -rf build
.PHONY: clean

# Redirect all undefined targets to cmake.
%:
	make -C $(build_dir) $@
.PHONY:
