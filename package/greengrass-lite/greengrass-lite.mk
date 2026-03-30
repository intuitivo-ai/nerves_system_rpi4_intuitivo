################################################################################
#
# greengrass-lite
#
# Upstream minimum deps: aws-greengrass-lite docs/SETUP.md
# Buildroot 2024.02.x (typical): curl 8.x, openssl 3.x, sqlite 3.44.x,
# libevent 2.1.12, libyaml/libzip/uriparser/util-linux above mins, libcgroup 2.0.3+.
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
	uriparser \
	libzip \
	util-linux \
	openssl \
	libcgroup \
	host-pkgconf

GREENGRASS_LITE_CONF_OPTS = \
	-DGGL_SYSTEMD_SERVICE_BUILD=OFF \
	-DBUILD_TESTING=OFF \
	-DBUILD_EXAMPLES=OFF \
	-DCMAKE_BUILD_TYPE=MinSizeRel

$(eval $(cmake-package))
