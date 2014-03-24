shared:
	# Works fine
	# the linker will take care of the
	# library dependencies
	gcc -o tifftest tifftest.c -ltiff

static:
	# Hopefully below will go bloody wrong
	# Cause you need to provide every single
	# static libs
	gcc -static -o tifftest tifftest.c -ltiff
