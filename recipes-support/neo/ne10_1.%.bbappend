FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_su980 += " \
			file://declare-variables-outside-for-loop.patch \
			"
