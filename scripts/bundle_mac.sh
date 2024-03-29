#!/bin/sh

# Change to the meson build directory.
cd "${MESON_BUILD_ROOT}"

# Define various useful path variables.
MESON_RES_PATH="${MESON_SOURCE_ROOT}/resources"
MESON_LC_FR_PATH="${MESON_RES_PATH}/lang/fr/LC_MESSAGES"

APP_PATH="${MESON_BUILD_ROOT}/Conjugateur.app"
CONTENTS_PATH="${APP_PATH}/Contents"
RES_PATH="${CONTENTS_PATH}/Resources"
EXE_PATH="${CONTENTS_PATH}/MacOS"
LC_FR_PATH="${RES_PATH}/fr.lproj"

echo "bundle_mac: bundling ${APP_PATH}"

# Remove the app if it already exists.
rm -rf "${APP_PATH}"

# Create the top directory of the bundle.
mkdir "${APP_PATH}"

# Create all necessary subdirectories of the bundle.
install -d -m 755 "${CONTENTS_PATH}" "${RES_PATH}" "${EXE_PATH}" "${LC_FR_PATH}"

# Install all necessary files to their correct locations inside the bundle.
install -m 644 "${MESON_BUILD_ROOT}/configuration-files/Info.plist" "${CONTENTS_PATH}"
install -m 644 "${MESON_RES_PATH}/conjugateur.icns" "${RES_PATH}"
install -m 644 "${MESON_LC_FR_PATH}/wxstd.mo" "${LC_FR_PATH}"
install -s -m 755 "${MESON_BUILD_ROOT}/conjugateur" "${EXE_PATH}"
