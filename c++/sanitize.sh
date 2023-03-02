file="$1"

if [ -z "$file" ]; then
	echo "Error: Need to enter filename as input."
	exit 1
fi

filename=$(basename -- "$file")
ext="${filename##*.}"
output="${filename%.*}".out

echo "Compiled binary \"$output\""
# Address Sanitizer flags for GCC.
g++ "$file" -o "$output" -ggdb -fsanitize=address -fno-omit-frame-pointer -static-libstdc++ -lrt
# g++ "$file" -ggdb -fsanitize=leak -fno-omit-frame-pointer -static-libstdc++ -static-liblsan -lrt

./"$output"
