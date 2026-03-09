################################################################################
#
# greengrass-lite
#
################################################################################

GREENGRASS_LITE_VERSION = v2.3.3
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
	host-pkgconf

GREENGRASS_LITE_CONF_OPTS = \
	-DGGL_SYSTEMD_SERVICE_BUILD=OFF \
	-DBUILD_TESTING=OFF \
	-DBUILD_EXAMPLES=OFF \
	-DCMAKE_BUILD_TYPE=MinSizeRel

$(eval $(cmake-package))
