#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include <hlib/hlib.h>

char	*util_read_file(const char* path) {
	int		fd = open(path, O_RDONLY);
	char	*content = NULL;
	if (fd != -1) {
		struct stat st;
		fstat(fd, &st);
		content = hcalloc(st.st_size + 1);
		read(fd, content, st.st_size);
		close(fd);
	}
	return content;
}
