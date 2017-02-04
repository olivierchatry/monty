#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	hisnumbern(const char *str, int n) {
	int not;
	for (not = 1;*str && not && n; ++str, --n) {
		not = (*str - '0');
		not = (not >= 0) && (not <= 9);
	}
	return not;
}

int	hisnumber(const char *str) {
	int not;
	for (not = 1;*str && not; ++str) {
		not = (*str - '0');
		not = (not >= 0) && (not <= 9);
	}
	return not;
}

void	*hcalloc(int size) {	
	void	*ret;
	int		*set;
	
	size = (size + 3) & ~3;
	ret = malloc(size);
	set = (int*)ret;
	while (size) {
		*set++ = 0;
		size -= 4;
	}
	return ret;
}

int hatoin(const char *str, int n) {
	int 				number = 0;
	const char	*start = str;
	const char	*end;
	int					neg = 0;
	for (;*str && !(*str >= '0' && *str <= '9') && n; ++str, --n) {
		if (*str == '-') {
			neg = !neg;
		}
	}

	start = str;
	
	for (;*str && (*str >= '0' && *str <= '9') && n; ++str, --n);
	end = str;
	while (start != end) {
		number *= 10;
		number += (*start - '0');
		start++;
	}
	return number * (neg ? -1 : 1);
}

int hatoi(const char *str) {
	int 				number = 0;
	int					neg = 0;
	const char	*start = str;
	const char	*end;
	
	for (;*str && !(*str >= '0' && *str <= '9'); ++str) {
		if (*str == '-') {
			neg = !neg;
		}		
	}
	start = str;
	for (;*str && (*str >= '0' && *str <= '9'); ++str);	
	end = str;
	while (start != end) {
		number *= 10;
		number += (*start - '0');
		start++;
	}
	return number * (neg ? -1 : 1);
}

int hstrcmp(const char *a, const char *b) {
	while (*a && (*a == *b)) {
		a++, b++;
	}
	return *a - *b;
}

int hstrncmp(const char *a, const char *b, int n) {
	while (--n && *a && (*a == *b)) {
		a++, b++;
	}
	return (*a - *b);
}

int hstrlen(const char *str) {
	int	count = 0;
	while (str[count]) {
		count++;
	}
	return count;
}

char *hstrdup(const char *str) {
	char	*dup = malloc(hstrlen(str) + 1);
	char	*tmp = dup;
	while (*str) {
		*tmp++ = *str++;
	}
	*tmp++ = 0;
	return dup;
}

char *hstrndup(const char *str, int n) {
	char	*dup = NULL;
	char	*tmp;
	if (n > 0) {
		tmp = dup = hcalloc(n + 1);
		while (n-- && *str) {
			*tmp++ = *str++;
		}
		*tmp++ = 0;
	}
	return dup;
}


int hprintf(const char *format, ...) {
  va_list arg;
  int done;

  va_start (arg, format);
  done = vfprintf (stdout, format, arg);
  va_end (arg);

  return done;
}

const char *hstrchr(const char *str, int c) {
	while(*str) {
		if (*str == c) {
			return str;
		}
		str++;
	}
	return NULL;
}

char *hstrcpy(char *dest, const char *src) {
	char	*temp = dest;
	while (*src) {
		*dest++ = *src++;
	}
	*dest = 0;
	return temp;
}

char *hstrcat(char *dest, const char *src) {
	while (*dest) {
		dest++;
	}
	return hstrcpy(dest, src);
}

char *hstrtok_r(char *str, const char *delim, char **saveptr) {
	char	*token = NULL;
	if (!str) {
		str = *saveptr;
	}
	while (*str && hstrchr(delim, *str)) {
		str++;
	}
	if (*str) {
		token = str;
	}
	while (*str && !hstrchr(delim, *str)) {
		str++;
	}
	*saveptr=str + (*str != 0);
	*str=0;
	return token;
}
