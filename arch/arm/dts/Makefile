#
# SPDX-License-Identifier:	GPL-2.0+
#


dtb-$(CONFIG_EXYNOS4) += exynos4412-trats2.dtb \
	exynos4412-odroid.dtb


targets += $(dtb-y)

# Add any required device tree compiler flags here
DTC_FLAGS +=

PHONY += dtbs
dtbs: $(addprefix $(obj)/, $(dtb-y))
	@:

clean-files := *.dtb
