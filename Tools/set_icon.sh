SOURCE_ICON_FOLDER=$1
TARGET_BUNDLE_PATH=$2

"$SYSTEM_DEVELOPER_DIR"/Tools/SetFile -a Ci "$TARGET_BUNDLE_PATH"
/bin/cp "$SOURCE_ICON_FOLDER/"Icon* "$TARGET_BUNDLE_PATH"