################################################################################
#
# greengrass-lite
#
# Upstream minimum deps: aws-greengrass-lite docs/SETUP.md
# Buildroot 2024.02.x (typical): curl 8.x, openssl 3.x, sqlite 3.44.x,
# libevent 2.1.12, libyaml/libzip/liburiparser/util-linux above mins, libcgroup 2.0.3+.
# CMake enforces libcurl>=7.68 via pkg-config; other libs via pkg_search_module.
################################################################################

GREENGRASS_LITE_VERSION = v2.4.0
GREENGRASS_LITE_SITE = $(call github,aws-greengrass,aws-greengrass-lite,$(GREENGRASS_LITE_VERSION))
GREENGRASS_LITE_LICENSE = Apache-2.0
GREENGRASS_LITE_LICENSE_FILES = LICENSE
GREENGRASS_LITE_INSTALL_STAGING = NO

GREENGRASS_LITE_DEPENDENCIES = \
	libsystemd-stub \
	libcurl \
	sqlite \
	libyaml \
	libevent \
	liburiparser \
	libzip \
	util-linux \
	openssl \
	libcgroup \
	host-pkgconf

# CMake IPO is patched off for cross-builds, but if TARGET_* still carry -flto,
# object files inside static libs (e.g. libgg-sdk.a) can remain LTO bytecode; the
# final link then reports undefined refs to gg_log / gg_* from gg-sdk.
#
# Buildroot sets BUILD_SHARED_LIBS=ON by default; gg-sdk then becomes libgg-sdk.so.
# Our ggl-cli link uses -Wl,--whole-archive, which only applies to .a archives, so
# symbols from gg-sdk were dropped and the link failed with undefined gg_* refs.
GREENGRASS_LITE_CONF_OPTS = \
	-DBUILD_SHARED_LIBS=OFF \
	-DGGL_SYSTEMD_SERVICE_BUILD=OFF \
	-DBUILD_TESTING=OFF \
	-DBUILD_EXAMPLES=OFF \
	-DCMAKE_BUILD_TYPE=MinSizeRel \
	-DCMAKE_C_FLAGS="$(TARGET_CFLAGS) -fno-lto" \
	-DCMAKE_EXE_LINKER_FLAGS="$(TARGET_LDFLAGS) -fno-lto" \
	-DCMAKE_SHARED_LINKER_FLAGS="$(TARGET_LDFLAGS) -fno-lto" \
	-DCMAKE_MODULE_LINKER_FLAGS="$(TARGET_LDFLAGS) -fno-lto"

$(eval $(cmake-package))
