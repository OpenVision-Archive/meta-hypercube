FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
			file://declare-variables-outside-for-loop.patch \
			"
