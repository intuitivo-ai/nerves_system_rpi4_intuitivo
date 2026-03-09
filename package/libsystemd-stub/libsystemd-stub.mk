################################################################################
#
# libsystemd-stub
#
################################################################################

LIBSYSTEMD_STUB_VERSION = 0.1.0
LIBSYSTEMD_STUB_SITE = $(NERVES_DEFCONFIG_DIR)/package/libsystemd-stub/src
LIBSYSTEMD_STUB_SITE_METHOD = local
LIBSYSTEMD_STUB_INSTALL_STAGING = YES
LIBSYSTEMD_STUB_LICENSE = Apache-2.0

$(eval $(cmake-package))
