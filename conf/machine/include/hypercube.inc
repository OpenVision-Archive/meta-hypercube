# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc

BOX_BRAND = "hypercube"

KERNEL_FILE = "e2-kernel.bin"
ROOTFS_FILE = "e2-rootfs.jffs2"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	${MACHINE}-dvb-modules \
	"

EXTRA_IMAGEDEPENDS += "\
	${MACHINE}-uboot-tools \
	${MACHINE}-user-libs \
	${MACHINE}-extra-modules \
	"

MACHINE_EXTRA_RDEPENDS += "\
	${MACHINE}-uboot-tools \
	${MACHINE}-user-libs \
	"

DVBMEDIASINK_CONFIG = "--with-dts --with-limited-mpeg4v2 --with-eac3 --with-wma --with-wmv --with-pcm"

IMAGE_FSTYPES ?= "jffs2 su980-usbimg"

IMAGE_CLASSES += "usb_image-su980"

JFFS2_ERASEBLOCK = "0x20000"
EXTRA_IMAGECMD_jffs2 = "--disable-compressor=lzo --compression-mode=size"

IMAGEDIR = "${MACHINE}/e2"

# TODO: this needs fixing...
IMAGE_CMD_jffs2_append = "; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	cd ${DEPLOY_DIR_IMAGE}; \
	rm -rf ${MACHINE}; \
	mkdir -p ${IMAGEDIR}; \
	cp -a boot.bin loader.bin upgrade.scr ${MACHINE}/; \
	cp -L ${KERNEL_IMAGETYPE}-${MACHINE}.bin ${IMAGEDIR}/${KERNEL_FILE}; \
	cp -a ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.jffs2 ${IMAGEDIR}/${ROOTFS_FILE}; \
	zip -r ${IMAGE_NAME}_usb.zip ${MACHINE}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.jffs2; \
	rm -rf ${MACHINE}; \
	"

MACHINE_FEATURES += "alsa 32bpp usbhost ci oldkernel triaccel olde2api HDMI RCA YUV"

DVBPROVIDER = "kernel"

KERNEL_IMAGETYPE ?= "Image"

SERIAL_CONSOLE = "115200 ttyS1"

PREFERRED_PROVIDER_virtual/kernel = "linux-su980"
PREFERRED_VERSION_linux-cube = "2.6.34"
PREFERRED_VERSION_wpa-supplicant = "0.5.8"
PREFERRED_VERSION_rtl8192cu = "3.3.0"
PREFERRED_VERSION_wscan = "20130331"

OLDEST_KERNEL = "2.6.34"
GCCVERSION = "4.9.4"
GLIBCVERSION = "2.19"

GLIBC_EXTRA_OECONF = "--with-tls --with-__thread"

DEFAULTTUNE = "cortexa9"

require conf/machine/include/tune-cortexa9.inc

TUNE_CCARGS += "${@bb.utils.contains("TUNE_FEATURES", "cortexa9", "-march=armv7-a -mtune=cortex-a9 -mfpu=vfpv3-d16 -mfloat-abi=softfp", "", d)}"
