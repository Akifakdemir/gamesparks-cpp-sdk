# change directory to the directory, where this script is in

: ${OUTPUT_DIRECTORY:=../build}
: ${PACKAGING_OUTPUT_DIRECTORY:=../dist}

# in the spirit of perl :)
die()
{
	echo $1 >&2
	exit 1
}

get_absolute_path()
{
	pushd "$1" > /dev/null || die "directory '$1' does not exist"
	pwd -P || exit $?
	popd > /dev/null
}

# test if first arg is below second arg
is_sub_directory()
{
	A=$(get_absolute_path "$1") || exit 1
	B=$(get_absolute_path "$2") || exit 1
	[[ "$A" == "$B"* ]]
}

is_safe_to_delete()
{
	# NOTE: it's also safe to dele, if it does not exist

	# $1 does not exist OR is subdirectory of parent dir OR die
	[ ! -e "$1" ] || is_sub_directory "$1" .. || die "ABORTING: '$1' is above repository root"
}

pushd "$(dirname "$0")"

echo "cleaning $OUTPUT_DIRECTORY"
echo "cleaning $PACKAGING_OUTPUT_DIRECTORY"

# sanity checks, so that we don't accidentally delete stuff we don't want to
is_safe_to_delete "$OUTPUT_DIRECTORY" || die "ABORTING: '$OUTPUT_DIRECTORY' is above repository root"
is_safe_to_delete "$PACKAGING_OUTPUT_DIRECTORY" || die "ABORTING: '$PACKAGING_OUTPUT_DIRECTORY' is above repository root"

rm -rf "$OUTPUT_DIRECTORY"
rm -rf "PACKAGING_OUTPUT_DIRECTORY"
rm -rf "./obj"
rm -rf "./libs"

popd
