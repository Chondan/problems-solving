for dir in */; do
	if [ $dir == "util/" ]; then
		continue
	fi

	# Loop through all files inside directory
	for file in $dir*; do
		mv $file ./;
	done

	# Remove directory after relocating files
	if [ "$(ls -A $dir)" ]; then
		continue
	fi
	rmdir $dir;
done
